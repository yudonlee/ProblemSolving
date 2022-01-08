#include <iostream>
#include <climits>

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long X, Y, left, right, ans = -1; 
  std::cin >> X >> Y;

  long long Z = (Y * 100) / (double)X; 
  left = 1;
  right = 1000000000000;
  
  while(left <= right) {
    long long mid = left / 2;
    mid += right / 2;
    if(left % 2 == 1 && right % 2 == 1) mid += 1;
    
    
    long long ymid = Y + mid;
    long long xmid = X + mid;
    long long change = (ymid * 100) / xmid;
    //winning_rate = (Y + mid) / (double)(X + mid) * 100;
    //int change = winning_rate;
    
    if(Z < change) {
        ans = mid;
        right = mid -1; 
    }   
    else left = mid + 1;
  }
  std::cout << ans << "\n";
  return 0;
}


