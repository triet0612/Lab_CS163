#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<vector<int>> Load_ADJ_matrix(string filename);

void DFS(int start_v, vector<vector<int>> adj_m, bool visited[], vector<int> &path);

void ConnectedComp();

void OutputConcomp(string filename, vector<vector<int>> ConnectedComp);
