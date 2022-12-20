#include "headersReq.h"

#ifndef _INCLUDE_CONFIGURATION_H_
#define _INCLUDE_CONFIGURATION_H_

namespace google {

enum PlayerType {
  HUMAN,
  NPC,
};

enum GameModeType {
  DEFAULT,
};

struct ShipDefinition {
  std::string name;
  int length;
};

struct GameModeConfig {
  PlayerType player1;
  PlayerType player2;
  GameModeType gameMode;
  int boardHeight;
  int boardWidth;
  std::vector<ShipDefinition> ships;
};

GameModeConfig LoadConfigFromFile();

} 

#endif 