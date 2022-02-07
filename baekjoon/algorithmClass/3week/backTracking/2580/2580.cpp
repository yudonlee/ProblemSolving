#include <iostream>
using namespace std;
int matrix[9][9];

//행과 열에서 사용한 숫자들을 기록.
int used_number_rows[9][10] = {0, };
int used_number_cols[9][10] = {0, };

int zeros_row[81] = {0, };
int zeros_col[81] = {0, };
int small_square[3][3][10] = {0, };
int zero_count = 0;

bool status = true;
bool checkSmallSquare(int r, int c) {
  if(small_square[r / 3][c/ 3][matrix[r][c]] > 1) return false; 
  /*
  int start_row = r / 3;
  int start_col = c / 3;
  int numbers[10] = {0, };
  numbers[0] = -9;
  for(int i = 3 * start_row; i < start_row + 3; i++) {
    for(int j = 3 * start_col; j < start_col + 3; j++) {
      numbers[matrix[i][j]]++;
      if(numbers[matrix[i][j]] > 1) {
          return false;
      }
    }
  }*/
  return true;
}
void dfs(int index) {
  if(index == zero_count && status) {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
          cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
    status = false;
    return;
  }
  for(int i = 1; i <= 9; i++) {
    if(!status) return;

    int r = zeros_row[index];
    int c = zeros_col[index];
    
        
    if (used_number_rows[r][i] || used_number_cols[c][i]) continue;
    
    matrix[r][c] = i;
    used_number_rows[r][i] = 1;
    used_number_cols[c][i] = 1;
    small_square[r / 3][c / 3][i]++;

    if(checkSmallSquare(r, c) && status) {
          dfs(index + 1);
    }
    if(status) {
      used_number_rows[r][i] = 0;
      used_number_cols[c][i] = 0;
      matrix[r][c] = 0;
      small_square[r / 3][c / 3][i]--;
    }
  }
}
int main(){
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> matrix[i][j];
      used_number_rows[i][matrix[i][j]] = 1;
      used_number_cols[j][matrix[i][j]] = 1;

      int r = i / 3;
      int c = j / 3;
      small_square[r][c][matrix[i][j]] = 1;

      if(matrix[i][j] == 0) {
        zeros_row[zero_count] = i;
        zeros_col[zero_count++] = j;
      }
    }

  }
  dfs(0);
  return 0;
}
