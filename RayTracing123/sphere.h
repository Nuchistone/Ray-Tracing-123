#pragma once

#include "hitable.h"
#include "ray.h"
#include "material.h"

class sphere : public hitable
{
public:
	sphere() = default;
	sphere(vec3 cen, double r, material* mat_ptr)
		: center(cen)
		, radius(r)
		, mat(mat_ptr)
	{
	}
	virtual bool hit(
		const ray& r,
		double tmin, 
		double tmax,
		hit_record& rec
	) const override;

	vec3 center;
	double radius;
	material* mat;
};
