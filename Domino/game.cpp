#include "game.h"
#include <bits/stdc++.h>

Table::Table() {

}

void Table::setBoard() {
  std::srand(std::time(0));
  for(int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      push_front(Tile(i,j));
    }
  }
  std::random_shuffle(begin(), end());
}

std::list<Tile> Table::dealTiles() {
  std::list<Tile> tmp;
  for (int i = 0; i < 7; i++) {
    tmp.push_back(front());
    pop_front();
  }
  return tmp;
}

Player::Player() {

}

Player Player::operator=(std::list<Tile> list) {
  for (auto e : list) {
    push_back(e);
  }
  return *this;
}

bool Player::play(Table &board) {
  bool final = false;
  for (auto &e : *this) {
    
    if (e.r == -1) {

    } else if (e.r == board.right()) {
      e.swap();
      board.playRight(e);
      e.r = -1;
      final = true;
      break;
    } else if (e.l == board.right()) {
      board.playRight(e);
      e.r = -1;
      final = true;
      break;
    } else if (e.r == board.left()) {
      board.playLeft(e);
      e.r = -1;
      final = true;
      break;
    } else if (e.l == board.left()) {
      e.swap();
      board.playLeft(e);
      e.r = -1;
      final = true;
      break;
    } else {
      final = false;
    }
  }
  return final;
}

void Table::display(std::ostream &out) const {
  out << "===================================================\n";
  out << "board: ";
  for (auto e : *this) {
    e.display();
  }
  out << std::endl;
}

void Player::display(std::ostream &out) const {
  for (auto e : *this) {
    e.display();
  }
  out << std::endl;
}

bool Player::empty() const {
  bool final = 1;
  for (auto e : *this) {
    if (e.r != -1) final = 0;
  }
  return final;
}

std::ostream &operator<<(std::ostream &out, const Table &t) {
  t.display(out);
  return out;
}

std::ostream &operator<<(std::ostream &out, const Player &p) {
  p.display(out);
  return out;
}