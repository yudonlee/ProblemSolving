#include <iostream>
#include <stdio.h>
#include <algorithm>

int main(){
  int A[50];
  int B[50];
  int N;
  int result = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  for (int i = 0; i < N; i++) scanf("%d", &B[i]);
  std::sort(A, A+N);
  std::sort(B, B+N);
  for (int i = 0; i < N; i++) result += A[i] * B[N - i -1];
  printf("%d\n", result);
  return 0;
}
