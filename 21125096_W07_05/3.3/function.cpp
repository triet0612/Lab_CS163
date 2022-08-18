#include "header.h"

vector<vector<int>> Load_ADJ_matrix(string filename){
    vector<vector<int>> matrix;
    ifstream fin(filename);
    int n;
    fin >> n;
    vector<int> temp;
    int i, j, x;
    for (i = 0; i < n; i++){
        temp.clear();
        for (j = 0; j < n; j++){
            fin >> x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    fin.close();
    return matrix;
}

void DFS(int start_v, vector<vector<int>> adj_m, bool visited[], vector<int> &path){
    path.push_back(start_v);
    visited[start_v] = true;
    int i;
    int n = adj_m[start_v].size();
    for (i = 0; i < n; i++){
        if (adj_m[start_v][i] == 1 && visited[i] == false)
            DFS(i, adj_m, visited, path);
    }
}

void Output_visited(vector<int> &path, string filename, int n){
    ofstream fout(filename);
    int i;
    fout << "Visited DFS path:\n";
    for (i = 0; i < n; i++){
        fout << path[i] << " ";
    }
    fout.close();
}
