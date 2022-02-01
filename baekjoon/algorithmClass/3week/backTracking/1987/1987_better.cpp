#include <iostream>
using namespace std;
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int R, C;
int depth_max = 0;
string inputs[20];
int dx[4] = {0, 1, -1, 0}; 
int dy[4] = {1, 0, 0, -1};
void dfs(int r, int c, int passes[], int depth) {
  if(r < 0 || r >= R  || c < 0 || c >= C) return;
  char current = inputs[r][c];
  if(passes[current - 'A'] == 0) {
    passes[current-'A'] = 1;
    depth_max = MAX(depth, depth_max);
    for(int i = 0; i < 4; i++) {
      //메모리 카피대신, backTracking시 변한 값들을 다시 원상태로 바꿔준다.
      //int pass_copy[26];
      //copy(passes, passes + 26, pass_copy);
      int next_row = r + dy[i];
      int next_col = c + dx[i];
      if(0 <= next_row && next_row < R && 0 <= next_col && next_col < C) {
        if(passes[inputs[next_row][next_col] - 'A'] == 0) {
          dfs(r + dy[i], c + dx[i], passes, depth + 1); 
          passes[inputs[next_row][next_col] - 'A'] = 0;
        }
      }
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
  int passes[26] = {0, };
  dfs(0, 0, passes, 1); 
  cout << depth_max << "\n";
  return 0;
}


