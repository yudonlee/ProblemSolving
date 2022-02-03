#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  if(n == 1) std::cout << n << "\n";
  else std::cout << n + n - 2 << "\n";
  return 0;
  
}
