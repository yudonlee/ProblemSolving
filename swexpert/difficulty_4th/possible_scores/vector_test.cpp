#include <iostream>
#include <vector>
using namespace std;
void call(int vv[],int number){
	for(int i =0; i<number;i++){
		vv[i] += 2;
	}
}
int main(){
	int number;
	vector<int> vv;
	cin >> number;
	int num[10];
	for(int i=0; i<number;i++){
		cin >> num[i];
	}
	cout<<"before:  ";
	for(int i=0; i<number;i++){
		cout << num[i]<<" ";
	}
	cout<<"\n after: ";
	call(num,number);
	for(int i=0; i<number;i++){
		cout << num[i]<<" ";
	}
	return 0;
	
	
}
