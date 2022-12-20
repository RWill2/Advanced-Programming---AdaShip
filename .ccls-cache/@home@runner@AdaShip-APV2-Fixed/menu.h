#include "headersReq.h"

#ifndef _INCLUDE_MENU_H_
#define _INCLUDE_MENU_H_

#include "configuration.h"

namespace google {

class Menu : public GameMode {
 public:
  void WaitForInput() override {
    std::cout << "Choose a game mode or quit:"               << std::endl
              << "\t1. Player vs. computer"                  << std::endl
              << "\t0. Quit"                                 << std::endl;
    int buffer;
    std::cin >> buffer;

    if (buffer < 0 || buffer > 1) {
      std::cout << "Unknown command." << std::endl;
      return;
    }

    _config = LoadConfigFromFile();

    switch (buffer) {
      case 1:
        _config.player1 = PlayerType::HUMAN;
        _config.player2 = PlayerType::NPC;
        _config.gameMode = GameModeType::DEFAULT;
        _active = false;
        break;
      case 0:
        QuitGame();
    }
  }

  void Render() override {}
  void Tick() override {}

  GameModeConfig GetConfig() { return _config; }

 private:
  void QuitGame() {
    std::cout << "Bye bye!" << std::endl;
    exit(0);
  }
  
  GameModeConfig _config;
};

}

#endif 