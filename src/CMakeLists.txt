include_directories(~/Documents/ASIO/asio-1.30.2/include)
add_library(server STATIC connection.cpp room.cpp server.cpp message.cpp)
add_library(client STATIC client.cpp message.cpp)
target_include_directories(server PUBLIC ${PROJECT_SOURCE_DIR/include})
