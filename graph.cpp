#include <bits/stdc++.h>
#include "graph.hpp"

using namespace std; 

//nen cay bang ma purfer-code tu file.txt
// Dòng đầu tiên thể hiện số cạnh của cây; 
// mỗi dòng tiếp theo thể hiện một cạnh của cây.

void puffer_code(char *filename){
	int i,j,n,e;
    FILE *f1=fopen(filename,"r");
    fscanf(f1,"%d",&e);
	n=e+1;
   // int a[n][2];
    int **a=(int**)malloc((n)*sizeof(int*));
    for(i=0;i<=e;i++){
        a[i]=(int*)malloc(2*sizeof(int));
    }
    int *deg=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<n;i++) deg[i]=0;
    for(i=0;i<e;i++){
        fscanf(f1,"%d\t%d\n",&a[i][0],&a[i][1]);
        for(j=1;j<=n;j++) if(j==a[i][0] || j==a[i][1]) deg[j]++;
    }
    fclose(f1);
  
    printf("ma prurfer code cua cay la:");
     for(i=1;i<n;i++){ 
		 if(deg[i]==1){
			 for(j=0;j<e;j++)
            {
                if(a[j][0]==i )
                {
                    printf("%d ",a[j][1]);
					int tmp=a[j][1];
					a[j][1]=-1;
					a[j][0]=-1;
                    deg[i]--;
                    deg[tmp]--;
                    if(deg[tmp]==1 && tmp<i && tmp!=0){
                        i=tmp;
                        break;
                    }
                }
                if(a[j][1]==i)
                {
                    printf("%d ",a[j][0]);
					int tmp=a[j][0];
					a[j][0]=-1;
					a[j][1]=-1;
                    deg[i]--;
                    deg[tmp]--;
                    if(deg[tmp]==1 && tmp<i && tmp!=0){
                        i=tmp;
                        break;
                    }
                }
            }
		 }
	   
        }
}

// to mau do thi tu file txt :
// Dòng đầu tiên ghi hai số nguyênnvàmlà số đỉnh và số cạnh của đồ thị;
// Ở m dòng tiếp theo, mỗi dòng ghi hai số nguyên tương ứng với một cạnh của đồ thị.

int iscolor(int *array,int color,int n){
    int i;
    for(i=0;i<n;i++) if(array[i]==color) return 1;
    return 0;
}
int* color_graph(int **array,int *deg,int n,int e){
    int i,j;
    int *color=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++) color[i]=0;
    for(i=1;i<=n;i++){
        int*a=(int*)malloc(deg[i]*sizeof(int));
        color[i]=1;
        int k=-1;
        for(j=1;j<=e;j++){
            if(array[j][0]==i) a[++k]=color[array[j][1]];
            if(array[j][1]==i) a[++k]=color[array[j][0]];
        }
        while(iscolor(a,color[i],deg[i])) color[i]++;
    }
    return color;
}
void record_file(int k,int e,int n,int **array,int *color){
    FILE *f1=fopen("dothi.dot","w");
    int i,j;
        fputs("graph  tree {\n",f1);
        for(i=1;i<=k;i++){
                float s1 = rand() / (float) RAND_MAX;
                float s2 = rand() / (float) RAND_MAX;
                float s3 = rand() / (float) RAND_MAX;
            for(j=1;j<=n;j++){
                if(color[j]==i) {
                    fprintf(f1,"%d[fillcolor=\"%f,%f,%f\", style=filled];\n",j,s1,s2,s3);
                }
            }
        }
        for(i=1;i<=e;i++){
            fprintf(f1,"%d--%d;\n",array[i][0],array[i][1]);
        }
        fputs("}",f1);
        fclose(f1);

}
void output_file_ColoredGraph(char *filename){
	int i,j,n,e;
    FILE *f1=fopen(filename,"r");
    fscanf(f1,"%d\t%d\n",&n,&e);
   // int a[n][2];
    int **a=(int**)malloc((e+1)*sizeof(int*));
    for(i=0;i<=e;i++){
        a[i]=(int*)malloc(2*sizeof(int));
    }
    int *deg=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++) deg[i]=0;
    for(i=1;i<=e;i++){
        fscanf(f1,"%d\t%d\n",&a[i][0],&a[i][1]);
        for(j=1;j<=n;j++) if(j==a[i][0] || j==a[i][1]) deg[j]++;
    }
    fclose(f1);

    /*for(i=1;i<=e;i++){
        printf("%d %d\n",a[i][0],a[i][1]);
    }*/
    //for(i=1;i<=n;i++) printf("%d:%d\n",i,deg[i]);

    int *color=color_graph(a,deg,n,e);
     
    //for(i=1;i<=n;i++) printf("%d\t%d\n",i,color[i]);
   
    int k=0;
    for(i=1;i<=e;i++){
        if(color[i]>k) k=color[i];
    }
     record_file(k,e,n,a,color);
}
//==========================================

void free_graph(Graph& g){
    Graph temp; 
    g = temp; 
}  

void read_file_to_create_undirected_graph(Graph& g) { 
    free_graph(g); 
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
    // string a;
    // cout<<"nhap a:";
    // cin>>a;
    // for(auto x:g[a]){
    //     cout<<x.first;
    //     cout<<endl;
    // }
}

void read_file_to_create_directed_graph(Graph& g) { 
    free_graph(g);
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

//sap xep TOPO
void topo_sort(Graph g){
    map<string,int> half_deg;
    map<string,int> nr;
    for(auto u:g){
        half_deg[u.first]=0;
    }
    for(auto u:g){
        for(auto v:g[u.first]){
            // cout<<v.first<<endl;
            half_deg[v.first]=half_deg[v.first]+1;
        }
    }
    queue<string> Q;
    for(auto v:g){
        if(half_deg[v.first]==0) Q.push(v.first);
    }
    int num=0;
    while (!Q.empty())
    {
        string u=Q.front();
        Q.pop();
        num=num+1;
        nr[u]=num;
        for(auto v:g[u]){
            half_deg[v.first]=half_deg[v.first]-1;
            if(half_deg[v.first]==0) Q.push(v.first);
        }
    }
    cout<<"Thu tu cac dinh theo sap xep TOPO la:"<<endl;
    for(int i=1;i<=num;i++){
        for(auto u:g){
            if(nr[u.first]==i) cout<<i<<":"<<u.first<<endl;
        }
    }
}