#include "game.h"

int main() {
  // Initiate variables, set board and deal all tiles to players
  Table table;
  table.setBoard();
  Player p1, p2, p3, p4;
  p1 = table.dealTiles();
  p2 = table.dealTiles();
  p3 = table.dealTiles();
  p4 = table.dealTiles();

  // Loop as long as at least one player can play a domino
  bool playable;
  do {
    playable = false;


    playable = p1.play(table) || playable; // makes playable true if player 1 can play
    // Player 1 takes his turn
    if (playable) { 
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


    playable = p2.play(table) || playable; // makes playable true if player 2 can play
    // Player 2 takes his turn
    if (playable) {
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


    playable = p3.play(table) || playable; // makes playable true if player 3 can play
    // Player 3 takes his turn
    if (playable) {
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
    

    playable = p4.play(table) || playable; // makes playable true if player 4 can play
    // Player 4 takes his turn
    if (playable) {
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
  } while(playable);
  // Print out the message that the game is no longer playable
  if (!playable) std::cout << "F mano yikes. Se tranco la cosa." << std::endl;
}