#include <bits/stdc++.h> 
#include "graph.hpp"

using namespace std; 

int main()  { 
    Graph g; 
    string start,end;
    int func; 
    st_map visited, previsit, postvisit;
    int clock_dfs = 1, cc_num = 0; 

    map <int, set<pair<int,string>>> set_cc; 
    // pair nay la ghep giua previsit va dinh dang xet
    // dung pair de ti in ra dinh theo thu thu tham 
    do { 
        fflush(stdin); 
        cout<<"\tGRAPH FUNCTION :\t\t"<<endl; 
        cout<<"1. READ FILE, INIT GRAPH"<<endl;
        cout<<"2. DIJKSTRA ALGORITHM"<<endl; 
        cout<<"3. PRIM MST ALGORITHM"<<endl ; 
        cout<<"4. DFS FIND CONNECTED COMPOMENT"<<endl ; 
        cout<<"5. EXIT"<<endl; 
        cout<<"CHOOSE FUNCTION : "<<endl; 
        
        cin>>func; 
        switch (func)
        {
            case 1:
                read_file(g);
                break;
            case 2: 
                cout<<"INPUT 2 VERTEX U WANT TO FIND PATH"<<endl;
                cin>>start;
                cin>>end; 
                Dijkstra(g,start,end); 
                break;
            case 3: 
                cout<<"PRIM ALGORITHM : "<<endl ; 
                Prim_mst(g); 
                break; 
            case 4: 
                for(auto x: g) { 
                    if(visited[x.first] == 0) {
                        cc_num++;  
                        DFS(g,x.first,visited,set_cc,cc_num,previsit,postvisit,clock_dfs);

                    }

                }
                for( int i= 1; i<=cc_num; i++) { 
                    //set<pair<int,string>> :: iterator ir; 
                    cout<<"CONNECTED COMPOMENT "<<i<<" : "<<endl;
                    
                    for(auto x: set_cc[i]) { 
                        cout<<x.second<<" "<<x.first<<" "<<postvisit[x.second]<<endl; 

                    }
                    cout<<endl; 
                }
                break; 
            case 5 : 
                return 0; 
        }
    }  while (1) ; 
    
    //read_file(g); 
    //insert_vertex(g,"F"); 
    //Graph g_fake = get_reverse_graph(g);

    // for (auto x: g_fake) { 
    //     cout<<x.first<<endl; 
    //     for(auto y : g_fake[x.first]) { 
    //         cout<<x.first<<" "<<y.first<<" "<<y.second<<endl;
    //     }
    // }
    /*
    read_file(g);
    
    // DFS 
    
    for(auto x: g) { 
        if(visited[x.first] == 0) {
            cc_num++;  
            DFS(g,x.first,visited,set_cc,cc_num,previsit,postvisit,clock_dfs);

        }

    }
    for( int i= 1; i<=cc_num; i++) { 
        //set<pair<int,string>> :: iterator ir; 
        cout<<"CONNECTED COMPOMENT "<<i<<" : "<<endl;
        // for(ir = set_cc[i].begin(); ir!=set_cc[i].end(); ++ir) { 
        //     cout<<*ir.second<<" "<<*ir.first<<" "<<postvisit[*ir]<<endl; 
        // }
        for(auto x: set_cc[i]) { 
            cout<<x.second<<" "<<x.first<<" "<<postvisit[x.second]<<endl; 

        }
        cout<<endl; 
    }
    
    // DIJKSTRA 
    cout<<"DIJKSTRA ALGORITHM  : "<<endl;
    cout<<"NHAP 2 DINH CAN TIM DUONG DI : "<<endl; 
    string start,end; 
    cin>>start>>end; 
    Dijkstra(g,start,end);

    cout<<"PRIM ALGORITHM : "<<endl ; 
    Prim_mst(g); 
    */
    return 0  ;
}