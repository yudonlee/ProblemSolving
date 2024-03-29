/*
 해당 코드는, 노드의 재방문을 막으면서도, 해당 노드까지 가는 무수히 많은 간선들이 존재하고, 해당 노드에서 도착지점까지 갔을떄 최솟값을 가지는 경우의 예외처리를 해주었다.
 일단 노드 재방문시, continue를 통해서 다시 while loop의 condition check로 돌아간다. 그전에, 만약 해당 노드까지 온 weight가 동일하다면 이들의 edgees list를 별도로 저장한다. 그리고 만약 해당 노드가 최소거리를 갖는 road에서의 node라면 별도로 저장한 edges를 가져와서 disable 시켜주는것이다. 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 99999999
using namespace std;

typedef pair<long long, int> pli;
typedef pair<int, int> pi;
typedef pair<pli, vector<pi>> plivt;
bool visit[501][501];
long long dist[501];
int start_node, last_node;
int N, M;

void CheckPath(vector<vector<pi>> vt) {
	memset(dist, 0, sizeof(dist));
	priority_queue<plivt, vector<plivt>, greater<plivt>> pq;
	vector<vector<pi>> duplicate_vt(501, vector<pi>(0));	

	pq.push({{0, start_node}, {}});
	while(!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		long long accumulated = t.first.first;
		int current_node = t.first.second;
		vector<pi> p = t.second;
		
		if(dist[last_node] && dist[last_node] < accumulated) break;
		
		if(!dist[current_node]) dist[current_node] = accumulated;
		else if(current_node != last_node) {
			if(dist[current_node] == accumulated) {
				for(auto itr: p) duplicate_vt[current_node].push_back(itr);
			}
			continue;	
		}
		if(current_node == last_node) {
			if(dist[current_node] == accumulated) {
				for(auto node: p) {
					for(auto dup: duplicate_vt[node.first]) {
						visit[dup.first][dup.second] = false;
					}
					visit[node.first][node.second] = false;
				}
			} else break;
		}
		
		for(auto it: vt[current_node]) {
			long long expense = it.first;
			int next_node = it.second;
			vector<pi> path(p);
			path.push_back({current_node, next_node});
			pq.push({{accumulated + expense, next_node}, path});
		}		
	}	
}

long long Dijkstra(vector<vector<pi>> vt) {
	memset(dist, -1, sizeof(dist));
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, start_node});

	for(int i = 0; i < N; i++) {
		if(i != start_node) pq.push({INF, i});
	}
	while(!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		long long accumulated = t.first;
		int current_node = t.second;
		
		if(dist[current_node] == -1) dist[current_node] = accumulated;
		else continue;
		if(dist[last_node] != -1) break;
		for(auto v: vt[current_node]) {
			long long expense = v.first;
			int next_node = v.second;
			if(visit[current_node][next_node]) {
				pq.push({expense + accumulated, next_node});
			}
		}
	}
	if(dist[last_node] == INF) return -1;
	return dist[last_node];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int src, dest, weight;

	while(cin >> N >> M) {
		if(N == 0 && M == 0) break;
		memset(visit, 0, sizeof(visit));
		cin >> start_node >> last_node;
		vector<vector<pi>> vt(501, vector<pi>(0));
		
		for (int i = 0; i < M; i++) {
			cin >> src >> dest >> weight;
			vt[src].push_back({weight, dest});
			visit[src][dest] = true;
		}
		CheckPath(vt);
		long long result = Dijkstra(vt);
		cout << result << "\n";	
	}
}




