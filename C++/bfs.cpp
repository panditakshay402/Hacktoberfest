#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

vector<int> bfsofG(int V, vector<int> adj[]){
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;

    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

       for(auto it: adj[node]){
        if(!vis[it]){
            vis[it] = 1;
            q.push(it);
        }
       } 
    }

    return bfs;
    
}


void AddEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    vector <int> adjo[6];
    AddEdge(adjo, 0, 1);
    AddEdge(adjo, 1, 2);
    AddEdge(adjo, 1, 3);
    AddEdge(adjo, 0, 4);

 

     vector <int> ans = bfsofG(5,adjo);
printAns(ans);

}
