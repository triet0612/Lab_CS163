#include "function.cpp"

int main(){
    vector<vector<int>> adj = Load_ADJ_matrix("adj.txt");
    OutputConcomp("concomp.txt", ConnectedComp(adj));
    return 0;
}
