#pragma once
#include "List.hpp"
#include <functional>

template <typename T>
class CircularList : public List<T> {
public:
    using iterator = typename List<T>::iterator;
    void traverse_from(iterator start, std::function<void(T&)> doIt) {
        if (this->empty()) return;

        iterator current = start;
        doIt(*current);
        ++current;

        if (current == this->end())
            current = this->begin();

        while (current != start) {
            doIt(*current);
            ++current;

            if (current == this->end())
                current = this->begin();
        }
    }
};
