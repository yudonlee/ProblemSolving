#include <iostream>
#include <set>
#include <vector>
using namespace std;

void add_result(set<int>* result,vector<int> index,int* num,int
i)
int num_of_scores;
int main(){
	int number,test_case,scores;
	cin >> test_case;
	for(int i=0; i< test_case;i++){
		cin >> num_of_scores;
		int num[101]={0,};
		int count=0;
		set<int> result;
		result.insert(0);
		vector<int> index;
		for(int i=0; i< num_of_scores;i++){
			cin >> number;
			if(num[number] == 0){
				index.push_back(number);
				count++;
			}
			num[number]++;
		}
		for(int i=0; i<count;i++){
			add_result(result,index,num,i);	
		}
		cout<<"\n result: ";
		for(auto it : result)
			cout << it <<" ";
		cout<<"\n"l;
	cout<<"#"<<i+1<<" "<<result.size()+1<<"\n";
	}
}
