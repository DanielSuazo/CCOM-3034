from collections import deque
from random import shuffle

class Domino:
  def __init__(self, left, right):
    self.left = left
    self.right = right

  def swap(self):
    tmp = self.left
    self.left = self.right
    self.right = tmp

  def display(self):
    print('[', self.left, '|', self.right,']', sep='', end=' ')

class Player:
  hand = deque()

  def play(self, board):
    for i in self.hand:
      if i.right == board[0].left:
        board.appendleft(i)
        self.hand.remove(i)
        return True
      elif i.right == board[-1].right:
        i.swap()
        board.append(i)
        self.hand.remove(i)
        return True
      elif i.left == board[0].left:
        i.swap()
        board.appendleft(i)
        self.hand.remove(i)
        return True
      elif i.left == board[-1].right:
        board.append(i)
        self.hand.remove(i)
        return True
    return False

  def display(self):
    for i in self.hand:
      i.display()
    print()
  def takeTiles(self, b):
    for i in range(0, 8):
      self.hand.append(b.board.pop())

class Table:
  board = deque()
  def __init__(self):
    for i in range(0,7):
      for j in range(0,7):
        self.board.append(Domino(i, j))
    shuffle(self.board)

  def display(self):
    for i in self.board:
      i.display()
    print()


board = Table()
p1 = Player()
p1.takeTiles(board)
p1.display()