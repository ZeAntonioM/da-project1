#ifndef DA_PROJECT1_COMPONENTSREPORT_H
#define DA_PROJECT1_COMPONENTSREPORT_H

#include "../Action.h"
#include "../../Reports.h"

class ComponentsReport : public Action
{
public:
    /**
     * pair of ints, the first value represents the number of strongly connected components
     * before the lines/stations where disabled and the second the amount after
     */
    typedef pair<int, int> CompResults;
    /**
     * @brief Construct a new Components Report object
     *
     * @param graph graph containing all the network information
     */
    ComponentsReport(Graph &graph);
    /**
     * @brief Calculates the difference of the  Strongly Connected Components before and after the lines
     * and stations being disabled
     *
     * @param stations stations to be disabled
     * @param lines lines to be disabled
     * @param percentage percentage of completion
     * @return CompResults  a pair of int being the first value the number of Strongly Connected Component before the stations
     * and the lines being disabled and the second the value after
     * @brief Complexity O( |V| + |E| ) being V the Stations and E the lines in the graph
     */
    CompResults doReport(Stations stations, Lines lines, int &percentage);

    /**
     * @brief asks the user for station and lines and displays the current Strongly Connected Components
     * and the Strongly Connected Components there would be if those lines/station where to be disabled
     * @brief Complexity O(V+E) being V the number of stations and E the number of lines
     */
    void execute() override;

    /**
     * @brief displays the Strongly Connected Components before and after the Stations/lines being disable
     *
     * @param sCCs an pair with the first element being the Strongly Connected Component before the
     * Stations/lines being disable
     * and the second one being the Strongly Connected Components after
     * @brief Complexity O(1)
     */
    void draw(CompResults sCCs) const;
};

#endif // DA_PROJECT1_COMPONENTSREPORT_H
