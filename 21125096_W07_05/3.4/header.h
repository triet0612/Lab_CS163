#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
using namespace std;

vector<vector<int>> Load_ADJ_matrix(string filename);

void BFS(int start_v, vector<vector<int>> adj_m, vector<int> &path);

void Output_visited(vector<int> &path, string filename, int n);