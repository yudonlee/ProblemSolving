#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define SIZE 4


void search(int i,int j,int count,int value);

vector<int> results;
int array[4][4] = {0,};
int main(){
	int number;
	cin >> number;
	for(int k=1; k <= number; k++){ 
		for(int i=3; i>-1; i--){
			for(int j=0; j<4; j++){
				cin >> array[i][j];
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
					search(i,j,1,0);
			}
		}
	//for(auto it = results.begin(); it!= results.end();it++)
	//	cout << *it<<" ";
		set<int> s(results.begin(),results.end());
		results.assign(s.begin(),s.end());
	//for(auto it = results.begin(); it!= results.end();it++)
	//	cout << *it<<" ";
		cout <<"#"<<k<<" "<<results.size();
		results.erase(results.begin(),results.end()); // if not initialization,it does make error.
	}
	return 0;
}

void search(int i,int j,int count,int value){
	if( i < 0 || j < 0 || i > SIZE -1 || j > SIZE -1 || count > 7 ){ 
		return;
	}
	int multi = 1;
	for(int k = 6; k >= count; k--)
		multi *= 10;
	value += multi*array[i][j];
	if(count == 7)
		results.push_back(value);
	count++;
	search(i+1,j,count,value);
	search(i-1,j,count,value);
	search(i,j+1,count,value);
	search(i,j-1,count,value);
}

