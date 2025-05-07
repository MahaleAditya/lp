#include<iostream>
using namespace std;

void DFSrecursive(int node,int V,int adj[][100],bool visited[]){
             visited[node]=true; 
             cout<<node<<" ";
             for(int i=0;i<V;i++){
                if(adj[node][i]==1 && !visited[i])
                {
                     DFSrecursive(i,V,adj,visited);
                }
             }
}
int main(){
    int ver;
    cout<<"Enter the number of vertex: ";
    cin>>ver;

    int edge;
    cout<<"Enter the number of edge: ";
    cin>>edge;

    int adj[100][100]={0};
    cout<<"Enter the edges from start to end :\n";
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
         adj[u][v]=1;
         adj[v][u]=1;
    }
    bool visited[100]={false};
    cout<<"Dfs traversal starts from 0: ";
    DFSrecursive(0, ver,adj,visited);
}