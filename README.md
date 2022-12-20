<h1>AdaShip - Advanced Programming</h1>
<h4>By Rebeca Williams</h4>

<h3>Overview</h3>

AdaShip is similar to the well known Battleships game. By default it is a 2 player game where each player takes turns in trying to elimenate the other players boats. To win the game you must destroy/sink all of your opponents boats.

For a default game each player has 2 10x10 boards. One will be used for your ships, this is known as a shipboard and is where you will place you ships as well as hits made by your opponent. The other board is known as the targetboard. This is where you can keep track of where you have fired and if it was a hit or a miss. Locations on the boards will have a single notation coordinate system which is made up of an alphabetic letter fr the colums and a number for the row e.g. A3.

There are 5 ships that come in various sizes. They all need to be placed on the shipboard before the game can be played. They can be placed horizontally or vertically but must remain wthin the bounds of the board and cannot cross another ship already on the board.

<h3>Releases</h3>

The plan is to release the game in smaller releases that have been broken down into tasks. Release 1 will contain the basics required for the application to run as well as the core functionality for a single player vs computer game. Release 2 looks at expanding the game modes to allow 2 people to play together as well as adding a salvo game mode. The salvo mode means that the player will be able to fire as many missiles as they have ships still standing, for example if the player has 4 ships standing they can then fire 4 missiles at their enemies ships. Finally a third release could be in scope depending on time.

For the first release the main goals are to have the configurtion file should be read by the system. From this the set-up interface is displayed allowing the player to select ther game mode, place/autoplace their ships. Once the player has placed all their ships in valid positions on the board the computer will then automatically place all of their ships in valid positions. The player and computer will then take turns firing/autofiring torpedos at their oponnents ships. The game is then won when all of the oponnents ships have been sunk.

<h3>Data Flow Diagram for Release 1 Tasks 1 - 3</h3>
https://app.diagrams.net/#G1zrv_Eb3DwqsYM9R7Ld0ypXyIbOuplufc