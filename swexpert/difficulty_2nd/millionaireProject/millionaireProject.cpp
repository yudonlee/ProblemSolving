#include <iostream>
#include <vector>
using namespace std;
int solution(int* n,int count);
int main(){
    int count,number;
    cin >>number;
    for(int i=0; i<number;i++){
        cin >>count;
        cout << "segv"<<endl;
        int *n = new int[count+1];
        for(int j=0;j<count;j++){
            cin >> n[j];
        }
        int result = solution(n,count);
        cout <<"#"<<i+1<<" "<<result<<endl;
    }
    return 0;
}
int solution(int* n,int count){
    vector<int> point;
    int max = n[count-1];
    int profit = 0;
    int index = 0;
    for(int i=count-1;i>=0;i--){
        if(max <= n[i]){
            max = n[i];
            point.push_back(i);
        }
    }
    while(!point.empty()){
        int max_point = point.back();
        point.pop_back();
        for(int i = index; i < max_point;i++){
            profit += n[max_point] - n[i];
        }
        index = max_point+1;
    }
    return profit;
}
