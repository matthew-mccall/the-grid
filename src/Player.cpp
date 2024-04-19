//
// Created by Matthew McCall on 4/19/24.
//

#include <cmath>

#include <graphx.h>

#include "Grid.hpp"
#include "Player.hpp"

void Player::setColor(const int color) {
  this->color = color;
}

void Player::drawTrail() const {
  auto [x, y] = getCurrPos();
  auto [lastX, lastY] = getLastPos();

  gfx_SetColor(color);

  switch (getCurrDirection()) {
  case Direction::UP:
    gfx_VertLine(x, y, std::round(lastY - y));
    break;
  case Direction::RIGHT:
    gfx_HorizLine(lastX, y, std::ceil(x - lastX));
    break;
  case Direction::DOWN:
    gfx_VertLine(x, lastY, std::ceil(y - lastY));
    break;
  case Direction::LEFT:
    gfx_HorizLine(x, y, std::round(lastX - x));
    break;
  }
}
bool Player::hasCollided() const {
  auto [x, y] = getCurrPos();

  switch (getCurrDirection()) {
  case Direction::UP:
    y -= 1;
    break;
  case Direction::RIGHT:
    x += 1;
    break;
  case Direction::DOWN:
    y += 1;
    break;
  case Direction::LEFT:
    x -= 1;
    break;
  }

  if (x < 0 || x > GFX_LCD_WIDTH) {
    return true;
  }

  if (y < 0 || y > GFX_LCD_HEIGHT) {
    return true;
  }

  return gfx_GetPixel(x, y) != Grid::COLOR;
  // return false;
}

