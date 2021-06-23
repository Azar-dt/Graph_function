#include <bits/stdc++.h> 
#include "graph.hpp"

using namespace std; 

int main()  { 
    Graph g; 
    string start,end;
    string filename;
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
        cout<<"5. TREE OF PURFER_CODE"<<endl ; 
        cout<<"6. COlOR_GRAPH ALGORITHM"<<endl ; 
        cout<<"7. TOPO_SORT ALGORITHM"<<endl;
        cout<<"8. EXIT"<<endl; 
        cout<<"CHOOSE FUNCTION : "<<endl; 
        
        cin>>func; 
        switch (func)
        {
            case 1:
                read_file_to_create_undirected_graph(g);
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
                insert_vertex(g,"F"); 
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
            case 5:
                puffer_code("tree.txt");
                cout<<endl;
                break;
            case 6:
                output_file_ColoredGraph("dothi.txt");
                break;
            case 7:
                read_file_to_create_directed_graph(g);
                topo_sort(g);
                break;
            case 8 : 
                return 0; 
        }
    }  while (1) ; 

    return 0  ;
}