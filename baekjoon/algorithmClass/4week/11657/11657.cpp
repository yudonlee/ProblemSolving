#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct Edge {
	int src;
	int dest;
	int weight;

} edges[6000];

long long dist[501];
int N, M;

bool BellmanFord(){
	dist[1] = 0;
	bool ret = true;

	for (int i = 1; i < N; i++) {
		for(int j = 0; j < M; j++) {
				auto e = edges[j];
			if ( dist[e.src] == INF) {
				continue;		
			} else if ( dist[e.dest] > dist[e.src] + e.weight) { 
				dist[e.dest] = dist[e.src] + e.weight;
			}
		}
	}
	
	for(int i = 0; i < M; i++) {
		auto e = edges[i];
		if(dist[e.src] == INF) continue;
		else if(dist[e.dest] > dist[e.src] + e.weight) return false;
	}
	return ret;
}

int main(){
	cin >> N >> M;
	int s, d, w;
	fill(dist, dist + 501, INF);
	for(int i = 0; i < M; i++) {
		cin >> s >> d >> w;
		edges[i] = {s, d, w};
	}
	
	if ( BellmanFord() ) {
		for(int i = 2; i <= N; i++) {
			if( dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
	else cout << "-1\n";

	return 0;
}
