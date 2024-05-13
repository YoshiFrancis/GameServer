Description:

Game room to be used for holding a variety of different types of activities/apps. I will utilize this application to host my uno card game, a simple chat server, and other applications whihc will require networking. All the new apps will be required/encouraged to have their own custom message. The message and the game itself should be the only changes in implementations varying in each application.

Outline of structure:

## Server
The server accepts incomming clients. Places them in the general hub.
-->
## Hub
Holds all the lobbies. Also contains all the players who have not joined a lobby yet. May also include a shared ptr to all players in general. Will inherit from the room class to enable messaging clients. This is needed for making new lobbies, asking for usernames, and sending clients' to their wished upon lobby.
-->
## Lobby
Each lobby will hold a particular game. For example, if a player wishes to make a new card game lobby, they will send request to the hub. The hub will then create the lobby tailored for the card game. Lobby will also inherit from the room class. Each different type of lobby (like a chat server lobby, uno game lobby, etc.) may vary in the type of custom messages being exchanged. 

## Overall

One Server --> One Hub --> to many lobbies (each player can only be in one lobby at a time).






## TODO
1. settup the infrastucture code for the server->hub->lobby->app system
2. implement hub functionality -- DONE
	- give user list of options: create new game lobby, view all game lobbies, join game lobby, ( prompt user for username -- DONE ) -- DONE


3. implement lobby functionality
	- get player to join, let player leave back to lobby, able to restart lobby (like when game ends), start game, end game, close lobby
	- could potentially let other players spectate ongoing game in the future
4. Implement applications
	- this is basically the end game. After 1-3, I will only be operating indivdually on the applications, which should be generall separated from the networking side. After 1-3, most of the networking side of the application is finished



	## CURRENT WORK
	- implementing lobby functionality
