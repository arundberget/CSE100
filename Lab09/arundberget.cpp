#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void DFS(vector<int>* G, bool* seen, stack<int>& s, int v){ // performs dfs on the graph
  seen[v] = true;
  for(int i = 0; i < G[v].size(); i++){
    int next = G[v][i];
    if(!seen[next]){
      DFS(G, seen, s, next);
    }
  }
  s.push(v); // push vertex onto stack when finished
}

void DFS2(vector<int>* G, bool* seen, vector<int>& scc, int v){ // finds scc in the graph
  seen[v] = true;
  scc.push_back(v);
  for(int i = 0; i < G[v].size(); i++){
    int next = G[v][i];
    if(!seen[next]){
      DFS2(G, seen, scc, next);
    }
  }
}

int main(){

  int V; // no. of vertices
  int E; // no. of edges
  cin>>V;
  cin>>E;

  vector<int>* G = new vector<int>[V];
  for(int i = 0; i < E; i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v); // adds edge
  }

  vector<int>* GT = new vector<int>[V];
  for(int i = 0; i < V; i++){
    for(int j = 0; j < G[i].size(); j++){
      int u = i;
      int v = G[i][j];
      GT[v].push_back(u);
    }
  }

  bool* seen1 = new bool[V];
  stack<int> s;
  for (int i = 0; i < V; i++) {
    seen1[i] = false;
  }
  for(int i = 0; i < V; i++){
    if(!seen1[i]){
      DFS(G, seen1, s, i);
    }
  }
  
  // use Kosaraju's alorithm to find sccs
  bool* seen2 = new bool[V];
  int* res = new int[V];
  while (!s.empty()) {
    int v = s.top();
    s.pop();
    if (!seen2[v]) {
      vector<int> scc;
      DFS2(GT, seen2, scc, v);
      int sccid = v;
      for (int i = 0; i < scc.size(); i++) {
        int u = scc[i];
          sccid = min(sccid, u);
      }
      for (int i = 0; i < scc.size(); i++) {
        int u = scc[i];
          res[u] = sccid;
      }
    }
  }
  
  // print scc ids
  for(int i = 0; i < V; i++){
    cout << res[i] << endl;
  }

  delete[] seen1;
  delete[] seen2;
  delete[] res;
  delete[] G;
  delete[] GT;

  return 0;
}
