//
// Created by franciscocardoso on 16-03-2023.
//

#ifndef DA_PROJECT1_SCRAPPER_H
#define DA_PROJECT1_SCRAPPER_H
#include "fstream"
#include "sstream"
#include "iostream"
#include "string"
#include "set"
#include "main.cpp"
using  namespace std;


class Scrapper {
public:
    void scrap(Graph &graph, string vertex_file, string edge_file);
    void scrapVertexes(set<Vertex> &vertexes_set, string vertex_file);
    void scrapEdges(set<Vertex> &vertexes_set, string vertex_file);
    void getValue(string &value, istringstream &data);

};


#endif //DA_PROJECT1_SCRAPPER_H
