#include <iostream>
#include <string>
int main(){
  std::string input;
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> input;
  int number = 0;
  std::string str_to_num = "";
  
  //첫번째 - 찾기
  int first_minus = input.find("-");
  //첫번째 Minus가 나오기 전 까지 모든 숫자 덧셈
  if(first_minus == -1) first_minus = input.length(); 
  
  for(int i = 0; i < first_minus; i++) {
    if(input[i] != '+') {
      str_to_num += input[i];
    } else {
      int m = std::stoi(str_to_num);
      number += m;
      str_to_num = "";
    }
    if(i == first_minus - 1) {
      int m = std::stoi(str_to_num);
      number += m;
      str_to_num = "";
    }
  }
  //다음 Minus가 나올때 까지 첫번째 minus기준으로 뒤에 모든 숫자들을 더한 뒤, minus처리 해줄때 최솟값이 된다.
  int minus = 0;
  for(int i = first_minus + 1; i < input.length(); i++){
    if(input[i] != '-' && input[i] != '+') {
      str_to_num += input[i];
    } else if(input[i] == '+') {
      int m = std::stoi(str_to_num);
      minus += m;
      str_to_num = ""; 
    } else if(input[i] == '-') {
      int m = std::stoi(str_to_num);
      minus += m;
      number -= minus;
      minus = 0;
      str_to_num = ""; 
    }

    if(i == input.length() - 1) {
      int m = std::stoi(str_to_num);
      minus += m;
      number -= minus;
    }
  }
  std::cout << number << std::endl;
  return 0;
}

