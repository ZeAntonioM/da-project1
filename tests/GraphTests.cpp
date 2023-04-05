//
// Created by franciscocardoso on 19-03-2023.
//

#include "GraphTests.h"
#include "../src/model/Graph.h"

using namespace std;
void GraphTests::run() {
    system("clear");
    Graph myGraph2;

    myGraph2.addStation(new Station("a"));
    myGraph2.addStation(new Station("b"));
    myGraph2.addStation(new Station("c"));
    myGraph2.addStation(new Station("d"));
    myGraph2.addStation(new Station("e"));
    myGraph2.addStation(new Station("f"));
    myGraph2.addStation(new Station("g"));
    myGraph2.addStation(new Station("h"));
    myGraph2.addBidirectionalLine(myGraph2.findStation("a"), myGraph2.findStation("b"), 3,ALFA);
    myGraph2.addBidirectionalLine(myGraph2.findStation("a"), myGraph2.findStation("c"), 2,STANDARD);
    myGraph2.addBidirectionalLine(myGraph2.findStation("b"), myGraph2.findStation("e"), 1,STANDARD);
    myGraph2.addBidirectionalLine(myGraph2.findStation("b"), myGraph2.findStation("d"), 1,ALFA);
    myGraph2.addBidirectionalLine(myGraph2.findStation("c"), myGraph2.findStation("d"), 2,ALFA);
    myGraph2.addBidirectionalLine(myGraph2.findStation("c"), myGraph2.findStation("e"), 1,STANDARD);
    myGraph2.addBidirectionalLine(myGraph2.findStation("d"), myGraph2.findStation("f"), 6,STANDARD);
    myGraph2.addBidirectionalLine(myGraph2.findStation("e"), myGraph2.findStation("f"), 1,ALFA);
    myGraph2.addBidirectionalLine(myGraph2.findStation("d"), myGraph2.findStation("g"), 1,STANDARD);
    myGraph2.addBidirectionalLine(myGraph2.findStation("g"), myGraph2.findStation("h"), 1,STANDARD);
    myGraph2.addBidirectionalLine(myGraph2.findStation("h"), myGraph2.findStation("f"), 1,STANDARD);

    pair<int,int> p;
    pair<int,int> m;
    string ss;
    cout<<"\nTest number 1\n\n";
    cout<<"Normal maxFlow:\n";
    m=myGraph2.maxFlow("a","f");
    for(auto v : myGraph2.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;
    cout<<"Max flow: "<<m.first<<"- Cost:"<<m.second<<endl;
    cout<<"\nMinimum cost max flow: \n\n";
    p=myGraph2.cheapestMaxFlow("a","f");
    ss="";
    for(auto v : myGraph2.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;

    cout<<"Maximum flow: "<<p.first<<" - Cost: "<<p.second<<endl;
    if(m.first==p.first and m.second>=p.second) cout<<"Passed!\n";
    else cout<<"Failed!";
    /*for( Path path: myGraph2.getPaths("a","f")){
        cout<<"Flow "<<path.second<<endl;
        for(StationPair stationPair: path.first){
            cout<<stationPair.first->getName()<<" -> "<<stationPair.second->getName()<<endl;
        }
    }*/

    Graph myGraph3;

    myGraph3.addStation(new Station("a"));
    myGraph3.addStation(new Station("b"));
    myGraph3.addStation(new Station("c"));
    myGraph3.addStation(new Station("d"));
    myGraph3.addStation(new Station("e"));
    myGraph3.addBidirectionalLine(myGraph3.findStation("a"), myGraph3.findStation("b"), 3,STANDARD);
    myGraph3.addBidirectionalLine(myGraph3.findStation("b"), myGraph3.findStation("c"), 3,ALFA);
    myGraph3.addBidirectionalLine(myGraph3.findStation("b"), myGraph3.findStation("d"), 3,STANDARD);
    myGraph3.addBidirectionalLine(myGraph3.findStation("c"), myGraph3.findStation("e"), 3,ALFA);
    myGraph3.addBidirectionalLine(myGraph3.findStation("d"), myGraph3.findStation("e"), 3,STANDARD);

    cout<<"\nTest number 2\n\n";
    cout<<"Normal maxFlow:\n";
    m=myGraph3.maxFlow("a","e");
    for(auto v : myGraph2.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;
    cout<<"Max flow: "<<m.first<<"- Cost:"<<m.second<<endl;
    cout<<"\nMinimum cost max flow: \n";
    p=myGraph3.cheapestMaxFlow("a","e");
    ss="";
    for(auto v : myGraph2.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;

    cout<<"Maximum flow: "<<p.first<<" - Cost: "<<p.second<<endl;
    if(m.first==p.first and m.second>=p.second) cout<<"Passed!\n";
    else cout<<"Failed!";

    Graph myGraph4;

    myGraph4.addStation(new Station("a"));
    myGraph4.addStation(new Station("b"));
    myGraph4.addStation(new Station("c"));
    myGraph4.addStation(new Station("d"));
    myGraph4.addStation(new Station("e"));
    myGraph4.addStation(new Station("f"));
    myGraph4.addStation(new Station("g"));
    myGraph4.addStation(new Station("h"));
    myGraph4.addBidirectionalLine(myGraph4.findStation("a"), myGraph4.findStation("b"), 5,ALFA);
    myGraph4.addBidirectionalLine(myGraph4.findStation("a"), myGraph4.findStation("c"), 2,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("b"), myGraph4.findStation("e"), 3,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("b"), myGraph4.findStation("d"), 4,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("c"), myGraph4.findStation("d"), 5,ALFA);
    myGraph4.addBidirectionalLine(myGraph4.findStation("c"), myGraph4.findStation("e"), 5,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("d"), myGraph4.findStation("f"), 6,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("e"), myGraph4.findStation("f"), 3,ALFA);
    myGraph4.addBidirectionalLine(myGraph4.findStation("d"), myGraph4.findStation("g"), 1,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("g"), myGraph4.findStation("h"), 1,STANDARD);
    myGraph4.addBidirectionalLine(myGraph4.findStation("h"), myGraph4.findStation("f"), 10,ALFA);

    ss="";
    cout<<"\nTest number 3\n\n";
    cout<<"Normal maxFlow:\n";
    m=myGraph4.maxFlow("a","f");
    for(auto v : myGraph4.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;
    cout<<"Max flow: "<<m.first<<"- Cost:"<<m.second<<endl;
    cout<<"\nMinimum cost max flow: \n\n";
    p=myGraph4.cheapestMaxFlow("a","f");
    ss="";
    for(auto v : myGraph4.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;

    cout<<"Maximum flow: "<<p.first<<" - Cost: "<<p.second<<endl;
    if(m.first==p.first and m.second>=p.second) cout<<"Passed!\n";
    else cout<<"Failed!";

    Graph myGraph5;

    myGraph5.addStation(new Station("a"));
    myGraph5.addStation(new Station("b"));
    myGraph5.addStation(new Station("c"));
    myGraph5.addStation(new Station("d"));

    myGraph5.addBidirectionalLine(myGraph5.findStation("a"), myGraph5.findStation("b"), 5,ALFA);
    myGraph5.addBidirectionalLine(myGraph5.findStation("a"), myGraph5.findStation("c"), 2,STANDARD);
    myGraph5.addBidirectionalLine(myGraph5.findStation("a"), myGraph5.findStation("d"), 3,STANDARD);
    myGraph5.addBidirectionalLine(myGraph5.findStation("b"), myGraph5.findStation("c"), 4,STANDARD);
    myGraph5.addBidirectionalLine(myGraph5.findStation("b"), myGraph5.findStation("d"), 5,ALFA);
    myGraph5.addBidirectionalLine(myGraph5.findStation("c"), myGraph5.findStation("d"), 5,STANDARD);

    cout<<"\nTest number 5\n\n";
    cout<<"Normal maxFlow:\n";

    m=myGraph5.maxFlow("a","d");
    for(auto v : myGraph5.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;
    cout<<"Max flow: "<<m.first<<"- Cost:"<<m.second<<endl;
    cout<<"\nMinimum cost max flow: \n\n";
    p=myGraph5.cheapestMaxFlow("a","d");
    ss="";
    for(auto v : myGraph5.getStationSet()) {
        ss += v->getName() + "-> (";
        for ( auto e : v->getAdj())
            ss += (e->getDest())->getName() + "[Flow: " + to_string((int)e->getFlow()) + "] ";
        ss += ") || ";
    }
    cout<<ss<<endl;

    cout<<"Maximum flow: "<<p.first<<" - Cost: "<<p.second<<endl;
    if(m.first==p.first and m.second>=p.second) cout<<"Passed!\n";
    else cout<<"Failed!";

}
