#include <iostream>
#include <vector>
using namespace std;

int N;

int max_count[70];
int added_stacks[71][71] = {0, };
void dfs(int i, int j , int count, int stacks[][71]) {
  if(count > max_count) max_count = count;
  while(

  for(int r = 1; r <= N; r++) {
    for(int c = 1; c <= N; c++) {
      added_stacks[r][c] = stacks[r][c];
      if(abs(i - r) == abs(j - c)) added_stacks[r][c] = 1;
    }
  }
 
  for(int r = 1; r <= N; r++) {
    for(int c = 1; c <= N; c++) {
      if(added_stacks[r][c] == 0) {
        added_stacks[r][c] = 1;
        dfs(r, c, count + 1, added_stacks);
        added_stacks[r][c] = 0;
      }
    }
  }


}

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;

  //사실상 닮음이라 두번만 하면 비숍이 놓이는 모든 위치가 결정된다.
  int stacks[71][71] = {0, };
  int k = (N + 1) / 2;
  for (int i = 1; i <= k; i++) { 
    stacks[i][i] = 1;
    dfs(i, i, 1, stacks);
    stacks[i][i] = 0;
  }
  cout << max_count << "\n";
  return 0;
}
