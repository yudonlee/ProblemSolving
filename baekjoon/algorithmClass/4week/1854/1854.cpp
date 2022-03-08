#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

//dist는 최대 100가지가 나올수 있으며, 차례로 distance를 입력해주는것이 좋을것 같다.
long long dist[1001][101];
long long dist_index[1001];
typedef pair<long long, int> pli;
//typedef pair<pli, vector<bool>> plivt;
vector<vector<pli>> vt(1001, vector<pli>(0));
int N, M, K;

void Dijkstra(){
	memset(dist, -1, sizeof(dist));
	memset(dist_index, 0, sizeof(dist_index));
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, 1});
	
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		long long accumulated = t.first;
		int current_node = t.second;
		//이 부분을 dist[][] update 하는 line 밑에 둔다면, segment fault가 발생할수 있기 때문에 주의해야한다.
		if(dist_index[current_node] > K) continue;
		
		dist[current_node][dist_index[current_node]++] = accumulated;
		
		for(auto v: vt[current_node]) {
			long long expense = v.first;
			int next_node = v.second;
			if(dist_index[next_node] < K) pq.push({expense + accumulated, next_node});
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	int src, dest, weight;
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		vt[src].push_back({weight, dest});
	}
	Dijkstra();
	for(int i = 1; i <= N; i++) cout << dist[i][K - 1] << "\n";
	return 0;
}

