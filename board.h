#include "headersReq.h"

#ifndef _INCLUDE_BOARD_H_
#define _INCLUDE_BOARD_H_

namespace google {

enum Tile {
  EMPTY = 0,
  SHIP = 1,
  HIT = 2,
  MISS = 3,
};

class Board {
 public:
  Board(int x, int y) : _x(x), _y(y) {
    SetupBoard();
  }

  void Render(bool hitsOnly = false);
  bool IsValidPlacement(Placement placement);
  bool ApplyPlacement(Placement placement);
  bool ApplyMove(Move move);
  void AutoPlace(GameModeConfig config);
  bool Empty();
  void Reset();
  
 private:
  int _x;
  int _y;

  std::vector<std::vector<int>> _board;

  void HitMine(int x, int y);

  void SetupBoard() {
    _board.resize(_x);

    for (int i = 0; i < _x; i++) {
      _board[i].resize(_y);
    }
    
    Reset();
  }

  void RenderLine() {
    for (int i = 0; i < _x; i++) {
      std::cout << "--";
    }
    std::cout << "\n";
  }
};

} 

#endif 