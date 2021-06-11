#include <bits/stdc++.h>
#include "graph.hpp"

using namespace std; 

void insert_vertex(Graph& g, string v) { 
    //Graph :: iterator ir; 
    if (g.find(v) == g.end()) { 
        map <string,double> temp; 
        g[v] = temp; 
    }
}

void insert_edge(Graph& g, string u, string v, double weight) { 
    g[u][v] = weight; 
}

void Dijkstra(Graph g, string start, string end) { 
    // tao min_heap
    priority_queue <ipair, vector<ipair> , greater<ipair>> pq; 
    map <string, string> prev; 
    map <string, double> dist; 

    for(auto x: g) { 
        prev[x.first] = ""; 
        if (x.first == start) dist[x.first] = 0;
        else  
            dist[x.first] = max_int; 
        pq.push(make_pair(dist[x.first], x.first)); 
    }
    bool kt = false; 
    while (!pq.empty()){ 
        string u = pq.top().second; 
        pq.pop(); 
        
        for(auto ir : g[u]) {
            string v = ir.first;   
            double new_weight = dist[u] + g[u][v]; 
            if (dist[v] > new_weight) { 
                dist[v] = new_weight; 
                pq.push(make_pair(new_weight, v)); 

                prev[v] = u ;
            }
            if (v == end) {
                kt = true; 
            }
        }
    }
    if (kt == false ) cout<<"No path \n";  
    else { 
        cout<<"Path founded, shortest path is : "<<endl; 
        stack <string> path; 
        string temp = end; 
        while (prev[temp]!="") {
              
            temp = prev[temp]; 
            path.push(temp);
        }
         
        while (!path.empty()) { 
            cout<<path.top()<<"-->"; 
            path.pop(); 
        }
        cout<<end<<endl; 
    }

}