#include <iostream>
#include <vector>
using namespace std;
int queen[10];
int n_queen[11]={0,};
int backtrack();
int number;
int n;
int count;
void search(int x,int y,vector<int> row);
int main(){
	cin >> number;
	for(int i=0;i<number;i++){
		cin >> queen[i];
	}
	for(int i=0; i<number;i++){
		count =0;
		n = queen[i];
		cout << "n is :"<<n;
		if(n_queen[n] == 0)
			n_queen[n] = backtrack();
		cout <<"#"<<i+1<<" "<<n_queen[n]<<"\n";
	}
	return 0;
}
int backtrack(){
	count =0;
	if(n==1)
		return 1;
	for(int r=0;r<n;r++){
		vector<int> row;
		search(r,0,row);				
	}
	return count;
}
bool bit(int x,int y,vector<int> row){
	int i=0;
	for(auto it : row){
		if( x == it || (abs(y-i)) == (abs(it - x)))
			return false;
		i++;
	}
	return true;
}
void search(int x,int y,vector<int> row){
	row.push_back(x);
	if(y > n-2)
		return;
	else if( y == n-2){
		for(int i=0; i< n;i++){
			if(bit(i,y+1,row))
				count++;
		}
	}
	else{
		for(int i=0; i< n;i++){
				if(bit(i,y+1,row)){
					search(i,y+1,row);
				}
		}
	}
}
