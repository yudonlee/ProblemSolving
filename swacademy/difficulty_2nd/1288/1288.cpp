#include<iostream>
#include <map>
#include <string>
#include <bitset>
using namespace std;

int lamb(int number, int test_case){
  int i = number;
  int multiple, remainder, start, base = 10;
  int count = (1 << 10) - 1; // 111111111 
  while(count) {
    for(int j = i; j != 0; j /= 10){
      count = count & ~(1 << (j % 10));
    }
    i += number;
  }
  return i - number;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
  int number;
  for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> number;
    cout << "#" << test_case << " " << lamb(number, test_case) << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
