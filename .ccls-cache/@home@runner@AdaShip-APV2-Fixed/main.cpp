//Currently missing validation of inputs
//Need improvements on the output of the board
//Require autoplacement to be split up for each ship

#include "headersReq.h"

using namespace google;

int main() {
  //Creates a menu object that then calls a function to begin the game setup 
  Menu menu;
  menu.Execute();
  
  //Creates 2 player objects that are then used to keep track of each player during the game
  Player* player1;
  Player* player2;

  //Gets the game mode from the menu
  GameModeConfig config = menu.GetConfig();
  HumanPlayer* humanPlayer1 = new HumanPlayer(config, "Player 1");
  NpcPlayer* npcPlayer2 = new NpcPlayer(config);

  //Sets the player types to the player objects created above
  player1 = humanPlayer1;
  player2 = npcPlayer2;
  
  //Sets board dimensions from config file
  int boardWidth = config.boardWidth;
  int boardHeight = config.boardHeight;
  //std::cout << "Width: " << boardWidth << " Height: " << boardHeight << "\n";

  //Creates board objects and completes setup for boards and players
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