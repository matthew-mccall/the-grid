//
// Created by Matthew McCall on 4/19/24.
//

#include "Grid.hpp"

#include <Player.hpp>

int const Grid::COLOR = 0x0;

Grid::Grid(Player &player1, Player &player2)
    : player1(player1), player2(player2) {}

void Grid::update(const float deltaTime) const {
  player1.update(deltaTime);
  player2.update(deltaTime);
}
void Grid::draw() const {
  player1.drawTrail();
  player2.drawTrail();
}

bool Grid::gameOver() const {
  return player1.hasCollided() || player2.hasCollided();
}
