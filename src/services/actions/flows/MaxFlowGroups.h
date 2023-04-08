//
// Created by ze on 06-04-2023.
//

#ifndef DA_PROJECT1_MAXFLOWGROUPS_H
#define DA_PROJECT1_MAXFLOWGROUPS_H

#include "../Action.h"
#include "../../../view/DrawUtils.h"

class MaxFlowDistricts : public Action
{
public:
  /**
   * @brief Constructor of the class MaxFlowDistricts
   * @param graph
   */
  MaxFlowDistricts(Graph &graph);

  /**
   * @brief Draws a table with the first 10 elements in data.
   * @param data - Priority queue with the districts and their max flow and cost
   * @complexity O(1)
   */
  void draw(priority_queue<pair<pair<int, int>, string>> data);

  /**
  * @brief Creates a Super Sink and connects it to all the
    stations of the district with a line with capacity INT16_MAX.
    Then it calculates the max flow and cost of the district and calls
    the draw() function so that the user can see the results.
  * @complexity O(|V|+|D|*(|V|+|E|)) being v the number of Stations, E the number of Lines and D the number of Districts
  */
  void execute() override;
};

class MaxFlowMunicipalities : public Action
{
public:
  /**
   * @brief Draws a table with the first 10 elements in data.
   * @param data - Priority queue with the municipalities and their max flow and cost
   * @complexity O(1)
   */
  void draw(priority_queue<pair<pair<int, int>, string>> data);

  /**
   * @brief Constructor of the class MaxFlowMunicipalities
   * @param graph
   */
  MaxFlowMunicipalities(Graph &graph);

  /**
  * @brief Creates a Super Sink and connects it to all the
    stations of the municipality with a line with capacity INT16_MAX.
    Then it calculates the max flow and cost of the municipality and calls
    the draw() function so that the user can see the results.
  * @complexity O(|V|+|M|*(|V|+|E|)) being v the number of Stations, E the number of Lines and M the number of Municipalities
  */
  void execute() override;
};

#endif // DA_PROJECT1_MAXFLOWGROUPS_H
