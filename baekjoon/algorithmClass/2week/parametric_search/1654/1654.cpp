#include <iostream>
#include <limits.h>

int lan[10000];
int K, N;
long long ans;

long long counting(long long lan_length){
  long long result = 0;
  for(int i = 0; i < K; i++) {
    long long share = lan[i] / lan_length;
    result += share;
  }
  return result;
}
long long search(long long left, long long right, int numbers){
  long long mid = (left + right) / 2;
  long long counted_lan = counting(mid);
  

  //결국 mid가 커지거나, 작아지거나 하면서 out of range된다. 그때 out of range되기 직전 mid를 return하면 그것이 답이 된다.
  if(left > right) return ans;

  if(counted_lan < numbers) {
    return search(left, mid - 1, numbers);
  } else {
    ans = mid;
    return search(mid + 1, right, numbers);
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> K >> N;
  for(int i = 0; i < K; i++) std::cin >> lan[i];

  
  long long l = search(0, INT_MAX, N);
  std::cout << l << "\n";
  return 0;
}
