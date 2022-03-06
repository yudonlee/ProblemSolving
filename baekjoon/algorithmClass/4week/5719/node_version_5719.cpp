//baekjoon online judge 100% score but it is wrong.
//why? this makes node impossible not "edges"
//but problem wants to make impossible edges! no nodes
//counterexample is this input
/*
 5 6
 0 4
 0 1 2
 0 2 2
 1 2 1
 2 4 2
 2 3 1
 3 4 2

 my output: -1
 true answer: 6
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 99999999
using namespace std;

typedef pair<long long, long long> pi;
typedef pair<pi, vector<long long> > pivt;

long long dist[501], visit[501];

int start, last;
int src, dest, weight;
bool middle;
int N, M;

void check_path(vector<vector<pi>> vt){

	memset(dist, 0, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	
	priority_queue<pivt, vector<pivt>, greater<pivt>> pq;
	pq.push({{0, start}, {start}});

	while(!pq.empty()){
		auto t = pq.top();
		long long accumulated = t.first.first;
		long long current_node = t.first.second;
		vector<long long> p = t.second;
		pq.pop();
		if(!dist[current_node]) dist[current_node] = accumulated;
		else if(dist[current_node] && current_node != last) continue;
		if(current_node == last) {
			if(dist[current_node] == accumulated) {
				for(auto node: p) {
					visit[node] = 1;
				}
				//this is start -> last. it is imposibble.
				if(p.size() == 2) {
					middle = true;
				}
			} else {
				break;
			}
		}
		for(auto it: vt[current_node]){
			long long expense = it.first;
			long long next_node = it.second;
			vector<long long> path(p);
			path.push_back(next_node);
			pq.push({{accumulated + expense, next_node}, path});
		}
	}

}
long long Dijkstra(vector<vector<pi>> vt) {
	memset(dist, -1, sizeof(dist));
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	
	pq.push({0, start});	
	for(int i = 0; i < N; i++) {
		if(i != start) pq.push({INF, i});
	}
	while(!pq.empty()){
		auto t = pq.top();
		long long accumulated = t.first;
		long long current_node = t.second;
		
		pq.pop();
		
		if(visit[current_node]) continue;

		if(dist[current_node] == -1) dist[current_node] = accumulated;
		else continue;
		for(auto v: vt[current_node]) {
	
			long long expense = v.first;
			long long next_node = v.second;
			if(!middle) pq.push({expense + accumulated, next_node});
			else {
				if(next_node != last || current_node != start) pq.push({expense + accumulated, next_node});
			}
		}
	}
	if(dist[last] == INF) return -1;

	return dist[last];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	while(cin >> N >> M) {
		if(N == 0 && M == 0) break;
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
		long long result = Dijkstra(vt);
		cout << result << "\n";
	}
	return 0;
}
