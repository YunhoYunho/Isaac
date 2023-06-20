#pragma once
#include <corecrt_math_defines.h>

//========================================
//##				백터					##
//========================================

struct Vector
{
	float x;
	float y;

	Vector()
	{
		x = 0;
		y = 0;
	}

	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector operator+(const Vector& other)
	{
		return Vector(x + other.x, y + other.y);
	}

	Vector& operator+=(const Vector& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector operator-(const Vector& other)
	{
		return Vector(x - other.x, y - other.y);
	}

	Vector& operator-=(const Vector& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	template <typename T>
	Vector operator*(T num)
	{
		return Vector(x * num, y * num);
	}

	template <typename T>
	Vector& operator*=(T num)
	{
		x *= num;
		y *= num;
		return *this;
	}

	template <typename T>
	Vector operator/(T num)
	{
		assert(0 != num);
		return Vector(x / num, y / num);
	}

	template <typename T>
	Vector& operator/=(T num)
	{
		assert(0 != num);
		x /= num;
		y /= num;
		return *this;
	}

	float Magnitude()
	{
		return sqrtf(x * x + y * y);
	}

	// 거리연산(피타고라스)의 루트연산이 굉장히 많은 시간을 요구하기 때문에
	// 거리의 차이만 비교하고 싶을 경우 루트연산을 하지 않은 길이의 제곱끼리 비교
	float SqrMagnitude()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return Magnitude();
	}

	// 정규화(표준화) : 길이가 1인 백터(단위백터)로 변환
	// 방향성백터와 같이 길이가 1인 백터가 필요할 경우 변환
	void Normalize()
	{
		if (SqrMagnitude() == 0)
		{
			x = 0;
			y = 0;
		}
		else
		{
			float length = Length();
			x = x / length;
			y = y / length;
		}
	}

	// 단위백터를 반환
	Vector Normalized()
	{
		if (SqrMagnitude() == 0)
		{
			return Vector(0, 0);
		}
		else
		{
			float length = Length();
			return Vector(x / length, y / length);
		}
	}

	static float CalculateAngle(Vector pos1, Vector pos2) 
	{
		Vector dirToPos1 = pos1.Normalized();
		Vector dirToPos2 = pos2.Normalized();

		float dot = Vector::Dot(dirToPos1, dirToPos2);

		float theta = acos(dot);
		float angle = theta * 180.0f / 3.141592f;

		return angle;
	}

	static float Dot(Vector vec1, Vector vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y;
	}

	static Vector AngleToDir(float angle)
	{
		float rad = angle * 3.141592f / 180.0f;
		return Vector(cos(rad), sin(rad));
	}

	static float DirToAngle(Vector vec)
	{
		if (vec.y >= 0)
			return CalculateAngle(vec, Vector(1, 0));
		else
			return -1 * CalculateAngle(vec, Vector(1, 0));
	}
};

//========================================
//##				색상					##
//========================================

struct Color
{
	Color()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 1;
	}

	Color(BYTE r, BYTE g, BYTE b, FLOAT a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	BYTE r, g, b;
	FLOAT a;
};