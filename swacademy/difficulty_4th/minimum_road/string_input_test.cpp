#include <iostream>
#include <string>
using namespace std;
int main(){
    int number;
    cin >>number;
    for(int i=0;i<number;i++){
        string input;
        cin >>input;
        for(int j=0; j<number;j++){
            int a = input[j] - '0';
            cout<<"a is :"<<a<<endl;
        }
    }
    return 0;
}
