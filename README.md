<h1>AdaShip - Advanced Programming</h1>
<h4>By Rebeca Williams</h4>

<h3>Challenge Outline</h3>
AdaShip is similar to the well known Battleships game. By default it is a 2 player game where each player takes turns in trying to elimenate the other players boats. To win the game you must destroy/sink all of your opponents boats.

For this project there are 3 releases. The first release forms the well known Battleship game where the player will be playing against th computer. For a default game each player has 2 10x10 boards. One will be used for your ships, this is known as a shipboard and is where you will place you ships as well as hits made by your opponent. The other board is known as the targetboard. This is where you can keep track of where you have fired and if it was a hit or a miss. Locations on the boards will have a single notation coordinate system which is made up of an alphabetic letter for the column and a number for the row e.g. A3. There are 5 ships that come in various sizes. They all need to be placed on the shipboard before the game can be played. They can be placed horizontally or vertically but must remain wthin the bounds of the board and cannot cross another ship already on the board. The second release will allow for the game to be extended to allow for two human players to play against eachother. It will also include the addition of a salvo gamemode. The salvo game is an updated version of the original game but the number of torpedos that can be fired is determined by the number of remaining ships the player has. The third release has many new features. It will allow for an infinite number of boats to the game through the 'adaship_config.ini' file. It also includes a new gamemode called hidden mines. The hidden mines update means a set number of mines are placed on each players boards randomly during the setup phase. These are then displayed to the player during the game. If the opposing player hits the mine all immediately surrounding locations explode. Any ships in those exploded locations are then marked as hit. This third release also includes better computer targeting through to make th computer player more difficult to play against. To complete the development, each release will be broken down into smaller tasks, allowing for the sepration of concerns and logical steps for development. Each group of tasks will focus on a core part of functionality. This will mean they can be tested as smaller units before implementing into the rest of the code. This will ensure that all changes made in the code are completed gradually to reduce errors.

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
3)Create that randomly places mines on each players board<br>
4)Update hit -> If hit on mine mark hits on surrounding locations<br>
5)Update computer auto-hit by keeping track of hit locations and targeting surrounding pieces to determine which direction the ship is placed, once sunk select new random firing location 

<h4>Object Oriented Design</h4>
For the program to follow object oriented principles I plan to create several objects. The plan is to have a board object. This board will have x and y values that are used to setup the boards size and coordinates. It will also have various methods that track and validate the placement of ships. Players are also objects, given that both the human and computer player share some characteristics it allows for inheritance. Both players will have a property that determines wether they are human or not. From the Player class there will be a Computer Player class and a Human Player class. The Computer Player will inherit features from the Player class. The Human Player will also inherit from the Player class. This reduces code repetition as both Human and Computer players share features. However the Computer player will be calling an automatic placement and automatic firing function whereas the Human player is given options before these funcions can be called. Another possible object could be a ship object which contains the properties of each ship and keeps track of the hits each ship takes. 

<h3>Development</h3>
<h4>Data Flow Diagram for Release 1</h4>
![Screenshot_20221220_225206](https://user-images.githubusercontent.com/92785142/218458339-13196364-1e8d-49b2-b66f-278d4b7f11ff.png)

<h4>Phases Of Development</h4>
For the first release the data will move around the system as depicted in the above diagram. There is a class for the Player object as well as the Board and the Gamemode. There is also the possibility of having classes for objects like the missiles as the game develops and features such as the Salvo and Hidden Mines functionalities are added. The game begins through the creation of the menu which prompts the user to select their gamemode. Once the gamemode and player types have been decided the boards are created for each player. Once both players and their boards have been setup the game is started using the information related to the selected gamemode. 

During the first development phase the tasks will be implemented following the tasks set out above. The configuration file and menu for user will be setup first to follow the basic flow of the game. From there the Ship and Board classes will be implemented. This will then allow the ships to be placed and checked to ensure they are placed within the board limits. The creation of the autoplace function will be created and then improved to allow individual ships to be autoplaced. Once the board and ships are setup the system will then begin the game and then take turns getting firing locations. There will also be an autofire function which will be used by the computer player as well as the human player where requested. The system will have a function that determines wether a ship is hit, missed or sunk. I will also need to develop an option to allow the user to quit the game at any point throughout.

The second development phase will include adding the salvo gamemode. This will be completed by adding a function that keeps track of how many ships are not sunk. I will then update the way missile locations are entered. This will include a vector which will store the coordinates that have been entered. From here the system can then identify if each firing location has missed, hit or sunk a ship. When adding the player vs player gamemode the plan is for the game set up in release 1 to be updated. When the user selects a player vs player mode 2 human player objects will be created when the gamemode is selected but if a player vs computer mode is selected 1 human and 1 computer player object will be created. Allowing the user to change the board dimensions will require validation of the inputs. When the 'adship_config.ini' is read the game will take the information relating to the board. It will then determine if the values are within the valid range that has been set out in the brief as 5x5 to 80x80.

The third development phase involves allowing the user to add ships through the 'adaship_config.ini' and add the hidden mines gamemode. For the adding of new ships more validation is required. This is to ensure the boats have the relevant information available and that all boats will fit onto the board. To do this I will track how many tiles are on the board as well as how many tiles are required for all the ships. As long as the number of boat tiles <= number of board tiles there is a valid number of ships. Otherwise the user will be alerted that the game cannot start due to there being too many ships. For the implementation of the hidden mines gamemode a function will be craeted to randomly select positions on the board. When the board is displayed the player can see where these mines are placed. If a player hits a mine all surrounding tiles will be hit. To create this functionality I will need to add a functionality that finds all surrounding tile locations. Having these locations means I will be able to call a pre-existing function to mark all these loactions as hit and then determine if a ship has been sunk. The final change to be made in release 3 is an improved computer player. I have decided to do this by using a vector to keep track of hit locations. When a hit is found the computer will then play the surrounding locations until the ship has been sunk. Once the ship has been sunk the computer will continue to randomly pick fiiring ocations until a hit has been detected where the previously outlined process will be completed. This will allow the computer to make a more informed decision about where they are firing improving the overall gameplay.

<h4>QA Through Testing & Finding Bugs</h4>
Testing is key to ensuring all key functionality within the game is working as expected. To ensure the code is functional unit tests may be used. These will test all of the tasks and functions that are outlined above in the phases of the development. Another way for me to test the game works is running different scenarios that are designed to break the game, this can include smoke and boundary testing depending on the input type that is required for the test. This will allow me to find weaknesses in my code and then create a more robust game through improving validation and error handling. 

<h4>Key Challenges & Innovations</h4>
One of the main challenges was the autoplacing of ships. Ship autoplacement was a complex change as it required several smaller changes as well as lots of validation to ensure the ship is placed within the board limits. A random number generation was required for determining the position on the board. This auto placement function required a loop as it has to continue generating positions for placement until a valid position is found and the ship can be placed. To ensure the placement is valid a method is called. This method checks that the ship is within board boundaries and the position is currently an empty position. This criteria has to be met for the ship to be placed and a boolean value is returned to say wether the ship position is valid or not.<br>
![IsValidPlacement](https://user-images.githubusercontent.com/92785142/218458153-3cbb85b4-cab1-4997-a82b-9cd4f325c00c.png)


<h3>Evaluation</h3>
#Analysis of key code, refactoring and code smells


<h4>Implementation of AP Principles</h4>
Advanced programming principles like inheritance are shown in the Player object. Human and computer players share certain properties such as IsHuman.<br>
![Player Class](h![NPCPlayer Class](https://user-images.githubusercontent.com/92785142/218466407-007217b8-c2b3-4d86-9d66-2ea5c8ab59b9.png) <br>
Below is the NPCPlayer class which inherits from Player class. It inherits features from the Player class whilst also having someof its own features such as calling fo a random move when it is time to take its turn.<br>
ttps://user-imag![HumanPlayer Class](https://user-images.githubusercontent.com/92785142/218466434-aca51d85-d539-44e4-b41a-f1c4f031c04e.png) <br>
The HumanPlayer class also inherits from the Player class. This means that the NPC and Human players share some functionality which is why inheritance was chosen for my implementation.<br>
es.githubusercontent.com/92785142/218466388-b25f5b5a-f458-43a2-914f-2e9f3614ca43.png)


<h4>Innovations</h4>
One of the innovations is the use of regular expressions within the application to get the board dimensions. The use of regular expressions makes this functionality more robust making the code less likely to break. This will compare the dimensions from the 'adaship_config.ini' with the expression to ensure the input from the file is a numericl value in the format it is expected to be in.  <br>
![RegEx](https://user-images.githubusercontent.com/92785142/218470845-465d702a-0b54-4757-bb76-4ebc392ce2da.png) <br>

Another innovative feature is the use of a 2d vector or the board. A 2d vector makes visualising the board simpler. This is because it looks like and behaves like the game board that is used in play. The coordinates of the game board map to positions in the vector. This makes it easier to build, develop, test and understand why objects on the board are behaving in a certain way. <br>
![2d board](https://user-images.githubusercontent.com/92785142/218472393-6a82eb28-bcb2-47be-8e65-3049ead10134.png) <br>


#Improved algorithms (research, design, implementation and testing)

#Reflective review, opportuniies to improve
<h4>Reflection & Opportunities For Improvement</h4>
Overall this project did not go as planned. Due to various commitments as well as the challenges I faced during this project I did not achieve what I wanted to in the deadline set. The current state of the code shows that there are various functionalities missing. There is currently minimal validation of inputs. This can be seen in the reset and quit functions where it only accepts lowercase inputs. This can be improved by setting all user inputs to lower case to make the game work better and less likely to break. The board display is quite messy and not user friendly. To improve this in future I would look to spend more time improving the user experience when playing the game. This would include improving the flow of the game and the way information is presented to the user. To do this I could use colours on the board and add more feedback to he user so they are aware with the state of the game. A final improvement would be the splitting of the autoplacement functioality for the human player. Currently the code only allows for all ships to be autoplaced. To improve this I would change the design by reworking the way autoplacemnt works. It would include a loop for the placement of ships and then get inputs from the user on how they want that ship to be placed. Using this loop will allow for the ship placement to be better tracked meaning there will be more flexibility in the way the user can place their ships.

To conclude this project has been an intersting learning experience both technically and professionally. It has taught me lessons about advanced programming and the best practices. I have also learnt how to improve my estimation and time management skills. Before approaching this project I had underestimted the amount of time required to complete. Being able to assess the amount of time required for workis a crucial skill when making decisions to do with planning and work prioritisation. Having completed this project I have been able to improve this skill which has assisted in my professional development.

<h3>Overview</h3>

AdaShip is similar to the well known Battleships game. By default it is a 2 player game where each player takes turns in trying to elimenate the other players boats. To win the game you must destroy/sink all of your opponents boats.

For a default game each player has 2 10x10 boards. One will be used for your ships, this is known as a shipboard and is where you will place you ships as well as hits made by your opponent. The other board is known as the targetboard. This is where you can keep track of where you have fired and if it was a hit or a miss. Locations on the boards will have a single notation coordinate system which is made up of an alphabetic letter fr the colums and a number for the row e.g. A3.

There are 5 ships that come in various sizes. They all need to be placed on the shipboard before the game can be played. They can be placed horizontally or vertically but must remain wthin the bounds of the board and cannot cross another ship already on the board.

<h3>Releases</h3>

The plan is to release the game in smaller releases that have been broken down into tasks. Release 1 will contain the basics required for the application to run as well as the core functionality for a single player vs computer game. Release 2 looks at expanding the game modes to allow 2 people to play together as well as adding a salvo game mode. The salvo mode means that the player will be able to fire as many missiles as they have ships still standing, for example if the player has 4 ships standing they can then fire 4 missiles at their enemies ships. Finally a third release could be in scope depending on time.

For the first release the main goals are to have the configurtion file should be read by the system. From this the set-up interface is displayed allowing the player to select ther game mode, place/autoplace their ships. Once the player has placed all their ships in valid positions on the board the computer will then automatically place all of their ships in valid positions. The player and computer will then take turns firing/autofiring torpedos at their oponnents ships. The game is then won when all of the oponnents ships have been sunk.
