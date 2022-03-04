#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;
//first is weight, second is destination.
typedef pair<int, int> pi; 
vector<vector<pi> > vt(1001, vector<pi>(0));
int dist[1001];
int dest_dist[1001];
int N, M, X;

int Dijkstra(int start_node){
	memset(dist, -1, sizeof(dist));
	priority_queue<pi, vector<pi>, greater<pi>> pq;

	for(int i = 1; i <= N; i++) {
		if(i != start_node) pq.push({INF, i});
		else pq.push({0, i});
	}
	
	while(!pq.empty()){
		auto it = pq.top();
		int accumulated = it.first;
		int current_node = it.second;
		pq.pop();
		if(dist[current_node] == -1) dist[current_node] = accumulated;
		else continue;
		if(current_node == X) break;
		for(auto it: vt[current_node]) {
			int next_node = it.second;
			int distance = accumulated + it.first;
			pq.push({distance, next_node});
		}
	}

	return dist[X];

}
void cal_dest_to_src(){
	memset(dest_dist, -1, sizeof(dest_dist));
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	for(int i = 1; i <= N; i++) {
		if(i != X) pq.push({INF, i});
		else pq.push({0, X});
	}

	while(!pq.empty()){
		auto it = pq.top();
		int accumulated = it.first;
		int current_node = it.second;
		pq.pop();
		if(dest_dist[current_node] == -1) dest_dist[current_node] = accumulated;
		else continue;
		for(auto it: vt[current_node]) {
			int next_node = it.second;
			int distance = accumulated + it.first;
			pq.push({distance, next_node});
		}
	}
}
int main(){
	cin >> N >> M >> X;
	int src, dest, weight;
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		vt[src].push_back({weight, dest});
	}
	
	cal_dest_to_src();	
	int result = -1;
	int tmp = -1;
	for(int i = 1; i <= N; i++) {
		if(i != X){ 
			tmp = Dijkstra(i) + dest_dist[i];
			//cout << "from " << i << " weight is: " << tmp << "\n";
		}
		if(tmp > result) result = tmp;
	}
	cout << result << "\n";
}
