#include "game.h"

int main() {
  char n;
  Table table;
  table.setBoard();
  Player p1, p2, p3, p4;
  p1 = table.dealTiles();
  p2 = table.dealTiles();
  p3 = table.dealTiles();
  p4 = table.dealTiles();

  std::cout << table;
  bool stuck = true;
  while(stuck){
    stuck = false;

    stuck = p1.play(table) || stuck;
    if (stuck) {
      std::cout << "Player 1's Turn!" << std::endl;
      std::cout << table;
      std::cout << "=====> ";
      std::cout << "player 1: " << p1;
      std::cout << "player 2: " << p2;
      std::cout << "player 3: " << p3;
      std::cout << "player 4: " << p4;
    }
    if (p1.empty()) {
      std::cout << "Player 1 wins!" << std::endl;
      break;
    }


    stuck = p2.play(table) || stuck;
    if (stuck) {
      std::cout << "Player 2's Turn!" << std::endl;
      std::cout << table;
      std::cout << "player 1: " << p1;
      std::cout << "=====> player 2: " << p2;
      std::cout << "player 3: " << p3;
      std::cout << "player 4: " << p4;
    }
    if (p2.empty()) {
      std::cout << "Player 2 wins!" << std::endl;
      break;
    }

    stuck = p3.play(table) || stuck;
    if (stuck) {
      std::cout << "Player 3's Turn!" << std::endl;
      std::cout << table;
      std::cout << "player 1: " << p1;
      std::cout << "player 2: " << p2;
      std::cout << "=====> player 3: " << p3;
      std::cout << "player 4: " << p4;
    }
    if (p3.empty()) {
      std::cout << "Player 3 wins!" << std::endl;
      break;
    }
    
    stuck = p4.play(table) || stuck;
    if (stuck) {
      std::cout << "Player 4's Turn!" << std::endl;
      std::cout << table;
      std::cout << "player 1: " << p1;
      std::cout << "player 2: " << p2;
      std::cout << "player 3: " << p3;
      std::cout << "=====> player 4: " << p4;
    }
    if (p4.empty()) {
      std::cout << "Player 4 wins!" << std::endl;
      break;
    }
  }
  if (!stuck) std::cout << "F mano yikes. Se tranco la cosa." << std::endl;
}