#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <unordered_map>
#include <stdexcept>
#include <iterator>  


template<typename K, typename V>
K getKeyWithMaxValue(const std::unordered_map<K, V>& map) {
    
    if (map.empty()) {
        throw std::runtime_error("Cannot get max key from an empty map");
    }

    auto maxIt = map.begin();
    for (auto it = std::next(map.begin()); it != map.end(); ++it) {
        if (it->second > maxIt->second) {
            maxIt = it;
        }
    }
    return maxIt->first;
}

#endif
