include_directories(~/Documents/ASIO/asio-1.30.2/include ~/Documents/CppLib/websocketpp)

add_definitions(-DASIO_STANDALONE)
add_definitions(-D_WEBSOCKETPP_CPP11_STL_)

add_library(server STATIC connection.cpp room.cpp server.cpp message.cpp hub.cpp lobby.cpp application.cpp wsserver.cpp wsconnection.cpp)
add_library(client STATIC client.cpp message.cpp)
target_include_directories(server PUBLIC ${PROJECT_SOURCE_DIR/include})
