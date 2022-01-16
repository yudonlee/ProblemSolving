#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > inputs(1001);
int visit_dfs[1001] = {0, };
int visit_bfs[1001] = {0, };
int N, M, start_node;

void dfs(int node){
  if(visit_dfs[node] == 1) return;
  cout << node << " ";
  visit_dfs[node] = 1;
  for(auto it: inputs[node]) if(visit_dfs[it] == 0) dfs(it);
}
int main(){
  cin >> N >> M >> start_node; 
  int src, dest;
  for(int i = 0; i < M; i++) {
      cin >> src >> dest;
      inputs[src].push_back(dest);
      inputs[dest].push_back(src);
  }
  for(int i = 1; i <= N; i++) if(!inputs[i].empty()) sort(inputs[i].begin(), inputs[i].end());
  
  //DFS 
  dfs(start_node);
  cout << "\n";
  
  // BFS
  for(int i = start_node; i <= start_node; i++) {
    if(visit_bfs[i] == 1) continue;
    queue<int> q; 
    q.push(i);
    visit_bfs[i] = 1;
    
    while(!q.empty()){
      int current = q.front();
      cout << current << " ";
      q.pop();
      for(auto it: inputs[current]) {
        if(visit_bfs[it] == 0) {
          q.push(it);
          visit_bfs[it] = 1;
        }
      }
    }
   }
  cout << "\n";
  return 0;
}
