#include "headersReq.h"

using namespace google;

int main() {
  MainMenu main_menu;
  main_menu.Execute();

  Player* player1;
  Player* player2;


  GameModeConfig config = main_menu.GetConfig();
  HumanPlayer* humanPlayer1 = new HumanPlayer(config, "Player 1");
  BadNpcPlayer* npcPlayer1 = new BadNpcPlayer(config);
  HumanPlayer* humanPlayer2 = new HumanPlayer(config, "Player 2");
  BadNpcPlayer* npcPlayer2 = new BadNpcPlayer(config);


  if (config.player1 == PlayerType::HUMAN) {
    player1 = humanPlayer1;
  } else {
    player1 = npcPlayer1;
  }

  if (config.player2 == PlayerType::HUMAN) {
    player2 = humanPlayer2;
  } else {
    player2 = npcPlayer2;
  }

  int boardWidth = config.boardWidth;
  int boardHeight = config.boardHeight;
  std::cout << "Width: " << boardWidth << " Height: " << boardHeight << "\n";
  Board* board1 = new Board(boardWidth, boardHeight);
  board1->Reset();
  Board* board2 = new Board(boardWidth, boardHeight);
  board2->Reset();

  SetupMode setup(player1, player2, board1, board2, config);
  setup.Execute();

  GameplayMode game(player1, player2, board1, board2, config);
  game.Execute();

  return 0;
}