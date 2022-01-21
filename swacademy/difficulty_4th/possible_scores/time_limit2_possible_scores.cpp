#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main(){
	int number,test_case,scores;
	cin >> test_case;
	for(int i=0; i< test_case;i++){
		int num_of_scores;
		cin >> num_of_scores;
		vector<int> values;
		result.insert(0);
		for(int i=0; i< num_of_scores;i++){
			cin >> number;
			vector<int> copied(values);
			for(auto i : copied)
				values.insert(i+number);	
		}	
		set<int> result(values.begin(),values.end());
		cout<<"#"<<i+1<<" "<<result.size()<<"\n";
	}
}
