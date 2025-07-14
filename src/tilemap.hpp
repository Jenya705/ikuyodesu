#ifndef TILEMAP_HPP_INCLUDED
#define TILEMAP_HPP_INCLUDED

#include <cstdint>
#include <unordered_map>
#include "alg/vec.hpp"

template<typename T, std::size_t C, std::size_t R>
class TilemapLayerChunk {
public:
    std::array<T, C * R> data;

    T& tile_at(Vec2<std::int32_t> tile) {
        return data[tile.y * C + tile.x];
    }
};

template<typename T>
class TilemapLayer {
public:
    constexpr static std::size_t CHUNK_C = 16;
    constexpr static std::size_t CHUNK_R = 16;

    std::unordered_map<Vec2<std::int32_t>, TilemapLayerChunk<T, CHUNK_C, CHUNK_R>> chunks;

    TilemapLayerChunk<T, CHUNK_C, CHUNK_R>* chunk_at(Vec2<std::int32_t> chunk) {
        auto i = chunks.find(chunk);
        return i == chunks.end() ? nullptr : i->second;
    }

    T* tile_at(Vec2<std::int32_t> tile) {
        auto chunk = chunk_at(tile / 16);
        return chunk == nullptr ? nullptr : chunk.tile_at(((tile % 16) + vec(CHUNK_R, CHUNK_C)) % 16);
    }
};

#endif
