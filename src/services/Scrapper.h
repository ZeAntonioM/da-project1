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

#include "../model/Graph.h"
#include "../model/StationLine.h"

using namespace std;


class Scrapper {
public:
    /**
     * @brief Scrapes the information from the stations and the stations and the lines and stores it in the graph
     * @param graph graph were all the information is going to be store
     * @param station_file the file containing the stations
     * @param line_file the file containing the lines
     * @complexity O(V+E) being V the number of stations and E the number of lines that exists
     */
    void scrape(Graph &graph, string station_file, string line_file);

    /**
     * @brief Scrapes the information from the stations and stores it in the graph
     * @param graph graph were all the information is going to be store
     * @param station_file the file containing the stations
     * @complexity O(V) being V the number of stations that exists
     */
    void scrapeStations(Graph &graph, string station_file);

    /**
     * @brief Scrapes the information from the lines and stores it in the graph
     * @param graph graph were all the information is going to be store
     * @param line_file the file containing the lines
     * @complexity O(E) being E the number of lines that exists
     */
    void scrapeLines(Graph &graph, string line_file);

    /**
     * @brief gets the data from the files checking for error and especial cases
     * @param value where the data is going to be store
     * @param data the line of the file conating the information
     * @complexity O(1)
     */
    void getValue(string &value, istringstream &data);

};


#endif //DA_PROJECT1_SCRAPPER_H
