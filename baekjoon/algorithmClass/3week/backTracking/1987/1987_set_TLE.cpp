#include <iostream>
#include <set>
using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int R, C;
int depth_max = 0;
string inputs[20];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
void dfs(int r, int c, set<int> passes, int depth) {
  if(r < 0 || r >= R  || c < 0 || c >= C) return;
  char current = inputs[r][c];
  if(passes.find(current - 'A') == passes.end()) {
    passes.insert(current - 'A');
    depth_max = MAX(depth, depth_max);
    for(int i = 0; i < 4; i++) {
      dfs(r + dy[i], c + dx[i], passes, depth + 1);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> R >> C;
  for(int i = 0 ; i < R; i++) {
    cin >> inputs[i];
  }
  set<int> passes;
  dfs(0, 0, passes, 1);
  cout << depth_max << "\n";
  return 0;
}
