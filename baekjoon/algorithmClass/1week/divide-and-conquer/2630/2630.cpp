#include <iostream>
int num_of_white;
int num_of_blue;
bool A[128][128];
bool isEqual(int row, int col, int N) {
  int next = N / 2;
  int root = A[row][col];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(root != A[row + i][col + j]) return false;
    }
  }
  return true;

}
void divide(int row, int col, int N){
  if(N == 1) {
      if(A[row][col]) num_of_blue++;
      else num_of_white++; 
      return;
  }
  int next = N / 2;
  if(isEqual(row, col, N)) {
      if(A[row][col]) num_of_blue++;
      else num_of_white++; 
  }
  else {
      divide(row, col, next);
      divide(row + next, col, next);
      divide(row, col + next, next);
      divide(row + next, col + next, next); 
  }
}
int main() {
  int N;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> N;
  num_of_white = 0, num_of_blue = 0;
  for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++) std::cin >> A[i][j];
  
  divide(0, 0, N);
  std::cout << num_of_white << "\n" << num_of_blue << "\n";
  return 0;
}
