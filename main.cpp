#include "Graph_Adjacency_list.hpp"

int main()
{
    Graph a(7);

    // a.add_edge(5, 6);
    // a.add_edge(4, 5);
    // a.add_edge(3, 5);
    // a.add_edge(2, 4);
    // a.add_edge(1, 4);
    // a.add_edge(1, 3);
    // a.add_edge(0, 2);
    // a.add_edge(0, 1);

    a.add_edge(0, 1);
    a.add_edge(0, 2);
    a.add_edge(1, 3);
    a.add_edge(1, 4);
    a.add_edge(2, 4);
    a.add_edge(3, 5);
    a.add_edge(4, 5);
    a.add_edge(5, 6);

    a.print_graph();

    a.depth_first_search(0);

    return 0;
}