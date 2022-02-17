int road[10][10] = {0, };
int n;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs_init(int map_size, int map[10][10]) {
  for(int i = 0; i < map_size; i++) 
    for(int j = 0; j < map_size; j++) road[i][j] = map[i][j];
  n = map_size;
}
int bfs(int x1, int y1, int x2, int y2) {
  x1 -= 1;
  x2 -= 1;
  y1 -= 1;
  y2 -= 1;
  int front = 0;
  int rear = 0;
  int next_x[400] = {0, };
  int next_y[400] = {0, };
  int distance[400] = {0, };
  bool visit[10][10] = {0, };
  
  
  next_x[rear] = x1;
  next_y[rear++] = y1;

  while(front < rear) {
    int current_y = next_y[front];
    int current_x = next_x[front];
    

    if(!visit[current_y][current_x]){
      visit[current_y][current_x] = true;
      if(current_x == x2 && current_y == y2) {
          return distance[front];
      }
     
      for(int i = 0; i < 4; i++) {
        int n_x = current_x + dx[i];
        int n_y = current_y + dy[i];
        if(0 <= n_x && n_x < n && 0 <= n_y && n_y < n) {
          if(!road[n_y][n_x]) {
            next_x[rear] = n_x;
            next_y[rear] = n_y;
            distance[rear++] = distance[front] + 1;
          }
        }
      }
    }

    front++;
  }
  return -1; 
}
