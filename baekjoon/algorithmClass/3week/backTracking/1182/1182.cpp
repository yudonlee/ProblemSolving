#include <iostream>
#include <algorithm>

using namespace std;

int num[20];
int N, S;
int subsets = 0;
void dfs(int sum, int next_index){
  if(next_index == N) {
    if(sum == S) subsets++;
    return;
  } 
  
  if(sum == S && num[next_index] > 0) {
    dfs(sum, N);
  }
  else {
    dfs(sum + num[next_index], next_index + 1);
    dfs(sum, next_index + 1);
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  cin >> N >> S;
  for(int i = 0; i < N; i++) cin >> num[i]; 
  sort(num, num + N);
  dfs(num[0], 1);
  dfs(0, 1);
  if(S != 0) cout << subsets << "\n";
  else cout << subsets - 1 << "\n";
  return 0;
}
