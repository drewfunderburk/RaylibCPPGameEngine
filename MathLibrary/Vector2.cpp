#include "pch.h"
#include "Vector2.h"
#include <cmath>

MathLibrary::Vector2::Vector2()
{
    x = 0;
    y = 0;
}

MathLibrary::Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float MathLibrary::Vector2::getMagnitude()
{
    return sqrt(x * x + y * y);
}

MathLibrary::Vector2 MathLibrary::Vector2::getNormalized()
{
    return normalize(*this);
}

MathLibrary::Vector2 MathLibrary::Vector2::normalize(Vector2 vector)
{
    if (vector.getMagnitude() == 0)
        return Vector2();

    return vector / vector.getMagnitude();
}

float MathLibrary::Vector2::dotProduct(Vector2 lhs, Vector2 rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

float MathLibrary::Vector2::angle(Vector2 lhs, Vector2 rhs)
{
    lhs = normalize(lhs);
    rhs = normalize(rhs);

    //Use the dotproduct to find the angle the actor needs to rotate
    float dotProd = dotProduct(lhs, rhs);

    if (abs(dotProd) > 1)
        return 0;

    float angle = (float)acos(dotProd);

    //Find a perpindicular vector to the direction
    Vector2 perp = Vector2(rhs.y, -rhs.x);

    //Find the dot product of the perpindicular vector and the current forward
    float perpDot = dotProduct(perp, lhs);

    //If the result isn't 0, use it to change the sign of the angle to be either positive or negative
    if (perpDot != 0)
        angle *= perpDot / abs(perpDot);

    return angle;
}

MathLibrary::Vector2 MathLibrary::Vector2::lerp(Vector2 start, Vector2 end, float time)
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

float MathLibrary::Vector2::distance(Vector2 start, Vector2 end)
{
    return sqrt(pow(end.x - start.y, 2) + pow(end.y - start.y, 2));
}

MathLibrary::Vector2 MathLibrary::Vector2::operator +(Vector2 rhs)
{
    return Vector2(x + rhs.x, y + rhs.y);
}

MathLibrary::Vector2 MathLibrary::Vector2::operator -(Vector2 rhs)
{
    return Vector2(x - rhs.x, y - rhs.y);
}

MathLibrary::Vector2 MathLibrary::Vector2::operator *(float scalar)
{
    return Vector2(x * scalar, y * scalar);
}

MathLibrary::Vector2 operator *(float scalar, MathLibrary::Vector2 rhs)
{
    return MathLibrary::Vector2(scalar * rhs.x, scalar * rhs.y);
}

MathLibrary::Vector2 MathLibrary::Vector2::operator / (float scalar)
{
    return Vector2(x / scalar, y / scalar);
}

bool MathLibrary::Vector2::operator==(Vector2 rhs)
{
    return x == rhs.x && y == rhs.y;
}
