#include <iostream>
#include <vector>

int main(){
  int n, input; 
  std::vector<int> ans;
  std::cin >> n;
  for(int i = 0; i < n; i++) {
      std::cin >> input;
    int index = std::lower_bound(ans.begin(), ans.end(), input) - ans.begin();
    if(ans.empty() || ans.back() < input) ans.push_back(input);
    else {
      ans[index] = input;
    }
  }
  std::cout << ans.size() << "\n";
}
