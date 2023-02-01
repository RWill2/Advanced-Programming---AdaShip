<h1>AdaShip - Advanced Programming</h1>
<h4>By Rebeca Williams</h4>

<h3>Challenge Outline</h3>
#Summary & Review of problem + propsed solution

AdaShip is similar to the well known Battleships game. By default it is a 2 player game where each player takes turns in trying to elimenate the other players boats. To win the game you must destroy/sink all of your opponents boats.

#UML Diagram
#Working Plan, Overall Approach, Development Stratergy, Approach to Quality

For this project there are 3 releases. The first release forms the well known Battleship game where the player will be playing against th computer.For a default game each player has 2 10x10 boards. One will be used for your ships, this is known as a shipboard and is where you will place you ships as well as hits made by your opponent. The other board is known as the targetboard. This is where you can keep track of where you have fired and if it was a hit or a miss. Locations on the boards will have a single notation coordinate system which is made up of an alphabetic letter fr the colums and a number for the row e.g. A3. There are 5 ships that come in various sizes. They all need to be placed on the shipboard before the game can be played. They can be placed horizontally or vertically but must remain wthin the bounds of the board and cannot cross another ship already on the board.

The second release will allow for the game to be extended to allow for two human players to play against eachother. It will also include the addition of a salvo gamemode. The salvo game is an updated version of the original game but the number of torpedos that can be fired is determined by the number of remaining ships the player has. 

The third release has many new features. It will allow for an infinite number of boats to the game through the 'adaship_config.ini' file. It also includes a new gamemode called hidden mines. The hidden mines update means a set number of mines are placed on each players boards randomly during the setup phase. These are then displayed to the player during the game. If the opposing player hits the mine all immediately surrounding locations explode. Any ships in those exploded locations are then marked as hit. This third release also includes better computer targeting through to make th computer player more difficult to play against.

To complete the development, each release will be broken down into smaller tasks, allowing for the sepration of concerns and logical steps for development. Each group of tasks will focus on a core part of functionality. This will mean they can be tested as smaller units before implementing into the rest of the code. This will ensure that all changes made in the code are completed gradually to reduce errors.

#Decomposition of overall problem, epic style tasks

<h4>Release 1 Tasks</h4>
1)Setup the 'adaship_config.ini'<br>
2)Create Setup interface which will give the user the gamemode options<br>
3)Display shipboard for user to placeships<br>
4)Create autoplace ship function that will allow the user to have the system place ships<br>
5)Allow user to quit and reset their shipboard<br>
6)Continue once user is happy with completed shipboard<br>
7)Get computer to autoplace their ships<br>
8)Create turn based process <br>
9)Get user to enter fire location<br>
10)Determine wether hit or miss and output result to player<br>
11)Create function to determine if win conditions have been met<br>
12)Allow user to quit game<br>
13)Get user to press a key to end turn

<h4>Release 2 Tasks</h4>
1)Allow user to input any valid board size through the 'adaship_config.ini'<br>
2)Update setup menu to include player vs player and salvo gamemode<br>
3)Implement function that allows for more than 1 coordinate to be entered.<br>
4)Create function tha tracks how many ships remain<br>
5)Repeat 'fire' for each coordinate from task 3<br>
6)Output result of each 'fire' to the user

<h4>Release 3 Tasks</h4>
1)Allow user to add any number of ships through the 'adaship_config.ini'<br>
2)Update setup menu to include hidden mines gamemode<br>
3)Create that randomly places mies on each players board<br>
4)Update hit -> If hit on mine mark hits on surrounding locations<br>
5)Update computer auto-hit by keeping track of hit locations and targeting surrounding pieces to determine which direction the ship is placed, once sunk select new random firing location 

#Object Oriented design, Planed phased breakdown into smaller tasks
<h4>Object Oriented Design</h4>
For the program to follow object oriented principles I plan to create several objects. The plan is to have a board object. This board will have x and y values that are used to setup the boards size and coordinates. It will also have various methods that track and validate the placement of ships. Players are also objects, give that both the human and computer player share some characteristics it allows for inheritance. Both players have will have a property that determines wether they are human or not. From the player class there will be a computer player class and a human player class. The computer player will inherit features from the player class. The human player will also inherit from the player class. This reduces code repetition as both human and computer players share features. However the computer player will be calling an automatic placement and automatic firing function whereas the human player is given options before these funcions can be called. Another possible object could be a ship object which contains the properties of each ship and keeps track of the hits each ship takes. 

<h3>Development</h3>
#Tasks for each phase of development
#QA through testing ad finding bugs
#Reflect on key changes, innovations and how they were solved

<h3>Evaluation</h3>
#Analysis of key code, refactoring and code smells
#Implementation and effective use of advanced programing principles
#Showcase any innovations
#Improved algorithms (research, design, implementation and testing)
#Reflective review, opportuniies to improve

<h3>Overview</h3>

AdaShip is similar to the well known Battleships game. By default it is a 2 player game where each player takes turns in trying to elimenate the other players boats. To win the game you must destroy/sink all of your opponents boats.

For a default game each player has 2 10x10 boards. One will be used for your ships, this is known as a shipboard and is where you will place you ships as well as hits made by your opponent. The other board is known as the targetboard. This is where you can keep track of where you have fired and if it was a hit or a miss. Locations on the boards will have a single notation coordinate system which is made up of an alphabetic letter fr the colums and a number for the row e.g. A3.

There are 5 ships that come in various sizes. They all need to be placed on the shipboard before the game can be played. They can be placed horizontally or vertically but must remain wthin the bounds of the board and cannot cross another ship already on the board.

<h3>Releases</h3>

The plan is to release the game in smaller releases that have been broken down into tasks. Release 1 will contain the basics required for the application to run as well as the core functionality for a single player vs computer game. Release 2 looks at expanding the game modes to allow 2 people to play together as well as adding a salvo game mode. The salvo mode means that the player will be able to fire as many missiles as they have ships still standing, for example if the player has 4 ships standing they can then fire 4 missiles at their enemies ships. Finally a third release could be in scope depending on time.

For the first release the main goals are to have the configurtion file should be read by the system. From this the set-up interface is displayed allowing the player to select ther game mode, place/autoplace their ships. Once the player has placed all their ships in valid positions on the board the computer will then automatically place all of their ships in valid positions. The player and computer will then take turns firing/autofiring torpedos at their oponnents ships. The game is then won when all of the oponnents ships have been sunk.

<h3>Data Flow Diagram for Release 1 Tasks 1 - 3</h3>
https://app.diagrams.net/#G1zrv_Eb3DwqsYM9R7Ld0ypXyIbOuplufc
