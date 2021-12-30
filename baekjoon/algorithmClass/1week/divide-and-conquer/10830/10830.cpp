#include <iostream>
#include <stdio.h>
#include <vector>
#define Remainder 1000
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
int N;
matrix operator*(matrix l, matrix r){
  //2D vector initialization! 
  matrix ret(N, vector<ll>(N, 0));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++){
        ret[i][j] += l[i][k] * r[k][j];
      }
      ret[i][j] %= Remainder;
    }
  }
  return ret;
}
matrix multiplication(matrix mat, ll b){
  matrix tmp(N, vector<ll>(N));
  if(b > 1) tmp = multiplication(mat, b/2);
  if(b == 1) return mat;
  else if(b % 2 == 1) {
    return (tmp * tmp * mat);
  } else {
    return tmp * tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  ll B, input;
  cin >> N >> B;
  matrix A(N, vector<ll>(N, 0));

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  matrix result(N, vector<ll>(N, 0));
  result = multiplication(A, B);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << result[i][j] % Remainder << " ";
    }
    cout << "\n";
  }
  return 0;
}
