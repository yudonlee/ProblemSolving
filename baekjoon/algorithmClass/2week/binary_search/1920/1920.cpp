#include <iostream>
#include <algorithm>

int A[100000];

bool search(int left, int right, int number){
  int mid = (left + right) / 2;
  
  if(left > right) return false;

  if(A[mid] == number) return true;
  else if(A[mid] < number) return search(mid + 1, right, number);
  else return search(left, mid - 1, number);
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cout.tie(NULL);
  std::cin.tie(NULL);
  int M[100000];
  int input;
  int n, m;
  std::cin >> n;
  for(int i = 0; i < n; i++) std::cin >> A[i];
  std::sort(A, A + n);
  
  std::cin >> m;
  
  for(int i = 0; i < m; i++) std::cin >> M[i];
  
  for(int i = 0; i < m; i++) {
    bool result = search(0, n-1, M[i]);
    std::cout << result << "\n";
  }
  return 0;
}
