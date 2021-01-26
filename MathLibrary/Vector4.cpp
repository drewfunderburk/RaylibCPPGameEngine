#include "pch.h"
#include "Vector4.h"
#include <cmath>

MathLibrary::Vector4::Vector4()
{
    x = 0; y = 0; z = 0; w = 0;
}

MathLibrary::Vector4::Vector4(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

float MathLibrary::Vector4::getMagnitude()
{
    return (float)sqrt(x * x + y * y + z * z + w * w);
}

MathLibrary::Vector4 MathLibrary::Vector4::getNormalized()
{
    return normalize(*this);
}

MathLibrary::Vector4 MathLibrary::Vector4::normalize(Vector4 vector)
{
    if (vector.getMagnitude() == 0)
        return Vector4();

    return vector / vector.getMagnitude();
}

float MathLibrary::Vector4::dotProduct(Vector4 lhs, Vector4 rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

MathLibrary::Vector4 MathLibrary::Vector4::crossProduct(Vector4 lhs, Vector4 rhs)
{
    return Vector4(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x, 0);
}

MathLibrary::Vector4 MathLibrary::Vector4::lerp(Vector4 start, Vector4 end, float time)
{
    // If the timescale is 0, return the start vector
    if (time == 0)
        return start;
    // If the timescale is set to 1, meaning we travel 100% of the way, return the end vector
    else if (time == 1)
        return end;
    // If the distance between the start and end vector is miniscule, return the end vector
    else if ((end - start).getMagnitude() < 0.1)
        return end;

    return start + (end - start) * time;
}

float MathLibrary::Vector4::distance(Vector4 start, Vector4 end)
{
    return sqrt(pow(end.x - start.y, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2) + pow(end.w - start.w, 2));
}

MathLibrary::Vector4 MathLibrary::Vector4::operator +(Vector4 rhs)
{
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

MathLibrary::Vector4 MathLibrary::Vector4::operator-(Vector4 rhs)
{
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

MathLibrary::Vector4 MathLibrary::Vector4::operator*(float scalar)
{
    return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

MathLibrary::Vector4 MathLibrary::Vector4::operator/(float scalar)
{
    return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

bool MathLibrary::Vector4::operator==(Vector4 rhs)
{
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

MathLibrary::Vector4 operator*(float scalar, MathLibrary::Vector4 rhs)
{
    return MathLibrary::Vector4(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z, scalar * rhs.w);
}

MathLibrary::Vector4 MathLibrary::operator*(float scalar, Vector4 lhs)
{
    return Vector4();
}
