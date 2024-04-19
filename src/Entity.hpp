//
// Created by Matthew McCall on 4/18/24.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Vec2.hpp"

using Position = Vec2;
using Velocity = Vec2;

class Entity {
public:
    enum class Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    void update(float deltaTime);
    void moveTo(Vec2 newPos);
    void setDirection(Direction direction);
    void setSpeed(int speed);

    Position getLastPos() const;
    Position getCurrPos() const;

    Direction getCurrDirection() const;
    Direction getLastDirection() const;

private:
    void recalculateVelocity();

    Position lastPos {};
    Position currPos {};
    Direction currDirection {};
    Direction lastDirection {};

    Velocity velocity {};

    int speed {}; // pixels per second
};



#endif //ENTITY_HPP
