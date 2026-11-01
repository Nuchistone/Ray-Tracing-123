#pragma once

#include "vec3.h"
#include "ray.h"

class material;

struct hit_record
{
	double t;		// parameter in the equation
	vec3 p;			// point coresponding to t
	vec3 normal;	// nomal vector at p
	material* mat_ptr;
};

class hitable
{
public:
	virtual bool hit(
		const ray& r,
		double t_min,
		double t_max,
		hit_record& rec
	) const = 0;
};