#include <iostream>

int A[1000000];

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin.tie(NULL);

  int max_count = 0;

  int N, input;
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> A[i];

  for(int i = 0; i < N; i++) {
    int min_index = i;
    int count = 1;
    int sub_max = A[min_index];

    for(int j = min_index + 1; j < N; j++) {
      if(A[j] > sub_max) {
        count++;
        sub_max = A[j];
      }
    }
    
    if(max_count < count) max_count = count;
  }

  std::cout << max_count << "\n";
}
