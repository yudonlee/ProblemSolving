// int에 00001 숫자 들어가는지 확인하기
#include <iostream>
using namespace std;
int main(){
	int aa = 0001;
	int bb = 001;
	cout << "aa : "<<aa << " bb is : "<< bb<<endl;
	if(aa == bb)
		cout <<"it is equal"<<endl;
	return 0;
}
