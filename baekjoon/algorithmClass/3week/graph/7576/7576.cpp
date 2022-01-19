#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int boxes[1002][1002];
int visit[1002][1002];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int> > ripes;
int main(){
  //N: row, M: col
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int N, M;
  int unripe = 0;
  int ripe = 0;
  int days = 0;
  memset(boxes, -1, sizeof(boxes));
  cin >> M >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> boxes[i][j];
      if(boxes[i][j] == 0) unripe++;
      else if(boxes[i][j] == 1) {
          ripes.push({i, j});
          visit[i][j] = 1;
          ripe++;
      }
    }
  }
  
  while(!ripes.empty() && unripe > 0) {
    int row = ripes.front().first;
    int col = ripes.front().second;

    ripes.pop();
    for(int i = 0; i < 4; i++) {
      int next_row = row + dy[i];
      int next_col = col + dx[i];
      if(visit[next_row][next_col] == 0 && boxes[next_row][next_col] == 0){
          visit[next_row][next_col] = visit[row][col] + 1;
          boxes[next_row][next_col] = 1;
          ripes.push({next_row, next_col});
          unripe--;
      }
    }
    days = visit[row][col];
  }

  if(unripe == 0 && ripe > 0) cout << days << "\n";
  else cout << "-1\n";

  return 0;
}
