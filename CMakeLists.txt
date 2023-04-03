cmake_minimum_required(VERSION 3.24)
project(da-project1)

set(CMAKE_CXX_STANDARD 17)


add_executable(da-project1 src/main.cpp src/services/Scrapper.cpp src/services/Scrapper.h src/services/Scrapper.cpp src/main.cpp src/services/Scrapper.cpp src/services/Scrapper.h src/model/Line.cpp src/services/Scrapper.h src/model/Line.cpp src/model/Station.cpp src/model/Graph.h src/model/Graph.cpp src/services/Program.cpp src/services/Program.h src/view/Menu.cpp src/view/Menu.h src/services/actions/Action.cpp src/services/actions/Action.h src/services/actions/ChangeMenu.cpp src/services/actions/ChangeMenu.h tests/GraphTests.h tests/GraphTests.cpp src/services/actions/MaxFlow.h src/services/actions/MaxFlow.cpp src/services/actions/ShowStations.h src/services/actions/ShowStations.cpp  src/services/actions/SearchStation.h src/services/actions/SearchStation.cpp)

