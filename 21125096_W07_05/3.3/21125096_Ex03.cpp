#include "function.cpp"

int main(){
    int start;
    cin >> start;
    vector<vector<int>> adj = Load_ADJ_matrix("adj.txt");

    bool *visited = new bool[adj.size()];
    int i;
    for (i = 0; i < adj.size(); i++){
        visited[i] = false;
    }
    vector<int> path;
    DFS(start, adj, visited, path);
    Output_visited(path, "path.txt", adj.size());
    
    delete[]visited;
    return 0;
}
