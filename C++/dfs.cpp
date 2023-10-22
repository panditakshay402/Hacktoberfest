#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int> adj[], int vis[], vector<int> &list){
    vis[node] = 1;
    list.push_back(node);

    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, list);
        }
    }
}

vector<int> dfsofG(int V, vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;
    vector<int>list;
    dfs(start, adj, vis, list);
    return list;


}
void addEdge(vector <int> adj[], int u, int  v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    vector <int> adj[5];
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    vector<int>ans = dfsofG(5, adj);
    printAns(ans);

    return 0;


}
