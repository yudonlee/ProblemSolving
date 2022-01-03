#include <iostream>
#include <vector>
#include <queue>
#define snake 2
#define apple 1
#define no 0
std::queue<std::pair<int, int> > snake_status;
typedef std::pair<int, int> Index;

int N;
int board[100][100] = {0,};
int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char conversion[10001] = {0, };
bool isHeadCollision(int r, int c) {
  if(board[r][c] == snake || r >= N || c >= N || r < 0 || c < 0) {
    return true;
  }
  return false;
}
int main(){
  int K, L, apple_row, apple_col, input_time;
  char input_direct;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> N;
  std::cin >> K;
  for(int i = 0; i < K; i++) {
    std::cin >> apple_row >> apple_col;
    board[apple_row - 1][apple_col - 1] = apple;
  }
  std::cin >> L;
  for(int i = 0; i < L; i++) {
    std::cin >> input_time >> input_direct;
    conversion[input_time] = input_direct;
  }
  int next_row = 0, next_col = 1;
  int direct = 0;
 
  int current_time = 0;
  board[0][0] = snake;
  snake_status.push(std::make_pair(0, 0));
  //board판에 Snake, apple, wall정보가 담겨져있다.
  //충돌날때 while문이 종료된다.
  
  //다음 목적지가 wall이거나 snake와 충돌나면 While문은 종료된다.
  while (!isHeadCollision(next_row, next_col)) {
    //다음 목적지에 아무것도 없을때

    //snake의 머리가 이동하고, 꼬리는 줄어들어야한다. 
    //머리가 생겨 크기는 +1 증가한 뒤, 다시 마지막 꼬리부분이 한칸 줄어야 한다.
    //큐에 저장함으로써, 가장 오래된 꼬리를 탈락시키는데 사용된다.
    //돌아보니 큐는 필요없었던거 같다.
    current_time++;
    if(board[next_row][next_col] == no) {
      snake_status.push(std::make_pair(next_row, next_col));
      Index idx = snake_status.front();
      snake_status.pop();
      board[next_row][next_col] = snake;
      board[idx.first][idx.second] = no;
    }
    //다음 목적지에 apple이 있을때 snake 크기증가
    else if(board[next_row][next_col] == apple) {
      snake_status.push(std::make_pair(next_row, next_col));
      board[next_row][next_col] = snake;
    }
    
    //방향 변환 체크
    if(conversion[current_time] != 0) {
      if(conversion[current_time] == 'L') {
        direct--;
        if(direct == -1) direct =3;
      } else {
        direct++;
        if(direct == 4) direct = 0;
      }
    }
    
    next_row += direction[direct][0];
    next_col += direction[direct][1];
  }
  
  //종료되기 위해선 이동을 한 뒤, 충돌이 발생하여 종료된다.
  //하지만 여기선 while-loop에서 이동하기 전 조건문을 체크하기 때문에 이동하지 않고 종료된다.
  //그리하여 실제 한번 이동한 시간을 더해준다.
  std::cout << current_time + 1 << "\n";
  return 0;
}
