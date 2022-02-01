#include <iostream>
#include <vector>


using namespace std;
int N;
int total;
void dfs(int cur_row, int cur_col, vector<int> rows) {
  
  rows.push_back(cur_row);
  
  if(cur_col == N) {
    total++;
    return;
  }
  
  int check[16] = {0, };
  
  int start = 1;
  
  for(auto it: rows) {
      check[it] = 1;
      int differ = abs(cur_col + 1 - start);
      if(0 < it + differ && it + differ < 16) check[it + differ] = 1;
      if(0 < it - differ && it - differ < 16) check[it - differ] = 1;
      
      start++;
      
  }

  for(int row = 1; row <= N; row++) {
      if(check[row] == 0) dfs(row, cur_col + 1, rows); 
  }
  
}
int main() {
  cin >> N;
  for(int i = 1; i <= N; i++) {
    vector<int> index;
    dfs(i, 1, index);
  }
  cout << total << "\n";
}
