/*
 해당 코드는 메모리초과 이슈가 발생한다.
 input_2.txt의 예시와 같이, 특정 노드까지 최솟값을 갖는 여러개의 길이 존재하고 해당 노드로부터 도착지점까지 한방향의 길만 가진다고 가정해보자.
 이것이 무수하게 커질때, 우린 불필요한 연산을 계속해서 하게 된다. 따라서 특정 노드에 집결한 여러가지 간선들이, 특정 노드에서 도착지점까지 가는 경우, 반복된 노드 방문을 피하여 간선을 저장해줘야한다. 
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
	
	pq.push({{0, start_node}, {}});
	while(!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		long long accumulated = t.first.first;
		int current_node = t.first.second;
		vector<pi> p = t.second;
		
		if(!dist[current_node]) dist[current_node] = accumulated;
    else if(dist[current_node] < accumulated) continue;
		

		if(current_node == last_node) {
			if(dist[current_node] == accumulated) {
				for(auto node: p) {
					visit[node.first][node.second] = false;
				}
			} else break;
		}
		
		if(!dist[last_node] && dist[last_node] < accumulated) break;
		
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

