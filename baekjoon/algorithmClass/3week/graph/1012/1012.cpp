#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool visit[51][51] = {0, };
int map[51][51] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


void init(){
  for(int i = 0; i < 51; i++) for(int j = 0; j < 51; j++) {
    map[i][j] = 0;
    visit[i][j] = false;
  }
}
void dfs(int row, int col){
  stack<pair<int, int> > s;
  s.push({row, col});
  visit[row][col] = true;
  while(!s.empty()){
    auto it = s.top();
    s.pop();
    
    for(int i = 0; i < 4; i++) {
      int nextRow = it.first + dy[i];
      int nextCol = it.second + dx[i];
      if(map[nextRow][nextCol] == 1 && visit[nextRow][nextCol] == false){
        s.push({nextRow, nextCol});
        visit[nextRow][nextCol] = true;
      } 
    }
 
  }
}
int main(){
  int test_case;
  int n, m, edges_number;
  int row, col;
  std::ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  cin >> test_case;
  for(int i = 0; i < test_case; i++) {
    vector<pair<int, int> > lists;
    int count = 0;
    // m is col, n is row
    cin >> m >> n >> edges_number; 

    for(int j = 0; j < edges_number; j++) {
      cin >> col >> row;
      lists.push_back({row + 1, col + 1});
      map[row + 1][col + 1] = 1;
    }

    for(auto it: lists){
      if(!visit[it.first][it.second]) {
          count++;
          dfs(it.first, it.second);
      }
    }
    cout << count << "\n";
    init();
  }
  return 0;
}
