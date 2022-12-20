#include "headersReq.h"

namespace google {

void Board::Render(bool hitsOnly) {
  std::cout << std::endl;

  RenderLine();

  for (int i = 0; i < _y; i++) {
    for (int j = 0; j < _x; j++) {
      switch (_board[i][j]) {
        case Tile::SHIP:
          if (hitsOnly)
            std::cout << ".";
          else
            std::cout << "-";
          break;

        case Tile::HIT:  // Hit.
          std::cout << "X";
          break;
        case Tile::MISS:  // Miss.
          std::cout << "0";
          break;
        case Tile::EMPTY:
        default:
          std::cout << ".";
      }
    }

    std::cout << std::endl;
  }

  RenderLine();
}

bool Board::IsValidPlacement(Placement placement) {
  int x = placement.move.x;
  int y = placement.move.y;
  int width = _board.size();
  int height = _board[0].size();

  if (placement.sideways) {
    if (x + placement.length >= width || y >= height) {
      return false;
    }

    for (int i = 0; i < placement.length; i++) {
      if (_board[x+i][y] != Tile::EMPTY) {
        return false;
      }
    }
  } else {
    if (x >= width || y + placement.length >= height) {
      return false;
    }

    for (int i = 0; i < placement.length; i++) {
      if (_board[x][y+i] != Tile::EMPTY) {
        return false;
      }
    }
  }

  return true;
}

bool Board::ApplyPlacement(Placement placement) {
  int x = placement.move.x;
  int y = placement.move.y;

  if (!IsValidPlacement(placement)) {
    return false;
  }

  if (placement.sideways) {
    for (int i = 0; i < placement.length; i++) {
      _board[x+i][y] = Tile::SHIP;
    }
  } else {
    for (int i = 0; i < placement.length; i++) {
      _board[x][y+i] = Tile::SHIP;
    }
  }

  return true;
}

bool Board::ApplyMove(Move move) {
  int i = move.x;
  int j = move.y;

  if (_board[i][j] == Tile::SHIP) {
    _board[i][j] = Tile::HIT;
    std::cout << "HIT" << std::endl;
  } else {
    _board[i][j] = Tile::MISS;
    std::cout << "MISS" << std::endl;
  }

  return true;
}

void Board::AutoPlace(GameModeConfig config) {
  std::stack<ShipDefinition> ships;
  for (int i = 0; i < config.ships.size(); i++) {
    ships.push(config.ships[i]);
  }

  while (!ships.empty()) {

    Placement placement;
    bool valid = false;
    ShipDefinition next = ships.top();
    
    while (!valid) {
      placement = Placement{
        .move = Move{
          .x = (int) rand() % config.boardWidth,
          .y = (int) rand() % config.boardHeight,
        },
        .length = next.length,
        .sideways = true,
      };
      valid = IsValidPlacement(placement);
    }

    ApplyPlacement(placement);
    if (!ships.empty()) ships.pop();
    std::cout << "[ NPC ] Auto-placed: " << next.name << "\n";
  }
}

bool Board::Empty() {
  for (int i = 0; i < _y; i++) {
    for (int j = 0; j < _x; j++) {
      if (_board[i][j] == Tile::SHIP) {
        return false;
      }
    }
  }

  return true;
}

void Board::Reset() {
  for (int i = 0; i < _board.size(); i++) {
    for (int j = 0; j < _board[i].size(); j++) {
      _board[i][j] = Tile::EMPTY;
    }
  }
}

}