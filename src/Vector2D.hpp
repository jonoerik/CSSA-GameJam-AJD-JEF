#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cstddef>
#include <vector>

template<class T>
class Vector2D {
public:
    Vector2D(size_t width, size_t height) :
	width_(width),
	height_(height)
    {
	data_.resize(width * height);
    }

    T& operator()(size_t x, size_t y) {
	return data_.at(width_ * y + x);
    }

    const T& operator()(size_t x, size_t y) const {
	return data_.at(width_ * y + x);
    }

    std::vector<T>& Data() {
	return data_;
    }

    size_t Width() const {
	return width_;
    }

    size_t Height() const {
	return height_;
    }

private:
    std::vector<T> data_;
    size_t width_;
    size_t height_;
	
};

#endif //VECTOR2D_H
