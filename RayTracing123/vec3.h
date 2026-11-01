#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>
constexpr double M_PI = 3.141592655358979324;

class vec3 {

public:
	vec3() = default;
	vec3(double e1, double e2, double e3) { e[0] = e1; e[1] = e2; e[2] = e3; }

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }
	double r() const { return e[0]; }
	double g() const { return e[1]; }
	double b() const { return e[2]; }

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	inline double operator[](int i) const { return e[i]; }
	inline double& operator[](int i) { return e[i]; }

	inline vec3& operator+=(const vec3& v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}
	inline vec3& operator-=(const vec3& v) {
		e[0] -= v.e[0];
		e[1] -= v.e[1];
		e[2] -= v.e[2];
		return *this;
	}
	inline vec3& operator*=(const vec3& v) {
		e[0] *= v.e[0];
		e[1] *= v.e[1];
		e[2] *= v.e[2];
		return *this;
	}
	inline vec3& operator/=(const vec3& v) {
		e[0] /= v.e[0];
		e[1] /= v.e[1];
		e[2] /= v.e[2];
		return *this;
	}
	inline vec3& operator*=(const double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}
	inline vec3& operator/=(const double t) {
		e[0] /= t;
		e[1] /= t;
		e[2] /= t;
		return *this;
	}

	inline double length() const { return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline double squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }
	//inline void make_unit_vec();

	double e[3];
};

inline vec3 operator+(const vec3& v1, const vec3& v2) {
	vec3 result = v1;
	result += v2;
	return result;
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
	vec3 result = v1;
	result -= v2;
	return result;
}

inline vec3 operator*(const vec3& v1, const vec3& v2) {
	vec3 result = v1;
	result *= v2;
	return result;
}

inline vec3 operator/(const vec3& v1, const vec3& v2) {
	vec3 result = v1;
	result /= v2;
	return result;
}

inline vec3 operator*(const vec3& v1, double t) {
	vec3 result = v1;
	result *= t;
	return result;
}

inline vec3 operator*(double t, const vec3& v1) {
	vec3 result = v1;
	result *= t;
	return result;
}

inline vec3 operator/(const vec3& v1, double t) {
	vec3 result = v1;
	result /= t;
	return result;
}

inline double dot(const vec3& v1, const vec3& v2) {
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
	return vec3(v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
		v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2],
		v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}
