#include <iostream>
#include <vector>
#include <queue>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;
//제일 위에 조상
int ancestor[101] = {0, };

//부모
int parents[101] = {0, };
// 조상으로부터의 거리 
int dist[101] = {0, };
// src에서 조상들의 거리의 집합(ex. 아버지-나: 1, 할아버지- 나: 2)
int relatives[101] = {0, };

int distance(int src, int dest){
  // 조상이 다르다면 친척이 아님.
  if(ancestor[src] != ancestor[dest]) return -1;

  int min = dist[src] + dist[dest]; //root에서 촌수(max value)
  

  int relative = 1;
  int start = src;
  //특정 조상으로부터 src까지의 거리
  while(start != ancestor[src]){
    int parent = parents[start];
    relatives[parent] = relative++;
    start = parent;
  }
  
  start = dest;
  relative = 1;
  //특정 조상이 공통될때 min(src에서의 촌수 + dest에서의 촌수)이 곧 촌수가 된다.
  while(start != ancestor[dest]) {
    int parent = parents[start];
    //공통된 조상이 존재할 때 거리.
    if(relatives[parent] != 0) {
      min = MIN(min, relative + relatives[parent]);
    }
    start = parent;
    relative++;
  }
  return min;
}

int main(){
  int n, src, dest;
  int relatives, parent, child;
  cin >> n >> src >> dest >> relatives;
  for(int i = 0; i < relatives; i++) {
    cin >> parent >> child;
    if(ancestor[parent] == 0) {
        ancestor[parent] = parent;
        parents[parent] = parent;
        dist[parent] = 0;
    }
    //root 조상
    ancestor[child] = ancestor[parent];
    //나의 부모 index
    parents[child] = parent;
    //root 조상으로부터의 거리
    dist[child] = dist[parent] + 1;

  }
  cout << distance(src, dest) << "\n";
}
