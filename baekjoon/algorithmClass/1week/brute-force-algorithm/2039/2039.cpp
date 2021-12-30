#include <stdio.h>
#include <algorithm>

int main(){
  int height[9];
  int sum = 0;
  for(int i = 0; i< 9; i++){
      scanf("%d\n", &height[i]);
      sum += height[i];
  }
  
  std::sort(height, height+9);

  int index1, index2;
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j <9; j++) {
        if(i != j && sum - height[i] - height[j] == 100){
            index1 = i;
            index2 = j;
            break;
        }
    }
  }
  
  for(int i = 0; i < 9; i++) {
    if(i != index1 && i != index2)
        printf("%d\n",height[i]);
  }
}
