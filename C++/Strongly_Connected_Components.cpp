// strongly Connected Components using Tarjan's Algorithm

// single pass algorithm

// Time Complexity -> O(V + E)
// Space Complexity -> O(N)

#include<bits/stdc++.h>

void dfs(int sv, vector<int> adj[], vector<int>& tin, vector<int>& low, vector<bool>& inStack, stack<int>&st, vector<vector<int>>& res)
{
  static int timer = 0;
  
  tin[sv] = low[sv] = timer;

  ++timer;

  st.push(sv);

  inStack[sv] = true;

  for(auto itr : adj[sv])
  {
    if(tin[itr] == -1)
    {
      dfs(itr, adj, tin, low, inStack, st, res);
      low[sv] = min(low[sv], low[itr]);
    }
    else if(inStack[itr])
    {
      // if node is visited and
      // if node is present in stack that means it is a back edge and if it is not present in stack
      // it is cross edge and we will do not consider cross edges.

      low[sv] = min(low[sv], tin[itr]);
    }
  }

  // if low[sv] == tin[sv] that means it is head node of the strong connected commonent

  if(low[sv] == tin[sv])
  {
    vector<int> scc;
    
    while(st.top() != sv)
    {
      scc.push_back(st.top());
      inStack[st.top()] = false;
      st.pop();
    }
    
    scc.push_back(sv);
    inStack[st.top()] = false;
    st.pop();

    res.push_back(scc);
  }
  
}

vector<vector<int>> TarjansAlgorithm(vector<int> adj[], int n)
{
  vector<vector<int>> res;
  
  vector<int> tin(n,-1), low(n,-1);

  vector<bool> inStack(n, false);

  stack<int> st;

  for(int i = 0; i < n; ++i)
  {
    if(tin[i] == -1)
      dfs(i, adj, tin, low, inStack, st, res);
  }
  
  return res;
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.

    vector<int> adj[n+1];

    for(auto& itr : edges)
    {
      adj[itr[0]].push_back(itr[1]);
    }
    
    return TarjansAlgorithm(adj, n);
}

// Kosaraju's Algorithm

// Time Complexity -> O(2(V+E))
// Space Complexity -> O(N)

#include <bits/stdc++.h>

void dfs(int sv, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
  visited[sv] = true;

  for (auto itr : adj[sv]) {
    if (!visited[itr])
      dfs(itr, adj, visited, st);
  }

  st.push(sv);
}

void dfs2(int sv, vector<int> revAdj[], vector<bool> &visited,
          vector<int> &scc) {
  scc.push_back(sv);
  visited[sv] = true;

  for (auto itr : revAdj[sv]) {
    if (!visited[itr])
      dfs2(itr, revAdj, visited, scc);
  }
}

vector<vector<int>> stronglyConnectedComponents(int n,
                                                vector<vector<int>> &edges) {
  // Write your code here.

  vector<vector<int>> res;

  vector<int> adj[n + 1];

  for (auto itr : edges) {
    int u = itr[0];
    int v = itr[1];

    adj[u].push_back(v);
  }

  vector<bool> visited(n + 1, false);

  stack<int> st;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i, adj, visited, st);
    }
  }

  vector<int> revAdj[n + 1];

  for (int i = 0; i < n; ++i) {
    visited[i] = 0;
    for (auto itr : adj[i]) {
      revAdj[itr].push_back(i);
    }
  }

  while (!st.empty()) {
    int node = st.top();
    st.pop();

    if (!visited[node]) {
      vector<int> scc;
      dfs2(node, revAdj, visited, scc);

      if (!scc.empty()) {
        sort(scc.begin(), scc.end());
        res.push_back(scc);
      }
    }
  }

  return res;
}
