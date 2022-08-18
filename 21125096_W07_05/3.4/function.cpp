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

void BFS(int start_v, vector<vector<int>> adj_m, vector<int> &path){
    vector<bool> visited;
    int n = adj_m.size();
    int i;
    for (i = 0; i < n; i++){
        visited.push_back(false);
    }
    vector<int> q;
    q.push_back(start_v);
    visited[start_v] = true;
    int v;
    while (q.empty() == false){
        v = q[0];
        path.push_back(v);
        q.erase(q.begin());
        for (i = 0; i < adj_m[v].size(); i++){
            if (adj_m[v][i] == 1 && visited[i] == false){
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
}

void Output_visited(vector<int> &path, string filename, int n){
    ofstream fout(filename);
    int i;
    fout << "Visited BFS path:\n";
    for (i = 0; i < n; i++){
        fout << path[i] << " ";
    }
    fout.close();
}
