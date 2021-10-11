#include <iostream>
// global variable 
//The number of east site and west site is n, m
int g_n, g_m;

int result = 0;
int value[31][31] = {0, };
int search(int n, int m) {
  // dynamic programming
  if(value[n][m] != 0) return value[n][m];
  if (n > m) value[n][m] = 0;
  else if(n == m) value[n][m] = 1;
  else if(n == 1) value[n][m] = n * m; 
  else {
    for (int i = 1; m - i > 0; i++) {
      //split (n, m) to (n-1, m-1 ... n-1)
      value[n][m] += search(n - 1, m - i); 
    }   
  }
  return value[n][m];
}
int main(){
  int number;
  std::cin >> number;
  for (int j = 0; j < number; j++) {
    scanf("%d %d", &g_n, &g_m);
    value[g_n][g_m] = search(g_n, g_m); 
    printf("%d\n", value[g_n][g_m]);
    result = 0;
  }
}
