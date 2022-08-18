#include "header.h"

void Dijstra(Graph Gr, vector<int> distance, vector<int> prev, int start_v) {
    int n = Gr.size;
    int i;
    for (i = 0; i < n; i++) {
        distance.push_back(INT_MAX);
        prev.push_back(-1);
    }
    distance[start_v] = 0;
    list<int> queue;
    for (i = 0; i < n; i++) {
        queue.push_back(i);
    }
    while (!queue.empty())
    {
        list<int>:: iterator itr;   
        itr = min_element(queue.begin(), queue.end());
        int curMin = *itr;
        queue.remove(curMin);
        for (auto i : Gr.Adj_list[curMin]) {
            if (distance[curMin] + i.weight < distance[i.label]) {
                distance[i.label] = distance[curMin] + i.label;
                prev[i.label] = curMin;
            }
        }
    }
}
