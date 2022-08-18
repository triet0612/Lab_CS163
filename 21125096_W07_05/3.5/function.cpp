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

vector<vector<int>> ConnectedComp(vector<vector<int>> adj_m){
    vector<vector<int>> concomp;
    int i;
    int size = adj_m.size();
    bool* visited = new bool[size];
    vector<int> path;
    
    for (i = 0; i < size; i++)
        visited[i] = false;

    for (i = 0; i < size; i++){
        if (!visited[i]){
            path.clear();
            DFS(i, adj_m, visited, path);
            concomp.push_back(path);
        }
    }
    delete[]visited;
    return concomp;
}

void OutputConcomp(string filename, vector<vector<int>> ConnectedComp){
    ofstream fout(filename);
    fout << ConnectedComp.size() << endl;
    vector<vector<int>>::iterator i;
    vector<int>::iterator j;
    for (i = ConnectedComp.begin(); i < ConnectedComp.end(); i++){
        for (j = (*i).begin(); j < (*i).end(); j++){
            fout << *j << " ";
        }
        fout << endl;
    }
}
