#include <iostream>
#include <vector>

int main(){
  int input, n;
  std::cin >> n;
  std::vector<int> ans;
  for(int i = 0; i < n; i++) {
    std::cin >> input;
    int index = lower_bound(ans.begin(), ans.end(), input) - ans.begin();
    if(ans.empty() || ans.back() < input) ans.push_back(input);
    else {
      ans[index] = input;
    }
  }
  std::cout << n - ans.size() << "\n";
  return 0;
}
