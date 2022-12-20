#include "headersReq.h"

using namespace std;

#ifndef _INCLUDE_SETUP_H_
#define _INCLUDE_SETUP_H_

namespace google {

class SetupMode : public GameMode {
 public:
  SetupMode(Player* player1, Player* player2,
            Board* board1, Board* board2, GameModeConfig config)
            : _player1(player1), _player2(player2), 
            _board1(board1), _board2(board2), _config(config) {}

  void WaitForInput() override {
    std::cout << "Autoplace? (y/n)\n";
    std::string buffer;
    std::cin >> buffer;

    bool valid = true;
    if (_player1->ShouldAutoPlace() || (buffer == "y")) {
      _board1->AutoPlace(_config);
      if (_player1->ShouldRenderBoard())
        _board1->Render();
    } else {
      do {
        Placement move = _player1->GetNextPlacement(_board1);
        valid = _board1->ApplyPlacement(move);
        if (!valid && _player1->IsHuman()) {
          _board1->Render();
          std::cout << "Invalid placement:" << std::endl;
        }
        if (_player1->ShouldRenderBoard())
          _board1->Render();
      } while (!valid);
    }

    if (_player2->ShouldAutoPlace()|| (buffer == "y"))  {
      _board2->AutoPlace(_config);
      if (_player2->ShouldRenderBoard())
        _board2->Render();
    } else {
      do {
        Placement move = _player2->GetNextPlacement(_board2);
        valid = _board2->ApplyPlacement(move);
        if (!valid && _player2->IsHuman()) {
          _board2->Render();
          std::cout << "Invalid placement:" << std::endl;
        }
        if (_player2->ShouldRenderBoard())
          _board2->Render();
      } while (!valid);
    }
    
    std::cout << "Reset/Continue/Quit? (r/c/q)\n";
    std::cin >> buffer;
    if (buffer == "r") {
      _board1->Reset();
      _board2->Reset();
    } else if (buffer == "c") {
      _active = _player1->AllPiecesDown() && _player2->AllPiecesDown();
    } else if (buffer == "q") {
      exit(0);
    }
  }

  void Render() override {}
  void Tick() override {}

 private:
  Player* _player1;
  Player* _player2;
  Board* _board1;
  Board* _board2;
  GameModeConfig _config;
};

} 

#endif 