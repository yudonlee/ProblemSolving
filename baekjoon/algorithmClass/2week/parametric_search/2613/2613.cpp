#include <iostream>
int N, M, beads[300], group[300];
  
bool check(int target){
  int groupCnt = 1;
  int sum = 0;
  for(int i = 0; i < N; i++) {
    if(beads[i] > target) return false;
    
    //합이 target 보다 클때 groupCount 증가
    //남은 구슬의 갯수와, 남은 그룹갯수의 크기가 동일할때도 그룹갯수 증가
    if(sum + beads[i] > target || N - i == M - groupCnt) {
      groupCnt++;
      sum = 0;
    }
    sum += beads[i];
  }
  
  if (groupCnt == M) return true;
  return false;
}

void divide(int target){
  int sum = 0;
  int groupCnt = 1;
  for(int i = 0; i < N; i++) {
    if(sum + beads[i] > target || N - i == M - groupCnt) {
      groupCnt++;
      sum = 0;
    }
    group[groupCnt - 1]++;
    sum += beads[i];
  }
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  std::cin >> N >> M;
  int left = 1;
  int right = 0; 
  
  for(int i = 0; i < N; i++) {
      std::cin >> beads[i];
      right += beads[i];
      if(left < beads[i]) left = beads[i];
  }

  
  int ans = 30000;

  while(left <= right) {
    int mid = (left + right) / 2;
    bool test = check(mid);

    if(test) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }

  }
  
  divide(ans);
  std::cout << ans << "\n";
  for(int i = 0; i < M; i++) std::cout << group[i] << " ";
  std::cout << "\n";
  return 0;
}
