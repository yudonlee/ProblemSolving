#include <iostream>
using namespace std;
#define MIN(x,y) x < y ? x : y
int main(){
	int row[1000];
	int height,number,col; // col is less than 256
	for(int i=1;i < 11; i++){
		int households=0; //if int households; then, the result is added #1, #2 is #2+#1. #3 is #3+ #2 +#1 ..
		cin >> number;
		for(int j = 0; j< number;j++)
			cin >> row[j];
		for(int j = 2; j< number-2;j++){
			if(row[j] >0){
				int min = row[j] - row[j-2];
				min = MIN(min, row[j] - row[j-1]);
				min = MIN(min, row[j] - row[j+1]);
				min = MIN(min, row[j] - row[j+2]);
				if(min >0)
					households += min;	
			}
		}
		cout << "#"<<i<<" "<<households<<endl;
		
	}
	return 0;
}
