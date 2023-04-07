cmake_minimum_required(VERSION 3.20)
project(da-project1)

set(CMAKE_CXX_STANDARD 17)


add_executable(da-project1 src/main.cpp tests/GraphTests.cpp src/view/Menu.cpp src/view/DrawUtils.cpp src/view/DrawPaths.cpp src/services/Scrapper.cpp src/services/Program.cpp src/services/actions/ShowStations.cpp src/services/actions/ShowLines.cpp src/services/actions/SearchStation.cpp src/services/actions/SearchLine.cpp src/services/actions/MaxFlowOrigins.cpp src/services/actions/MaxFlowGroups.cpp src/services/actions/MaxFlow.cpp src/services/actions/Disable.cpp src/services/actions/DestinationMaxFlow.cpp src/services/actions/CheapestMaxFlow.cpp src/services/actions/ChangeMenu.cpp src/services/actions/Action.cpp src/model/Station.cpp src/model/Line.cpp src/model/Graph.cpp src/view/DrawUtils.h)