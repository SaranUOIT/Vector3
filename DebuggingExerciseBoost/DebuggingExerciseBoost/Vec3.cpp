#include "Vec3.h"
#include <limits>
#include <boost/contract.hpp>


Vec3::Vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;

	boost::contract::check c = boost::contract::function()
		.precondition([&] {
		BOOST_CONTRACT_ASSERT(_x < std::numeric_limits<float>::max());
		BOOST_CONTRACT_ASSERT(_y < std::numeric_limits<float>::max());
		BOOST_CONTRACT_ASSERT(_z < std::numeric_limits<float>::max());
		BOOST_CONTRACT_ASSERT(_x > std::numeric_limits<float>::lowest());
		BOOST_CONTRACT_ASSERT(_y > std::numeric_limits<float>::lowest());
		BOOST_CONTRACT_ASSERT(_z > std::numeric_limits<float>::lowest());

	})
		.postcondition([&] {
		BOOST_CONTRACT_ASSERT(x == _x);
		BOOST_CONTRACT_ASSERT(y == _y);
		BOOST_CONTRACT_ASSERT(z == _z);
	})
		;
}

Vec3::~Vec3()
{
}

float Vec3::Dot(Vec3 Vec1, Vec3 Vec2)
{
	return Vec1.x * Vec2.x + Vec1.y * Vec2.y + Vec1.z * Vec2.z;
}

Vec3 Vec3::Cross(Vec3 Vec1, Vec3 Vec2)
{
	float _x = Vec1.y * Vec2.z - Vec1.z * Vec2.y;
	float _y = Vec1.x * Vec2.z - Vec1.z * Vec2.x;
	float _z = Vec1.x * Vec2.x - Vec1.y * Vec2.x;

	return Vec3(_x, _y, _z);
}

Vec3 Vec3::Add(Vec3 Vec1, Vec3 Vec2)
{
	float _x = Vec1.x + Vec2.x;
	float _y = Vec1.y + Vec2.y;
	float _z = Vec1.z + Vec2.z;

	return Vec3(_x, _y, _z);
}

Vec3 Vec3::Subtract(Vec3 Vec1, Vec3 Vec2)
{
	float _x = Vec1.x - Vec2.x;
	float _y = Vec1.y - Vec2.y;
	float _z = Vec1.z - Vec2.z;

	return Vec3(_x, _y, _z);
}

Vec3 Vec3::Multiply(Vec3 Vec1, float scalar)
{
	float _x = Vec1.x * scalar;
	float _y = Vec1.y * scalar;
	float _z = Vec1.z * scalar;

	return Vec3(_x, _y, _z);
}

Vec3 Vec3::Projection(Vec3 Vec1, Vec3 Vec2)
{
	return Multiply(Vec1, Dot(Vec1, Vec2) / Dot(Vec2, Vec2));
}
