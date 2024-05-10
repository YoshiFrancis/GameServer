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
