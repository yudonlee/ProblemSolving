#include <iostream>
#include <algorithm>

//low 석순, high 종유석
int low[100000];
int high[100000];
int count = 0;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// target보다 같거나 큰 value들의 첫번째 index 찾기.
// 없을때 크기 return.
int lower_bound(int left, int right, int target, int* arr) {
  int l = left, r = right;
  while(l < r) {
    int mid = (l + r) / 2;
    if (target <= arr[mid]) r = mid;
    else l = mid + 1;
  }
  return l;
}
// target보다 큰 value index 찾
int upper_bound(int left, int right, int target, int* arr){
  int l = left, r = right;
  while(l < r) {
    int mid = (l + r) / 2;
    if (target >= arr[mid]) l = mid + 1;
    else r = mid;
  }
  return l;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int N, H;
  std::cin >> N >> H;
  int N_2 = N / 2;
  for(int i = 0; i < N_2; i++) std::cin >> low[i] >> high[i];
 
  std::sort(low, low + N_2);
  std::sort(high, high + N_2);

  int min = 99999999, num_of_min = 0;

  for(int target = 1; target <= H; target++) {
    int left = 0, right = N_2;
    int low_index = lower_bound(0, N_2, target, low);


    int high_index = upper_bound(0, N_2, H - target, high);
    

    //if(high_index == N_2 - 1 && high[high_index] >= 8 - target) high_index = 0;

    
    /*
    if(low[low_index] < target & low_index != N_2 - 1) low_index++;


    if(high[high_index] != target & high_index != N_2 - 1) high_index++; */
    
    //std::cout << "left : " << N_2 - low_index << " N_2 - high_index" << N_2 - high_index << "\n";
    //std::cout << "count: " << N_2 - low_index << "\n"; 
    int numbers = N_2 - low_index + N_2 - high_index; 
    if(numbers < min) {
      min = numbers;
      num_of_min = 1;
    } else if(numbers == min) num_of_min++;
    
    //std::cout << "min is: " << min << " height is : " << target << "\n";
  }
  std::cout << min <<" "<< num_of_min << "\n";
  return 0;
}
