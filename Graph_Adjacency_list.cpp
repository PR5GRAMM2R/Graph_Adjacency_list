#include "Graph_Adjacency_list.hpp"
#include <cassert>
#include <iostream>
#include <stack>
#include <queue>

Graph::Graph(int n)
{
    assert(n > 0);

    adjacencyList.resize(n);
    size = n;
}

Graph::~Graph()
{
    adjacencyList.resize(0);
    size = 0;
}

void Graph::add_edge(int source, int target)
{
    assert(source >= 0 && source < size);
    assert(target >= 0 && target < size);

    list<int>::iterator it;

    for(it = adjacencyList[source].begin(); it != adjacencyList[source].end(); it++){
        if(*it == target){
            cout << source << " 와 " << target << " 사이의 edge 가 이미 있습니다." << endl;
            return;
        }
    }

    adjacencyList[source].push_back(target);
    adjacencyList[target].push_back(source);

    return;
}

void Graph::remove_edge(int source, int target)
{
    assert(source >= 0 && source < size);
    assert(target >= 0 && target < size);

    list<int>::iterator it;
    bool erased = false;

    for(it = adjacencyList[source].begin(); it != adjacencyList[source].end(); it++){
        if(*it == target){
            adjacencyList[source].erase(it);
            erased = true;
            break;
        }
    }

    for(it = adjacencyList[target].begin(); it != adjacencyList[target].end(); it++){
        if(*it == source){
            adjacencyList[target].erase(it);
            erased = true;
            break;
        }
    }

    if(erased == false)
        cout << source << " 와 " << target << " 사이의 edge 가 없습니다." << endl;

    return;
}

void Graph::print_graph()
{
    list<int>::iterator lit;

    cout << "\n------ Adjacency List -----" << endl;

    for(int i = 0; i < size; i++){
        cout << i << " : ";

        for(lit = adjacencyList[i].begin(); lit != adjacencyList[i].end(); lit++){
            cout << *lit << " ";
        }

        cout << endl;
    }

    cout << "---------------------------\n" << endl;

    return;
}

void Graph::depth_first_search(int start)
{
    stack<int> visited_mem;
    bool visited[size] = { false };

    visited_mem.push(start);
    visited[start] = true;
    cout << "depth_first_search : " << start << " ";
    list<int>::iterator lit;
    bool goNext = false;

    while(!visited_mem.empty()){
        for(lit = adjacencyList[visited_mem.top()].begin(); lit != adjacencyList[visited_mem.top()].end(); lit++){
            if(visited[*lit] == false){
                visited[*lit] = true;
                cout << *lit << " ";
                visited_mem.push(*lit);
                goNext = true;
                break;
            }
        }

        if(goNext == true){
            goNext = false;
            continue;
        }

        visited_mem.pop();
    }

    cout << endl;

    return;
}

void Graph::breadth_first_search(int start)
{
    
}

void Graph::dijkstra_algorithm(int start)
{
    
}