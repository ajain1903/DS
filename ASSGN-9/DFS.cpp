#include <iostream>
#include <vector>

void DFS(int node,std::vector <int> adj[],int vis[],std::vector <int> &trav ){ //reference of vis is also needed so use vector for it
    vis[node] = 1;
    trav.push_back(node);

    // traversing depth by recursion
    for (auto x:adj[node])
    {   
        if(vis[x]!=1){
        DFS(x,adj,vis,trav);
        }
    }
    return;
}
std::vector <int> DFS(int nodes,std::vector <int> adj[]){
    int vis[nodes] = {0};  //visited array
  //std::vector <int> vis(nodes,0)  // this is needed to take a reference of the visited array
      
    std::vector <int> trav;
    int start = 0;
    DFS(start,adj,vis,trav);
    return trav;
}
int main(){
    //storing graph using vector array
    int n;
    std::cin>>n; //no of nodes of the graph
    int m;
    std::cin>>m; // no of edges
    std::vector <int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        std::cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector <int> x =DFS(n,adj);
    for (auto i:x)
    {
        std::cout<<i<<" ";
    }
    return 0;
}