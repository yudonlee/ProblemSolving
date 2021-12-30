#include <iostream>
#include <stdio.h>


int main(){
  // N: row, M: col, B: Inventory
  int N, M, B;
  int land[500][500];
  scanf("%d %d %d", &N, &M, &B);
  int num_of_blocks = B;
  for(int i = 0; i < N; i++) 
    for(int j = 0; j < M; j++) { 
        scanf("%d ",  &land[i][j]);
        num_of_blocks += land[i][j];
    }
  int minimum_time = 999999999; 
  int now_layer = -1;
  for(int layer = 0; layer <= 256; layer++){
    if (num_of_blocks < layer * N * M) break;
    int time = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(land[i][j] > layer) time += (land[i][j] - layer) * 2;
        else {
          time += (layer - land[i][j]); 
        } 
      }
    }

    if(time <= minimum_time) {
        minimum_time = time;
        now_layer = layer;
    }
  }

  printf("%d %d\n", minimum_time, now_layer);
  return 0;
}
