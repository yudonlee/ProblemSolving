#include <iostream>

long long trees[1000000];

long long count(int N, long long height){
  long long result = 0;
  for(int i = 0; i < N; i++) {
    if(height < trees[i]) result += trees[i] - height;
  }
  return result;
}
int main(){
  int N;
  long long M, H, left, right, ans;
  left = 0;
  right = 0;
  ans = -1;

  std::cin >> N >> M;
  for(int i = 0; i < N; i++) {
      std::cin >> trees[i];
      if(right < trees[i]) right = trees[i];
  }
  
  while(left <= right) {
    long long mid = (left + right) / 2;
    long long sum = count(N, mid);
    
    if(sum >= M) {
        ans = mid;
        left = mid + 1;
    } else {
      right = mid - 1;
    }

  }
  std::cout << ans << "\n";
  return 0;
}
