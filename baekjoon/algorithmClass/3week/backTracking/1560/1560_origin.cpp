#include <iostream>
#include <vector>
using namespace std;

int stacks[71][71] = {0, };
int N;

int max_count = 0;
void dfs(int i, int j , int count, vector<pair<int, int> > queues) {
  if(count > max_count) max_count = count;

  for(int r = 1; r <= N; r++) {
    for(int c = 1; c <= N; c++) {
      bool status = true;
      for(auto bishop: queues) {
          if(abs(r - bishop.first) == abs(c - bishop.second)) {
              status = false;
              break;
          }
      }
      
      if(status) {
        vector<pair<int, int> > added = {queues.begin(), queues.end()};
        added.push_back({r, c});
        dfs(r, c, count + 1, added);
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
  for (int i = 1; i <= (N + 1) / 2; i++) { 
    //stacks[i][j] = 1;
    vector<pair<int, int> > queues;
    queues.push_back({i, i});
    dfs(i, i, 1, queues);
    //stacks[i][j] = 0;
  }
  cout << max_count << "\n";
  return 0;
}
