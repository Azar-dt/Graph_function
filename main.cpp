#include <bits/stdc++.h> 
#include "graph.hpp"

using namespace std; 

int main()  { 
    Graph g; 
    FILE * fi = freopen("in.txt","r",stdin) ; 
    if (fi == NULL) { 
        cout<<"Cannot open file\n"; 
        return 0; 
    }
    
    string u, v;
    double weight;  
    while (!feof(fi)){ 
        cin>>u>>v>>weight; 
        //insert_vertex(g,s); 
        insert_edge(g,u,v,weight); 
        insert_edge(g,v,u,weight); 
    }
    for (auto x: g) { 
       // map<string,double> :: iterator ir; 
        for(auto y : g[x.first]) { 
            cout<<x.first<<" "<<y.first<<" "<<y.second<<endl;
        }
    }
    Dijkstra(g,"1","4"); 
    return 0  ;
}