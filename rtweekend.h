#pragma once
#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <functional>
#include <random>

// usings
using std::shared_ptr;
using std::make_shared;

// Constants
// 返回特殊值“正无穷大”，由浮点类型表示。
// infinity() 返回给定浮点类型（公共静态成员函数）的正无穷大值
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
// 角度转弧度
inline double degrees_to_radians(double degrees) {
	return degrees * pi / 180.0;
}

inline double ffmin(double a, double b) { return a <= b ? a : b; }
inline double ffmax(double a, double b) { return a >= b ? a : b; }

inline double random_double() {
	// 返回[0,1)的随机数
	return rand() / (RAND_MAX + 1.0);
}

inline double random_double2() {
	// uniform_real_distribution 随机生成随机浮点数，均匀分配到[0,1)
	static std::uniform_real_distribution<double>distribution(0.0, 1.0);
	//C++的 rand() 函数产生的随机数范围值是 0~32767 ，如果想产生很大的随机数(几亿，甚至几十亿)，就要用到 mt19937 。
	static std::mt19937 generator;
	static std::function<double()>rand_generator =
		std::bind(distribution, generator);
	return rand_generator();
}

inline double random_double(double min, double max) {
	// 返回[min,max)之间的随机数
	return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max) {
	if (x < min) return min;
	if (x > max)return max;
	return x;
}

inline int random_int(int min, int max) {
	// Returns a random integer in [min,max].
	return static_cast<int>(random_double(min, max + 1));
}


// Common Headers

#include "ray.h"
#include "vec3.h"
#include "hittable.h"

#endif // !TRWEEKEND_H
