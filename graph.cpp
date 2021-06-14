#include <bits/stdc++.h>
#include "graph.hpp"

using namespace std; 

void read_file(Graph& g) { 
    char file_name[20];  
    printf("INPUT FILE NAME : \n"); 
    scanf("%s",file_name);  
    //cout<<file_name<<endl; 
    //FILE * fi = freopen(file_name,"r",stdin) ; 
    fstream fi(file_name,ios::in); 
    //fstream()
    if (fi.fail()) { 
        cout<<"Cannot open file\n"; 
        return ; 
    }
    //fflush(stdin); 
    string u, v;
    double weight;  
    while (!fi.eof()){ 
        fi>>u>>v>>weight; 
        //insert_vertex(g,s); 
        insert_edge(g,u,v,weight); 
        insert_edge(g,v,u,weight); 
    }
    fi.close(); 
}

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

Graph get_reverse_graph(Graph g) { 
    Graph g_fake; 
    for(auto x: g) { 
        insert_vertex(g_fake,x.first); 
        for (auto y : g[x.first]) { 
            g_fake[y.first][x.first] = y.second; 
        }
    }
    return g_fake; 
}

void DFS(Graph g, string u,st_map& visited,map<int,set<pair<int,string>>> &set_cc,int cc_num,st_map& previsit, st_map& postvisit,int& clock_dfs){ 
    visited[u] = 1;
    set_cc[cc_num].insert(make_pair(clock_dfs,u));  
    previsit[u] = clock_dfs; 
    clock_dfs ++; 
    for(auto x : g[u]) { 
        if (visited[x.first] ==0 ) { 
            DFS(g,x.first,visited,set_cc,cc_num,previsit,postvisit,clock_dfs); 
        }
    }
    postvisit[u] = clock_dfs ; 
    clock_dfs ++; 
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

void Prim_mst(Graph g) { 
    priority_queue <ipair, vector<ipair> , greater<ipair>> pq; 
    string start ; 
    // lay phan tu dau tien de push vao queue 
    // ko nhat thiet la phan tu dau tien
    for(auto x: g) { 
        start = x.first; 
        break ; 
    }
    st_map inMST; 
    map <string, double> cost; 
    map <string, string> parent; 
    for(auto x:g) { 
        cost[x.first] = max_int; 
        parent[x.first] = ""; 
        inMST[x.first] = 0; 
    }
    // push phan tu dau tien vao prio_queue
    cost[start] = 0; 
    parent[start] = start; 
    pq.push(make_pair(0,start)); 
    //Gan giong Dijkstra 
    while (!pq.empty()) { 
        string u = pq.top().second; 
        pq.pop() ;

        if (inMST[u] == false) { 
            inMST[u] = true; 

            for(auto x : g[u]) { 
                string v = x.first; 
                double weight = x.second; 

                if (inMST[v]==false && cost[v]>weight) { 
                    cost[v] = weight; 
                    pq.push(make_pair(weight,v)) ; 
                    parent[v] = u; 
                } 
            }
        }

        
    }
    //cout<<start<<endl; 
    for (auto x: g) { 
        if (x.first!= start) 
            cout<<parent[x.first]<<" "<<x.first<<endl; 
    }
}