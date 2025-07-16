#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED

#include <cstdint>
#include <functional>
#include <unordered_map>
#include "alg/vec.hpp"
#include "scene/base.hpp"
#include <type_traits>

template<typename T, std::size_t C, std::size_t R>
class TilemapLayerChunk {
public:
    std::array<T, C * R> data;

    T& tile_at(Vec2<std::int32_t> tile) {
        return data[tile.y * C + tile.x];
    }
};

template<typename T>
class NoFunction {
public:
    void operator()(Vec2<std::int32_t> v1, T& v2) {};
};

template<
    typename T,
    typename RenderF = NoFunction<T>,
    typename UpdateF = NoFunction<T>
>
class TilemapLayer: public Base {
public:
    constexpr static std::size_t CHUNK_C = 16;
    constexpr static std::size_t CHUNK_R = 16;

    TilemapLayer(): render_function(RenderF()), update_function(UpdateF()) {}
    TilemapLayer(RenderF render_function, UpdateF update_function): render_function(render_function), update_function(update_function) {}

    std::unordered_map<Vec2<std::int32_t>, TilemapLayerChunk<T, CHUNK_C, CHUNK_R>> chunks;
    RenderF render_function; UpdateF update_function;

    TilemapLayerChunk<T, CHUNK_C, CHUNK_R>* chunk_at(Vec2<std::int32_t> chunk) {
        auto i = chunks.find(chunk);
        return i == chunks.end() ? nullptr : i->second;
    }

    T* tile_at(Vec2<std::int32_t> tile) {
        auto chunk = chunk_at(tile / 16);
        return chunk == nullptr ?
            nullptr :
            chunk.tile_at(((tile % 16) + vec((std::int32_t)CHUNK_R, (std::int32_t)CHUNK_C)) % 16);
    }

    void for_each(std::function<void(Vec2<std::int32_t>, T&)> func) {
        for (auto& p: chunks) {
            auto v = p.first * 16;
            for (auto y = 0; y < CHUNK_C; y++) {
                for (auto x = 0; x < CHUNK_R; x++) {
                    auto tv = v + vec(x,y);
                    func(tv, p.second.tile_at(vec(x,y)));
                }
            }
       }
    }

    void update() override {
        if (!std::is_same<UpdateF, NoFunction<T>>::value)
            for_each(update_function);

    }

    void render() override {
        if (!std::is_same<RenderF, NoFunction<T>>::value)
            for_each(render_function);
    }
};

#endif
