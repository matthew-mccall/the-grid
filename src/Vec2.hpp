//
// Created by Matthew McCall on 4/18/24.
//

#ifndef VEC2_HPP
#define VEC2_HPP

struct Vec2
{
  Vec2() = default;
  Vec2(float x, float y);

  float x = 0, y = 0;

  Vec2& operator+=(Vec2 other);
  friend Vec2 operator+(Vec2 a, Vec2 b);

  Vec2& operator*=(float a);
  friend Vec2 operator*(float a, Vec2 x);

  bool operator==(Vec2 other) const;

  static const Vec2 UP;
  static const Vec2 RIGHT;
  static const Vec2 DOWN;
  static const Vec2 LEFT;
  static const Vec2 ZERO;
};


#endif //VEC2_HPP
