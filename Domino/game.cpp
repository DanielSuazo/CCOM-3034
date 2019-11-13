#include "game.h"
#include <bits/stdc++.h>


// Sets the board
// Clears the board of any dominos, creates all dominos and shuffles them randomly
void Table::setBoard() {
  clear();
  std::srand(std::time(0));
  for(int i = 0; i < 7; i++) {
    for (int j = i; j < 7; j++) {
      push_front(Tile(i,j));
    }
  }
  std::random_shuffle(begin(), end());
}

// Returns a list of Tiles that can be assigned to a player
std::list<Tile> Table::dealTiles() {
  std::list<Tile> tmp;
  for (int i = 0; i < 7; i++) {
    tmp.push_back(front());
    pop_front();
  }
  return tmp;
}

// Allows a list of tiles to be assigned to a player for the dealTiles function
Player Player::operator=(std::list<Tile> list) {
  clear();
  for (auto e : list) {
    push_back(e);
  }
  return *this;
}

// Player goes through his turn. Plays a domino to the board if possible and returns true.
// Returns false if no tile could be played.
bool Player::play(Table &board) {
  bool final = false;
  for (auto &e : *this) {
    if (e.r != -1) {
      if (e.r == board.right()) {
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
  }
  return final;
}

// Display the board
void Table::display(std::ostream &out) const {
  out << "===================================================\n";
  out << "board: ";
  for (auto e : *this) {
    e.display();
  }
  out << std::endl;
}

// Display the player's hand
void Player::display(std::ostream &out) const {
  for (auto e : *this) {
    e.display();
  }
  out << std::endl;
}

// Overloading the basic empty function to return false if all dominos in hand are -1
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