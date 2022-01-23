#include <iostream>
using namespace std;

int dx[4] = {0, 2, 1, 1};
int dy[4] = {0, 3, 3, 2};
bool status = true;

int N;
int result[81];
void dfs(int min[], int current, int index){
  //last index is number
  min[index] = current;

  for(int i = 2; i <= (index + 1) / 2; i++) {
    int start = index - i * 2 + 1;
    int next_start = index - i + 1;

    bool check = true;
    for(int j = 0; j < i; j++) if(min[start + j] != min[next_start + j]) check = false;
    if(check) return;
  }
  if(index == N - 1 && status) {
    for(int k = 0; k < N; k++) cout << min[k];
    cout <<"\n";
    status = false;
  }
  if(status) {
    dfs(min ,dx[current], index + 1);
    dfs(min, dy[current], index + 1);
  }

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int min[81]; // last index is number.
  min[0] = 1;
  min[1] = 1;
  cin >> N;
  if(N != 1) {
      dfs(min, dx[1], 1);
      dfs(min, dy[1], 1);
  } else {
    cout << "1" << "\n";
  }
  return 0;
}


