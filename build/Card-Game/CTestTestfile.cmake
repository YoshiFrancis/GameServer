# CMake generated Testfile for 
# Source directory: /Users/fozua/Desktop/GameServer/Card-Game
# Build directory: /Users/fozua/Desktop/GameServer/build/Card-Game
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[local_tests]=] "/Users/fozua/Desktop/GameServer/build/Card-Game/tests/test_local")
set_tests_properties([=[local_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/fozua/Desktop/GameServer/Card-Game/CMakeLists.txt;24;add_test;/Users/fozua/Desktop/GameServer/Card-Game/CMakeLists.txt;0;")
add_test([=[helper_tests]=] "/Users/fozua/Desktop/GameServer/build/Card-Game/tests/test_helper")
set_tests_properties([=[helper_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/fozua/Desktop/GameServer/Card-Game/CMakeLists.txt;25;add_test;/Users/fozua/Desktop/GameServer/Card-Game/CMakeLists.txt;0;")
subdirs("src")
subdirs("tests")
