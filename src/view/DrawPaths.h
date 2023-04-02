//
// Created by franciscocardoso on 02-04-2023.
//

#ifndef DA_PROJECT1_DRAWPATHS_H
#define DA_PROJECT1_DRAWPATHS_H
#include "iostream"
#include "../model/Graph.h"


class DrawPaths {
public:
    void draw(int maxFlow, int cost,vector<Path> path, int page)const;
    void pageController()const;
    int spacialChars(string word) const;
};


#endif //DA_PROJECT1_DRAWPATHS_H
