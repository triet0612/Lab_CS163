#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Vertex {
    int label;
    int weight;
};

struct Graph{
    int size;
    vector<vector<Vertex>> Adj_list;
    Graph(int n) {
        size = n;
    }
};

void Dijstra(Graph Gr, vector<int> dist, vector<int> prev, int start_v);
