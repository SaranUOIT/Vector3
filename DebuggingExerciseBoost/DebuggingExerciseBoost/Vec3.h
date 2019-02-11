#pragma once

class Vec3
{
public:
	Vec3(float _x, float _y, float _z);
	~Vec3();

	float Dot(Vec3 Vec1, Vec3 Vec2);
	Vec3 Cross(Vec3 Vec1, Vec3 Vec2);
	Vec3 Add(Vec3 Vec1, Vec3 Vec2);
	Vec3 Subtract(Vec3 Vec1, Vec3 Vec2);
	Vec3 Multiply(Vec3 Vec1, float scalar);
	Vec3 Projection(Vec3 Vec1, Vec3 Vec2);

	float x;
	float y;
	float z;

};