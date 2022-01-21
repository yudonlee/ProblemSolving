#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MAX_TOTAL 10000

int main(){
	int number,test_case,scores;
	cin >> test_case;
	for(int i=0; i< test_case;i++){
		int num_of_scores;
		cin >> num_of_scores;
		int values[MAX_TOTAL + 1] = {0,};
		int max=0;
		int num[101]={0,};
		int count =0;
		values[0] = 1;
		for(int i=0; i< num_of_scores;i++)
			cin >> num[i];
		for(int i=0; i< num_of_scores;i++){
			int val = num[i];
			for(int j=max; j>= 0;j--){
				if(values[j] > 0)
					values[j+val]++;
			}
			max +=val;
		}
		for(int j=0; j<max;j++){
			if(values[j] > 0){
				count++;
			}
		}

		cout<<"#"<<i+1<<" "<<count+1<<"\n";
	}
	return 0;
}
