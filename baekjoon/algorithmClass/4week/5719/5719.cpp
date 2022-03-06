#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, vector<int> > pivt;

int dist[501], visit[501];

int start, last;
int src, dest, weight;
bool middle;


void check_path(vector<vector<pi>> vt){

	memset(dist, 0, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	/*
	vector<vector<pi>> vt(501, vector<pi>(0));	
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		vt[src].push_back({weight, dest});
	}*/
	
	priority_queue<pivt, vector<pivt>, greater<pivt>> pq;
	pq.push({{0, 0}, {start}});

	vector<int> result; 
	while(!pq.empty()){
		auto t = pq.top();
		int accumulated = t.first.first;
		int current_node = t.first.second;
		vector<int> p = t.second;
		pq.pop();
		if(!dist[current_node]) dist[current_node] = accumulated;
		else if(dist[current_node] && current_node != last) continue;
		if(current_node == last) {
			if(dist[current_node] == accumulated) {
				for(auto node: p) {
					//cout << "node: " << node << "\n";
					visit[node] = 1;
				}
				if(p.size() == 2) {
					//cout << "middle true\n";
					middle = true;
				}
			} else {
				break;
			}
		}
		for(auto it: vt[current_node]){
			int expense = it.first;
			int next_node = it.second;
			vector<int> path(p);
			path.push_back(next_node);
			pq.push({{accumulated + expense, next_node}, path});
		}
	}

}
int Dijkstra(vector<vector<pi>> vt) {
	memset(dist, -1, sizeof(dist));
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	
	pq.push({0, start});
	/*if(!middle) {
		pq.push({0, start});
	} else {
		for(auto it: vt[start]) {
			int expense = it.first;
			int next = it.second;
			if(next != last) pq.push({expense, next});
		}
	}	*/
	while(!pq.empty()){
		auto t = pq.top();
		int accumulated = t.first;
		int current_node = t.second;
		//cout << "accum and node: "<< accumulated << ", " << current_node << "\n";
		pq.pop();
		
		if(visit[current_node]) continue;

		if(dist[current_node] == -1) dist[current_node] = accumulated;
		else continue;
		for(auto v: vt[current_node]) {
	
			int expense = v.first;
			int next_node = v.second;
			if(!middle) pq.push({expense + accumulated, next_node});
			else {
				if(next_node != last || current_node != start) pq.push({expense + accumulated, next_node});
			}
		}
	}
	return dist[last];
}
int main() {
	int N, M; 
	while(cin >> N >> M) {
		if(N == 0 && M == 0) {
			//cout << "NM\n";
			break;
		}
		
		cin >> start >> last;
		
		vector<vector<pi>> vt(501, vector<pi>(0));	
		for(int i = 0; i < M; i++) {
			cin >> src >> dest >> weight;
			vt[src].push_back({weight, dest});
		}
		middle = false;
		check_path(vt);
		visit[start] = 0;
		visit[last] = 0;
		int result = Dijkstra(vt);
		cout <<result << "\n";
	}
	return 0;
}
