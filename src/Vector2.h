#pragma once
#include <cmath>

class Vector2
{
public:
    float x = 0;
    float y = 0;

public:
    Vector2() = default;
    ~Vector2() = default;

    Vector2(float x, float y): x(x), y(y)
    {
    }

    Vector2 operator+(const Vector2& rhs) const
    {
        return Vector2(x + rhs.x, y + rhs.y);
    }

    void operator+=(const Vector2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
    }

    void operator-=(const Vector2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
    }

    Vector2 operator-(const Vector2& rhs) const
    {
        return Vector2(x - rhs.x, y - rhs.y);
    }


    float operator*(const Vector2& rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }

    Vector2 operator*(float rhs) const
    {
        return Vector2(x * rhs, y * rhs);
    }

    void operator*=(float rhs)
    {
        x *= rhs;
        y *= rhs;
    }

    float length()
    {
        return sqrt(x * x + y * y);
    }

    Vector2 normalize()
    {
        float len = length();
        if (len == 0)
        {
            return Vector2(0, 0);
        }

        return Vector2(x / len, y / len);
    }
};
