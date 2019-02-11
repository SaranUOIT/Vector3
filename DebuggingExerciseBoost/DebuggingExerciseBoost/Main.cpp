#include "Vec3.h"
#include <iostream>
#include <boost/contract.hpp>

bool isCollidingSphere(Vec3 &c1, float r1, Vec3 &c2, float r2)
{
	int rSquared = r1 + r2;
	rSquared *= rSquared;
	Vec3 delta = c1.Subtract(c1, c2);
	float distanceSquared = delta.Dot(delta, delta);

	boost::contract::check c = boost::contract::function()
		.precondition([&] {
		BOOST_CONTRACT_ASSERT(r1 != 0);
		BOOST_CONTRACT_ASSERT(r2 != 0);
		BOOST_CONTRACT_ASSERT(r1 > 0);
		BOOST_CONTRACT_ASSERT(r2 > 0);
	})
		;

	return distanceSquared < rSquared;
}

int main()
{
	Vec3 temp(1, 2, 3);
	Vec3 temp2(1, 2, 3);

	std::cout << isCollidingSphere(temp, -2, temp2, 2) << std::endl;

	return 0;
}