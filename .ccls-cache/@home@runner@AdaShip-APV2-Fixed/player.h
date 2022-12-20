#include "headersReq.h"

#ifndef _INCLUDE_PLAYER_H_
#define _INCLUDE_PLAYER_H_

namespace google {

class Player {
 public:
  Player() {}
  Player(Player&&) = default;
  virtual Placement GetNextPlacement(Board* board) = 0;
  virtual Move GetNextMove() = 0;
  virtual bool ShouldRenderBoard() { return false; }
  bool AllPiecesDown() { return _piecesDown; }
  virtual bool ShouldAutoPlace() { return false; }
  bool IsHuman() { return false; }
 protected:
  bool _piecesDown = false;
};

class NpcPlayer : public Player {
 public:
  NpcPlayer(GameModeConfig config) : _config(config) {
    for (int i = 0; i < config.ships.size(); i++) {
      _remainingShips.push(config.ships[i]);
    }
  }

  Placement GetNextPlacement(Board* board) {
    return Placement{};
  }

  Move GetNextMove() {
    return RandomMove();
  }
  virtual bool ShouldAutoPlace() { return true; }

 private:
  std::stack<ShipDefinition> _remainingShips;
  GameModeConfig _config;
  Move RandomMove() {
    return Move{
      .x = rand() % _config.boardWidth,
      .y = rand() % _config.boardHeight,
    };
  }
};

class HumanPlayer : public Player {
 public:
  HumanPlayer(GameModeConfig config, std::string name) : _config(config) {
    for (int i = 0; i < config.ships.size(); i++) {
      _remainingShips.push(config.ships[i]);
    }
    _name = name;
  }

  Placement GetNextPlacement(Board* board) {
    Placement placement;
    bool valid = false;
    while (!valid) {
      ShipDefinition next = _remainingShips.top();
      std::string buffer;
      std::cout << "Next placement (e.g. A2) - " << next.name << ": ";
      std::cin >> buffer;
      
      placement = Placement{
        .move = MoveFromInputBuffer(buffer),
        .length = next.length,
        .sideways = true,
      };
      valid = board->IsValidPlacement(placement);
    }

    _remainingShips.pop();
    _piecesDown = _remainingShips.size() == 0;
    return placement;
  }

  Move GetNextMove() {
    std::cout << "[" << _name << "] Next move: ";
    std::string buffer;
    std::cin >> buffer;
    return MoveFromInputBuffer(buffer);
  }

  bool IsHuman() { return true; }
  virtual bool ShouldRenderBoard() { return true; }

  Move MoveFromInputBuffer(std::string buffer) {
    std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::toupper);
    return Move{
      .x = indexForColumnReference(buffer.substr(0,1)),
      .y = std::atoi(buffer.substr(1,1).c_str() ) - 1,
    };
  }

 private:
  std::string _name = "Player";
  std::stack<ShipDefinition> _remainingShips;
  GameModeConfig _config;

  int indexForColumnReference(std::string buffer) {
    if(buffer.length() == 1) {
      return toupper(int(buffer[0])) - 65;
    } else if(buffer.length() == 2) {
      return ((toupper(int(buffer[1])) - 65) + (toupper(int(buffer[0])) - 64) * 26);
    }
    return -1;
  }
};

}

#endif 