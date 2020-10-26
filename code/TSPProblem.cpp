#include <bits/stdc++.h>
using namespace std;
#define V 4
 
// implementation of traveling Salesman Problem
int tspSolution(int graph[][V], int s)
{
    vector<int> nodes;
    for (int i = 0; i < V; i++)
        if (i != s)
            nodes.push_back(i);
 
    int min_path = INT_MAX;
    do {
 
        // store current Path weight(cost)
        int current_pathweight = 0;
 
        // compute current path weight
        int k = s;
        for (int i = 0; i < nodes.size(); i++) {
            current_pathweight += graph[k][nodes[i]];
            k = nodes[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(nodes.begin(), nodes.end()));
 
    return min_path;
}
 
int main()
{
    int graph[][V] = { { 0, 3, 6, 7 },
                       { 12, 0, 2, 8 },
                       { 8, 6, 0, 2 },
                       { 3, 7, 6, 0 } };
    int s = 0;
    cout << tspSolution(graph, s) << endl;
    return 0;
}