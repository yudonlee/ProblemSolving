#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > inputs(1001);
int visit[1001] = {0, };
int N, M, start_node;
void dfs(int node){
  if(visit[node] == 1) return;
  visit[node] = 1;
  for(auto it: inputs[node]) if(visit[it] == 0) dfs(it);
}
int main(){
  cin >> N >> M;
  int src, dest, count = 0;
  for(int i = 0; i < M; i++) {
      cin >> src >> dest;
      inputs[src].push_back(dest);
      inputs[dest].push_back(src);
  }
  for(int i = 1; i <= N; i++) if(!inputs[i].empty()) sort(inputs[i].begin(), inputs[i].end());
  
  //DFS
  for(int i = 1; i <= N; i++) {
    if(visit[i] == 0){
      dfs(i);
      count++;
    }
  }
  cout << count << "\n";
  return 0;
}
