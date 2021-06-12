#include <bits/stdc++.h> 

#define max_int 1000000000
using namespace std;

typedef map <string, map<string,double>> Graph; 
typedef map <string, int> st_map; 
typedef pair<double,string> ipair; 

void insert_vertex(Graph& g, string v); 

void insert_edge(Graph& g, string u, string v,double weight);  

void DFS(Graph g, string u,st_map& visited,map<int,set<pair<int,string>>> &set_cc,int cc_num,st_map& postvisit,int& clock_dfs);

void Dijkstra(Graph g, string start, string end); 