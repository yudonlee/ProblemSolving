#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
int maze[101][101];
//visit은 방문여부와 (1,1)에서 떨어진 거리를 나타낸다.
int visit[101][101] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;
void bfs(int row, int col){
  visit[row][col] = 1;
  
  queue<pair<int, int> > q;
  q.push({row, col});
  while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nextRow = r + dy[i];
      int nextCol = c + dx[i];

      if(maze[nextRow][nextCol] == 1 && visit[nextRow][nextCol] == 0) {
        visit[nextRow][nextCol] = visit[r][c] + 1;
        q.push({nextRow, nextCol});
      }
    }
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  cin >> N >> M;
  string inputs;
  memset(maze, -1, sizeof(maze));
  for(int i = 1; i <= N; i++) {
    cin >> inputs;
    int j = 1;
    for(char s: inputs) maze[i][j++] = s - '0';
  }

  bfs(1, 1);
  cout << visit[N][M] << "\n";

  return 0;
}
