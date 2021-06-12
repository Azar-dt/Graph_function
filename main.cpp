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
        cin>>u>>v; 
        //insert_vertex(g,s); 
        insert_edge(g,u,v,1); 
        insert_edge(g,v,u,1); 
    }
    insert_vertex(g,"F"); 
    // for (auto x: g) { 
    //    // map<string,double> :: iterator ir; 
    //     for(auto y : g[x.first]) { 
    //         cout<<x.first<<" "<<y.first<<" "<<y.second<<endl;
    //     }
    // }
    Dijkstra(g,"B","J");
    st_map visited, previsit, postvisit;
    int clock_dfs = 1, cc_num = 0; 

    map <int, set<pair<int,string>>> set_cc; 
    // pair nay la ghep giua previsit va dinh dang xet
    // dung pair de ti in ra dinh theo thu thu tham 
    for(auto x: g) { 
        if(visited[x.first] == 0) {
            cc_num++;  
            DFS(g,x.first,visited,set_cc,cc_num,postvisit,clock_dfs);

        }

    }
    for( int i= 1; i<=cc_num; i++) { 
        set<pair<int,string>> :: iterator ir; 
        cout<<"CONNECTED COMPOMENT "<<i<<" : "<<endl;
        // for(ir = set_cc[i].begin(); ir!=set_cc[i].end(); ++ir) { 
        //     cout<<*ir.second<<" "<<*ir.first<<" "<<postvisit[*ir]<<endl; 
        // }
        for(auto x: set_cc[i]) { 
            cout<<x.second<<" "<<x.first<<" "<<postvisit[x.second]<<endl; 

        }
        cout<<endl; 
    }
    
    return 0  ;
}