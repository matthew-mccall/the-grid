//
// Created by Matthew McCall on 4/19/24.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity {
public:
  bool hasCollided() const;
  void setColor(int color);
  void drawTrail() const;

private:
  int color {};
};



#endif //PLAYER_HPP
