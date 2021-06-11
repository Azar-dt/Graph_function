#include <bits/stdc++.h> 

#define max_int 1000000000
using namespace std;

typedef map <string, map<string,double>> Graph; 
typedef pair<double,string> ipair; 

void insert_vertex(Graph& g, string v); 

void insert_edge(Graph& g, string u, string v,double weight);  

void Dijkstra(Graph g, string start, string end); 