#include <iostream>
#include <set>
#include <vector>
using namespace std;

void inserts(set<int> &result,vector<int> index,int* num,int x,int y,int levels,int count);

int num_of_scores;
int main(){
	int number,test_case,scores;
	cin >> test_case;
	for(int i=0; i< test_case;i++){
		cin >> num_of_scores;
		int num[101]={0,};
		int count=0;
		set<int> result;
		vector<int> index;
		for(int i=0; i< num_of_scores;i++){
			cin >> number;
			if(num[number] == 0){
				index.push_back(number);
				result.insert(number);
				count++;
			}
			num[number]++;
		}
			
		for(int i = 0; i< count;i++){
			for(int j = 0; j < count; j++){
				int added_number = index[i] + index[j];
				int copied_num[101];//int* copied_num;
				int levels = 2;
				copy(num,num+101,copied_num);
				inserts(result,index,copied_num,index[i],index[j],levels,count);
			
			}
		}
	/*	for( auto it = result.begin(); it != result.end(); it++)
			cout << *it <<endl;
	*/
	cout<<"#"<<i+1<<" "<<result.size()+1<<"\n";
	}
}
void inserts(set<int> &result,vector<int> index,int* copied_num,int x,int y,int levels,int count){
	//vector를 멤버변수로 호출할때 그값이 복사되는지 아니면 heap영역에서 건드리기
	//떄문에 값이 손상되는지가 확실치 않음. 출력을 통해 확인해봐야할듯
	//그렇기 때문에 아무래도 index에 있는것들을 복사해줘야 할 거 같음.
	//이게 맞는 방식인지 확실치 않기에 고민이 많이 됨. 있는 그대로를 살리면서 어떻게 안될까?
	//set형식을 씀으로써 중복되는 글자를 없애버릴수 있다.
	if(levels == 2 && x==y){
		if(copied_num[x] > 1){
			result.insert(x+y);
			copied_num[x]-=2;
			levels++;
			for(int i = 0;i < count;i++)
				inserts(result,index,copied_num,x+y,index[i],levels,count);	
		}
	}
	else if(levels == 2 && x != y){
		if(copied_num[x] > 0 && copied_num[y] >0){
			result.insert(x+y);
			copied_num[x]--;
			copied_num[y]--;
			levels++;
			for(int i = 0;i < count;i++)
				inserts(result,index,copied_num,x+y,index[i],levels,count);
		}
	}
	else if(copied_num[y] > 0 && levels > 2 && levels <= num_of_scores ){
		result.insert(x+y);
		copied_num[y]--;
		levels++;
		for(int i = 0;i < count;i++)
			inserts(result,index,copied_num,x+y,index[i],levels,count);
	}	
}
/*void inserts(set<int> &result,vector<int> index,int* copied_num,int x,int y,int levels,int count){
	if(levels == 2){
		if(x== y){
			if(copied_num[x] >1){
				result.insert(x+y);
				copied_num[x]-=2;
				levels++;
				for(int i = 0; i< count; i++){
					inserts(result,index,copied_num
				}
			}
		}
	}
}
*/
