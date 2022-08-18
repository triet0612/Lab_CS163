#include "function.cpp"

int main(){
    int start;
    cin >> start;
    vector<vector<int>> adj = Load_ADJ_matrix("adj.txt");

    vector<int> path;
    BFS(start, adj, path);
    Output_visited(path, "path.txt", adj.size());    
    return 0;
}
