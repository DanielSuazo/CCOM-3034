#include<iostream>
#include<deque>
#include<list>

struct Tile {
    int l, r;
    Tile(int left, int right) : l(left), r(right) {}
    void swap() { std::swap(l,r); }
    void display() {
      if (r == -1) return;
      std::cout << "[" << l << "|" << r << "]" << " ";
    }
};

class Table : private std::deque<Tile> {
  public:
    Table();
    int right() const { return back().r; }
    int left() const { return front().l; }
    void playRight(Tile t) { push_back(t); }
    void playLeft(Tile t) { push_front(t); }
    void setBoard();
    std::list<Tile> dealTiles();
    void display(std::ostream &out) const;
};

class Player : public std::list<Tile> {
  public:
    Player();
    Player operator=(std::list<Tile>);
    bool play(Table &board);
    void display(std::ostream &out) const;
    bool empty() const;
};

std::ostream &operator<<(std::ostream &out, const Table &t);
std::ostream &operator<<(std::ostream &out, const Player &t);