#ifndef KEY_TYPE_H
#define KEY_TYPE_H

#include <iostream>
#include <limits>

enum class TYPE : uint8_t {
    RED = 0,
    GREEN,
    BLUE
};

class KeyType {
public:
    KeyType(int key) : m_key(key) {}

    bool operator<(const KeyType& other) const {
        return m_key < other.m_key;
    }

    bool operator==(const KeyType& other) const {
        return m_key == other.m_key;
    }

    friend std::ostream& operator<<(std::ostream& os, const KeyType& key) {
        os << key.m_key;
        return os;
    }

private:
    int m_key;
};

#endif  // KEY_TYPE_H