#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length(int src){
	if(src >=1000000)
		return -1;
	else if(src >=100000)
		return 6;
	else if(src >=10000)
		return 5;
	else if(src >=1000)
		return 4;
	else if(src >=100)
		return 3;
	else if(src >=10)
		return 2;
	else if(src >=0)
		return 1;
	else
		return -1;
}

int max_winning(int source,int digits,int exchange_number);
void swap(pair<int, int> &x,pair<int, int> &y){
	int tmp;
	tmp = x.second;
	x.second = y.second;
	y.second = tmp;
}
bool cmp_first(const pair<int, int> &x, const pair<int, int> &y){
	//if(x.first == y.first)
	//	return x.second < y.second;
	if(x.first == y.first)
		return x.second > y.second;
	return x.first < y.first;
}
bool cmp(const pair<int, int> &x, const pair<int, int> &y){
	return x.second < y.second;
}
void input(pair <int, int> &x,int value){
	x.second = value;
}
int counted_number[11]={0,};
int main(){
	int number;
	cin >> number;
	int src,dest,exchange_num;
	for(int i=1; i<=number;i++){
		cin >> src >> exchange_num;
		int digits = length(src);
		if(digits == -1)
			break;
		else{
			int result = max_winning(src,digits,exchange_num);
			cout << "#"<< i<<" "<<result<<endl;
		}
	}
	return 0;
}
int max_winning(int source,int digits,int exchange_number){
	vector<pair<int,int> > list_of_nums;
	list_of_nums.push_back(make_pair(-1,-1));
	int count = exchange_number;
	int _digits = digits;
	int _source= source;
	int divided = 10;
	int dividen = source;
	int left_count;
	if(_digits == 1)
		return _source;
	else{
		for(int i=1; i<=digits;i++){
			int remainder = dividen % divided;
			dividen /= divided;
			counted_number[remainder]++;
			if(counted_number[remainder] >1)
				counted_number[11] =1;
			list_of_nums.push_back(make_pair(remainder,i));
		}
		sort(list_of_nums.begin(),list_of_nums.end(),cmp_first); //sorting for first.
		for(int i =1;i<=count;){	
			int inserted_digit = _digits+1-i;
			if(inserted_digit == 1){
				left_count = count -i+1;
				break;
			}
			if(list_of_nums[inserted_digit].second != inserted_digit){
				if( count - i > 0 && counted_number[list_of_nums[inserted_digit].first] >1){
					int seconds[11] = {0,},index=0;
					for(int j = 1; j<=digits,index <= count-i;j++){
						if( list_of_nums[j].second <=inserted_digit && list_of_nums[j].second >=inserted_digit - (count-i)){
							seconds[index++] = j;
							counted_number[list_of_nums[inserted_digit].first]--;
						}
					}
					index = 0;
					for(int j = inserted_digit; j > inserted_digit-(count-i+1);j--){
						input(list_of_nums[seconds[index++]],j);
					}	// i put but initialization ??..list_of_nums[seconds[index]].second = j;
					
				}
				int index = 1;
				while(list_of_nums[index].second != inserted_digit)
					index++;
				swap(list_of_nums[index],list_of_nums[inserted_digit]);
				i++;
			}
			else
				_digits--; //if it has not changed, then digits is minus.
		}
		sort(list_of_nums.begin(),list_of_nums.end(),cmp); //sorting for second.
		if(left_count % 2){
			if(counted_number[11] ==0)
				swap(list_of_nums[1],list_of_nums[2]);
			sort(list_of_nums.begin(),list_of_nums.end(),cmp); //sorting for second.
		}
	}
	string result = "";
	for(int i=1;i<=digits;i++){
		result = to_string(list_of_nums[i].first) +result;
	}
	for(int i=0;i<=11;i++)
		counted_number[i] = 0;
	return atoi(result.c_str());
}
