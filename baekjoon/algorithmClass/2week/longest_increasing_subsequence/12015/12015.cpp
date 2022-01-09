#include <iostream>
#include <algorithm>
#include <vector>
int A[1000000];

std::vector<int> DP;
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin.tie(NULL);

  int count = 0;

  int N, input;
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> A[i];
  
  DP.push_back(A[0]);
  for(int i = 1; i < N; i++) {
    if(DP.back() < A[i]) DP.push_back(A[i]);
    
    else {
      auto it = std::lower_bound(DP.begin(), DP.end(), A[i]);
      *it = A[i];
    }
  }
  std::cout << DP.size() << "\n";
}
