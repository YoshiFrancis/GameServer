cmake_minimum_required(VERSION 3.29) 
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)
project(testing 
				VERSION 3.29
				LANGUAGES CXX
)

include_directories(~/Documents/ASIO/asio-1.30.2/include ~/Documents/CppLib/websocketpp include)

add_subdirectory(src)
add_subdirectory(Card-Game)
target_link_libraries(unogame PUBLIC server)

add_executable(server_main server_main.cpp)
add_executable(client_main client_main.cpp)
target_link_libraries(server_main PUBLIC server unogame)
target_link_libraries(client_main PUBLIC client)


