#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#define NOT_VISIT -1
using namespace std;

typedef struct Point{
	int xpos;
	int ypos;
    int expense;
}Point;

int _move[100][100];
int costs[100][100];
int minimum_road(int size);
bool isUp(int x,int y,int size){
    if(x > 0)
        return true;
    return false;
};
bool isDown(int x,int y,int size){
    if(x < size -1)
        return true;
    return false;
};
bool isLeft(int x,int y,int size){
    if(y > 0)
        return true;
    return false;
};
bool isRight(int x,int y,int size){
    if(y < size -1)
        return true;
    return false;
};
int main(){
	int test_case,size;
	cin >> test_case;
	for(int i=0; i<test_case;i++){
		cin >> size;
		for(int j=0;j<size;j++){
            string input;
            cin >> input;
            for(int k=0; k<size;k++){
                costs[j][k] = input[k]-'0';
                _move[j][k] = NOT_VISIT;
            }
        }
        /*string input;
        for(int j=0; j<size;j++){
			for(int k=0;k<size;k++){
				cin >> costs[j][k];
                _move[j][k] = NOT_VISIT;
            }
		}*/
		int result = minimum_road(size);
        cout <<"#"<<i+1<<" "<<result<<endl;
	}
	return 0;
}
int minimum_road(int size){
	int value = 0;
    queue<Point> ptr;
	ptr.push({0,0,0});
    _move[0][0] = 0;
    while(!ptr.empty()){
		Point visit = ptr.front();
        ptr.pop();
		if(isUp(visit.xpos,visit.ypos,size)){
           if(_move[visit.xpos-1][visit.ypos] == NOT_VISIT || _move[visit.xpos-1][visit.ypos] > costs[visit.xpos-1][visit.ypos] + visit.expense){
               _move[visit.xpos-1][visit.ypos] = costs[visit.xpos-1][visit.ypos] + visit.expense;
               ptr.push({visit.xpos-1,visit.ypos,visit.expense + costs[visit.xpos-1][visit.ypos]});
           }
        } 
		if(isDown(visit.xpos,visit.ypos,size)){
           if(_move[visit.xpos+1][visit.ypos] == NOT_VISIT || _move[visit.xpos+1][visit.ypos] > costs[visit.xpos+1][visit.ypos] + visit.expense){
               _move[visit.xpos+1][visit.ypos] = costs[visit.xpos+1][visit.ypos] + visit.expense;
               ptr.push({visit.xpos+1,visit.ypos,visit.expense + costs[visit.xpos+1][visit.ypos]});
           }
        } 
		if(isLeft(visit.xpos,visit.ypos,size)){
           if(_move[visit.xpos][visit.ypos-1] == NOT_VISIT || _move[visit.xpos][visit.ypos-1] > costs[visit.xpos][visit.ypos-1] + visit.expense){
               _move[visit.xpos][visit.ypos-1] = costs[visit.xpos][visit.ypos-1] + visit.expense;
               ptr.push({visit.xpos,visit.ypos-1,visit.expense + costs[visit.xpos][visit.ypos-1]});
           }
        } 
		if(isRight(visit.xpos,visit.ypos,size)){
           if(_move[visit.xpos][visit.ypos+1] == NOT_VISIT || _move[visit.xpos][visit.ypos+1] > costs[visit.xpos][visit.ypos+1] + visit.expense){
               _move[visit.xpos][visit.ypos+1] = costs[visit.xpos][visit.ypos+1] + visit.expense;
               ptr.push({visit.xpos,visit.ypos+1,visit.expense + costs[visit.xpos][visit.ypos+1]});
           }
        } 
    }
    return _move[size-1][size-1];
}
