#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int visit[320][320] = {-1, };
int dy[8] = {-2, -1,2, 1,-1, 1, -2, 2 };
int dx[8] = {1, 2, 1, 2, -2, -2, -1, -1};

int bfs(pair<int, int> src, pair<int, int> dest, int n){
  if(src == dest) return 0;
  int r, c, next_row, next_col, end_x, end_y, dist = 0;
  int y, x;
  tie(y, x) = src;
  visit[y][x] = 1;
  tie(end_y, end_x) = dest;
  queue<pair<int, int> > q;
  q.push(src);
  while(!q.empty() && dist == 0) {
    tie(r, c) = q.front();
    q.pop();

    for(int i = 0; i < 8; i++) {
      int next_row = r + dy[i];
      int next_col = c + dx[i];
      if(visit[next_row][next_col] == 0) {
        visit[next_row][next_col] = visit[r][c] + 1;
        q.push({next_row, next_col});
      }
      if(next_row == end_y && next_col == end_x) dist = visit[r][c];
    }
  }
  return dist;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case, N;
  cin >> test_case;
  for(int i = 0; i < test_case; i++) {
    int n;
    cin >> n;
    memset(visit, -1, sizeof(visit));
    for(int i = 5; i < n + 5; i++) for(int j = 5; j < n+5; j++) visit[i][j] = 0;

    int src_x, src_y, dest_x, dest_y;
    cin >> src_y >> src_x;
    cin >> dest_y >> dest_x;
    pair<int, int> src = {src_y + 5, src_x + 5};
    pair<int, int> dest = {dest_y + 5, dest_x + 5};
    cout << bfs(src, dest, n) << "\n";
  }
}


