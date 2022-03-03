#include <iostream>
#include <queue>
#include <cstring>

#define INF 987654321

using namespace std;
typedef pair<int, int> pi;
int dist[20001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E, start_node;
	
	vector<vector<pi>> vt(20001, vector<pi>(0));
	memset(dist, -1, sizeof(dist));
	cin >> V >> E >> start_node;
	
	int src, dest, weight;
	for(int i = 0; i < E; i++) {
		cin >> src >> dest >> weight;
		vt[src].push_back({dest, weight});
	}
	priority_queue<pair<int, int>, vector<pi>, greater<pi> > pq;

	pq.push({0, start_node});
	for(int i = 1; i <= V; i++) {
		if(i != start_node) pq.push({INF, i});
	}
	while(!pq.empty()){
		auto it = pq.top();
		int current_node = it.second;
		
		int accumulated = it.first;
		pq.pop();

		if(dist[current_node] == -1) dist[current_node] = accumulated;
		else continue;

		for(auto edges: vt[current_node]){
			pq.push({edges.second + accumulated, edges.first});
		}
	}

	for(int i = 1; i <= V; i++) {
		if(dist[i] != INF) cout << dist[i] << "\n";
		else cout << "INF\n"; 
	}
	return 0;
}
