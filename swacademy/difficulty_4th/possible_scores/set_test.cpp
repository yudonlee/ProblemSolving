#include <iostream>
#include <vector>
#include <set>
using namespace std;
void call(set<int> vv,int number){
	for(int i =0; i<number;i++){
		vv.insert(i+8);
	}
	cout <<"\nin function: ";
	for(auto i : vv)
		cout << i<<" ";
	cout <<endl;
}
void calls(vector<int> vv,int number){
	for(int i =0; i<number;i++){
		vv.push_back(i+8);
	}
	cout <<"\nin function: ";
	for(auto i : vv)
		cout << i<<" ";
	cout <<endl;
}
void callss(vector<int> &vv,int number){
	for(int i =0; i<number;i++){
		vv.push_back(i+8);
	}
	cout <<"\nin function: ";
	for(auto i : vv)
		cout << i<<" ";
	cout <<endl;
}
int main(){
	int number;
//	set<int> vv;
	vector<int> vv;
	cin >> number;
	int num[10];
	for(int i=0; i<number;i++){
		int aa;
		cin >> aa;
		vv.push_back(aa);
	}
	cout<<"before:  ";
	for(auto i : vv)
		cout << i<<" ";
	callss(vv,number);
	cout <<"\nafter: ";
	for(auto i : vv)
		cout << i<<" ";
	return 0;
	
	
}
