//
// Created by Matthew McCall on 4/18/24.
//

#include <cmath>

#include "Entity.hpp"

void Entity::update(const float deltaTime) {
  // must have a distance greater than 1 so that line can be rendered
  if (currDirection == lastDirection) {
    if (std::fabs(lastPos.x - currPos.x) >= 1) {
      lastPos.x = currPos.x;
    }

    if (std::fabs(lastPos.y - currPos.y) >= 1) {
      lastPos.y = currPos.y;
    }
  } else {
    lastPos = currPos;
  }

  lastDirection = currDirection;
  currPos += deltaTime * velocity;
}

void Entity::moveTo(const Vec2 newPos) {
  currPos = newPos;
}

void Entity::setDirection(const Direction direction) {
  currDirection = direction;
  recalculateVelocity();
}

void Entity::setSpeed(const int speed) {
  this->speed = speed;
  recalculateVelocity();
}

Position Entity::getLastPos() const {
  return lastPos;
}

Position Entity::getCurrPos() const {
  return currPos;
}

Entity::Direction Entity::getCurrDirection() const {
  return currDirection;
}

Entity::Direction Entity::getLastDirection() const {
  return lastDirection;
}


void Entity::recalculateVelocity() {
  switch (currDirection) {
  case Direction::UP:
    velocity = Vec2::UP;
    break;
  case Direction::RIGHT:
    velocity = Vec2::RIGHT;
    break;
  case Direction::DOWN:
    velocity = Vec2::DOWN;
    break;
  case Direction::LEFT:
    velocity = Vec2::LEFT;
    break;
  default:
    return;
  }

  velocity *= speed;
}
