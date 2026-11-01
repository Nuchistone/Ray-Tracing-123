#pragma once

#include "hitable.h"

class hitable_list : public hitable
{
public:
	hitable_list() {}
	hitable_list(hitable **l, int n) //vector<shared_ptr<hitable>> l
		: list(l)			// hitable is a abstract base class, so we use hitable* to convert it to a derived class
		, list_size(n) { }
	virtual bool hit(
		const ray& r,
		double tmin,
		double tmax,
		hit_record& rec
	) const override;

	hitable** list;	// abstract base class, unable to be itemized
	int list_size;
};
