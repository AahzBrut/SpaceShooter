#pragma once

#include <cstdio>
#include <map>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <box2d/types.h>

template<> struct std::hash<b2BodyId> {
    size_t operator()(const b2BodyId& id) const noexcept {
        return hash<int>()(id.index1) ^ hash<unsigned>()(id.revision) ^ hash<unsigned>()(id.world0);
    }
};

template<> struct std::equal_to<b2BodyId> {
    bool operator() (const b2BodyId& firstId, const b2BodyId& secondId) const {
        return firstId.index1 == secondId.index1 && firstId.revision == secondId.revision && firstId.world0 == secondId.world0;
    }
};

namespace SpaceShooter {
    template<typename K, typename V>
    using Pair = std::pair<K, V>;

    template<typename T>
    using Unique = std::unique_ptr<T>;

    template<typename T>
    using Shared = std::shared_ptr<T>;

    template<typename T>
    using Weak = std::weak_ptr<T>;

    template<typename T>
    using List = std::vector<T>;

    template<typename Key, typename Value, typename Compare = std::less<Key>>
    using Map = std::map<Key, Value, Compare>;

    template<typename Key, typename Value, typename Hasher = std::hash<Key>>
    using Dictionary = std::unordered_map<Key, Value, Hasher>;

    template<typename T>
    using Set = std::unordered_set<T>;

#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

    enum class CollisionLayers {
        None = 0,
        Player = 1,
        PlayerBullet = 2,
        Enemy = 4,
        EnemyBullet = 8,
        Reward = 16,
    };

    inline CollisionLayers operator|(CollisionLayers lhs, CollisionLayers rhs) {
        return static_cast<CollisionLayers>(static_cast<int>(lhs) | static_cast<int>(rhs));
    }

    const Map<int, std::string> CollisionLayersNames = {
        {0, "None"},
        {1, "Player"},
        {2, "PlayerBullet"},
        {4, "Enemy"},
        {8, "EnemyBullet"},
        {16, "Reward"},
    };
}
