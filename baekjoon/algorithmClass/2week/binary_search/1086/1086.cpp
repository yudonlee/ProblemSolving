#include <iostream>

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  int* numbers = new int[20000001]();
  int N, M;
  int input;
  std::cin >> N;
  for(int i = 0; i < N; i++) {
     std::cin >> input;
     numbers[input + 10000000]++;
  }
  std::cin >> M;
  for(int i = 0; i < M; i++) {
      std::cin >> input;
      std::cout << numbers[input + 10000000] << " ";
  }
  std::cout << "\n";
  return 0;
}
