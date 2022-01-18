#include <iostream>
#include <string>
using namespace std;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int maze[101][101];
int min_dist = 10000;
int visit[101][101] = {0, };
int N, M;
void bfs(int row, int col, int distance){
  if(row < 1 || row > N || col < 1 || col > M) return;
  
  if(maze[row][col] == 0) return;
  
  if(visit[row][col] > 0 && visit[row][col] <= distance) return;
  visit[row][col] = distance;

  if(row == N && col == M) {
      min_dist = MIN(distance, min_dist);
  }
  bfs(row + 1, col, distance + 1);
  bfs(row, col + 1, distance + 1);
  
  bfs(row - 1, col, distance + 1);
  bfs(row, col - 1, distance + 1);
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  cin >> N >> M;
  string inputs;
  for(int i = 1; i <= N; i++) {
    cin >> inputs;
    int j = 1;
    for(char s: inputs) maze[i][j++] = s - '0';
  }

  bfs(1, 1, 1);
  cout << min_dist << "\n";
  return 0;
}
