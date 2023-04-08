//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_COMPONENTSREPORT_H
#define DA_PROJECT1_COMPONENTSREPORT_H


#include "../Action.h"
#include "../../Reports.h"

class ComponentsReport : public Action {
public:
    /**
     * @brief Construct a new Components Report object
     * 
     * @param graph graph containing all the network information
     */
    ComponentsReport(Graph &graph);
    /**
     * @brief Calculates the difference of the  sCC before and after the lines and stations being disabled
     * 
     * @param stations stations to be diabled
     * @param lines lines to be diabled
     * @param percentage percentage of completion
     * @return pair<int, int>  a pair of int being the first value the number of sCC before the stations
     *  and the lines being disabled and the second the value after
     */
    pair<int, int> doReport(Stations stations, Lines lines, int &percentage);

    
    /**
     * @brief asks the user for station and lines and displays the current sCCs
     * and the sCCs there would be if those lines/station where to be disabled
     * @complexity O(V+E) being V the number of stations and E the number of lines
     */
    void execute() override;

    /**
     * @brief displays the sCCs before and after the Stations/lines being disable
     * 
     * @param sCCs an pair with the first element being the sCCs before the Stations/lines being disable
     * and the second one being the sCCs after
     * @complexity O(1)
     */
    void draw(pair<int, int> sCCs) const;

};


#endif //DA_PROJECT1_COMPONENTSREPORT_H
