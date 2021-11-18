#include <iostream>
#include <string>
using namespace std;
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
char case_BW[8][8] = {
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'}
};
char case_WB[8][8] = {
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'}
};
int checkColor(string* board, int i, int j){
  int cnt_BW = 0, cnt_WB = 0;
  for (int s = i; s < i + 8; s++) {
    for (int t = j; t < j + 8; t++) {
      if (board[s][t] != case_BW[s - i][t - j]) cnt_BW++;
      else if (board[s][t] != case_WB[s - i][t - j]) cnt_WB++;
    }
  }
  return MIN(cnt_BW, cnt_WB);
}
int make_minimum(string* board, int n, int m){
  int minimum = 64;
  for (int i = 0; i < n - 8 + 1; i++) {
    for (int j = 0; j < m - 8 + 1; j++) {
      minimum = MIN(minimum, checkColor(board, i, j));
    }
  }
  return minimum;
}
int main(){
  int n, m;
  string board[51];
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
      cin >> board[i];
  }
  int result = make_minimum(board, n, m);
  printf("%d\n", result);
  return 0;
}
