#pragma once

#include "vec3.h"

class ray
{
public:
	ray() = default;
	ray(const vec3& a,
		const vec3& b)
		: A(a)
		, B(b){}
	vec3 origin() const { return A; }
	vec3 direction() const { return B; }
	vec3 point_at_parameter (double t) const
	{ return A + B * t; }	//return a point with parm. t

	vec3 A; //origin
	vec3 B; //direction
};
