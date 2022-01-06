#include <iostream>
#include <algorithm>

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int N, province[10000];
  long long M, l, r, mid;
  long long province_max = 0;
  std::cin >> N;
  for(int i = 0; i < N; i++) {
      std::cin >> province[i];
      if(province_max < province[i]) province_max = province[i];
  }
  std::sort(province, province + N);
  std::cin >> M;
  l = 0, r = province_max;
  long long ans;
  while(l <= r) {
    mid = (l + r) / 2;
    //std::cout << l << "and" << r << "  \n";
    long long max = 0;
    for(int i = 0; i < N; i++){
      if(province[i] < mid) max += province[i];
      else max += mid;
    }
    if(max > M) r = mid - 1;
    else {
        l = mid + 1;
        ans = mid;
    }
  }
  std::cout << ans <<"\n";
  return 0;
}
