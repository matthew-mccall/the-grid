//
// Created by Matthew McCall on 4/19/24.
//

#ifndef GRID_HPP
#define GRID_HPP

class Player;

class Grid {
public:
  Grid(Player& player1, Player& player2);

  void update(float deltaTime) const;
  void draw() const;

  bool gameOver() const;

  static const int COLOR;

private:
  Player& player1;
  Player& player2;
};



#endif //GRID_HPP
