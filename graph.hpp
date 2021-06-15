#include <bits/stdc++.h> 

#define max_int 1000000000
using namespace std;

typedef map <string, map<string,double>> Graph; 
typedef map <string, int> st_map; 
typedef pair<double,string> ipair; 

void puffer_code(char *filename);

int iscolor(int *array,int color,int n);

int* color_graph(int **array,int *deg,int n,int e);

void record_file(int k,int e,int n,int **array,int *color);

void output_file_ColoredGraph(char *filename);

void read_file_to_create_undirected_graph(Graph& g); 

void read_file_to_create_directed_graph(Graph& g); 

void insert_vertex(Graph& g, string v); 

void insert_edge(Graph& g, string u, string v,double weight);  

Graph get_reverse_graph(Graph g); 

void DFS(Graph g, string u,st_map& visited);

void Dijkstra(Graph g, string start, string end); 

void Prim_mst(Graph g); 

void topo_sort(Graph g);