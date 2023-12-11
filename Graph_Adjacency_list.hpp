#ifndef __GRAPH_ADJACENCY_LIST__
#define __GRAPH_ADJACENCY_LIST__

#include <vector>
#include <list>

using namespace std;

class Graph{
    private :
        vector<list<int>> adjacencyList;
        int size;
    
    public :
        Graph(int n);
        ~Graph();

        void add_edge(int source, int target);
        void remove_edge(int source, int target);
        void print_graph();

        void depth_first_search(int start);
        void breadth_first_search(int start);

        void dijkstra_algorithm(int start);
};

#endif