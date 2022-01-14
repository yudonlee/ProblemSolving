#include <iostream>
#include <vector>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main(){
  int max = -1, length = 0, max_length = 0;
  std::vector<int> lis;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n, input;
  while(std::cin >> n){
    for (int i = 0; i < n; i++) {
      std::cin >> input; 
      int index = std::lower_bound(lis.begin(), lis.end(), input) - lis.begin();
      if(lis.size() == index) {
          lis.push_back(input);
      }
      else {
        lis[index] = input;
      }
    }
    std::cout << "result is: "<< lis.size() << "\n";
    
    lis.clear();
  }
  return 0;
}
