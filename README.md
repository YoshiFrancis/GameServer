### Yoshi's Gamehub Server

## Description

A gamehub server that can host applications in C++ following a particular messaging protocol. Server can handle mutliple users by utilizing ASIO's library for asynchronous input and output. Future goals is to build a websocket service so that web users may also be able to play with terminal users. I would also like to support applications in other languages. I would do this through a stream over the web.

## User guide

clonse the repo:
git clone https://github.com/YoshiFrancis/GameServer.git

go into the directory:
cd GameServer

go into the build directory:
cd build

You must build the server:
make

After making you can either host the server or join an already opened server on a friend's computer.
To create a server, run:
./server_main <port to run on>

To join a server (you can do this ont he same computer, just make another tab in the terminal):
./client_main <ip the server is running on> <local port the server is running on>

AFterward, you will be prompted to enter a name. Type in /help for more commands.

Currently the only games right now is an Uno implementation.
