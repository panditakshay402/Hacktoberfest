#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  int num;
  int comp;
  vector<int> size, par;
  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) { iota(par.begin(), par.end(), 0); }
  int find(int x) {
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }
 
  int operator[](int x) {
    return find(x);
  }
 
  bool merge(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    comp--;
    if (size[x] < size[y]) swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }
 
  vector<int> find_all() {
    vector<int> A(num);
    for(int i=0;i<num;i++){
        A[i] = find(i);
    }
    return A;
  }
};
