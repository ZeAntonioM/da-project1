//
// Created by franciscocardoso on 02-04-2023.
//

#ifndef DA_PROJECT1_DRAWPATHS_H
#define DA_PROJECT1_DRAWPATHS_H
#include "iostream"
#include "../model/Graph.h"
#include "DrawUtils.h"



class DrawPaths {
public:
    /**
     * @brief displays a table with a path from one stations to another, the max flow and its cost
     * @param maxFlow the max flow from the two stations
     * @param cost the cost of the max flow
     * @param path vector with all paths
     * @param page the current path to display
     * @complexity O(1) being E the lines from the path
     */
    void draw(int maxFlow, int cost,vector<Path> path, int page)const;
    /**
     * @brief displays all the paths from one station to another with pagination,
     * (one path per page) and lets you navigate between them
     * @param maxFlow the max flow from the two stations
     * @param cost the cost of the max flow
     * @param path vector with all paths
     * @complexity O(1) being E the lines from the paths
     */
    void pageController(int maxFlow, int cost, vector<Path> path)const;

};


#endif //DA_PROJECT1_DRAWPATHS_H
