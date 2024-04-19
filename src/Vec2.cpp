//
// Created by Matthew McCall on 4/18/24.
//

#include "Vec2.hpp"

Vec2 const Vec2::UP = Vec2 { 0, -1 };
Vec2 const Vec2::RIGHT { 1, 0 };
Vec2 const Vec2::DOWN { 0, 1 };
Vec2 const Vec2::LEFT { -1, 0 };
Vec2 const Vec2::ZERO {};

Vec2::Vec2(float x, float y) : x(x), y(y) {}

Vec2 & Vec2::operator+=(const Vec2 other)
{
  x += other.x;
  y += other.y;

  return *this;
}

Vec2 operator+(Vec2 a, const Vec2 b)
{
  a += b;
  return a;
}

Vec2& Vec2::operator*=(const float a)
{
  x *= a;
  y *= a;

  return *this;
}

Vec2 operator*(const float a, Vec2 x)
{
  x *= a;
  return x;
}

bool Vec2::operator==(const Vec2 other) const
{
  return (x == other.x) && (y == other.y);
}