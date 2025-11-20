#include <iostream>
#include <queue>
#include <vector>

std::vector <int> BFS(int v,std::vector <int> adj[]){  // v is no of nodes
    int vis[v] = {0};  //visited array
    vis[0] = 1;
    
    std::vector <int> trav;
    std::queue <int> q;
    q.push(0);
    
    while (!q.empty())
    {
        int temp  = q.front();
        q.pop();
        trav.push_back(temp);
        for(auto x:adj[temp])
        {
            if(vis[x]==1){
                continue;
            }
            q.push(x);
            vis[x] = 1;
        }
    }
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
    std::vector <int> x =BFS(n,adj);
    for (auto i:x)
    {
        std::cout<<i<<" ";
    }
    return 0;
}