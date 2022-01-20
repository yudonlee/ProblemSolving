#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
int visit[103][103];
int sectionCount[10001] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int number = 0;

void bfs(int row, int col){
  int r, c;
  visit[row][col] = 1;
  sectionCount[number]++;
  queue<pair<int, int> > q;
  q.push({row, col});
  while(!q.empty()){
    tie(r, c) = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int next_row = r + dy[i];
      int next_col = c + dx[i];

      if(visit[next_row][next_col] == 0) {
        visit[next_row][next_col] = 1;
        q.push({next_row, next_col});
        sectionCount[number]++;
      }
    }
  }

}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  memset(visit, -1, sizeof(visit));
  int M, N, K;
  cin >> M >> N >> K;
  int left_x, left_y, right_x, right_y;
  for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) visit[i][j] = 0;

  for(int k = 0; k < K; k++) {
    //x is 0 to M-1, y is 0 to N -1
    cin >> left_x >> left_y >> right_x >> right_y;
    //now x is 1 to M, y is 1 to N
    for(int i = left_y + 1; i < right_y + 1; i++) {
      for(int j = left_x + 1; j < right_x + 1; j++){
          visit[i][j] = 1;
      }
    }

  }
  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      if(visit[i][j] == 0) {
        number++;
        bfs(i, j);
      }
    }
  }

  cout << number << "\n";
  sort(sectionCount, sectionCount + number + 1);
  for(int i = 1; i <= number; i++) {
    cout << sectionCount[i] << " ";
  }
  cout << "\n";
  return 0;
}
