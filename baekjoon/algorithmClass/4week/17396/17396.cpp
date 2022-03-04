#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<long long, int> pi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M; 
	int sight[100000] = {0, };
	int visit[100000] = {0, };
	long long dist[100000] = {0, };
	cin >> N >> M;
	
	dist[N - 1] = -1;
	for(int i = 0; i < N; i++) cin >> sight[i];
	sight[N - 1] = 0;

	int src, dest, weight;
	vector<vector<pi>> vt(100000, vector<pi>(0));
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		if((!sight[src]) && (!sight[dest])) {
			//cout << "push\n" << src << ", " << dest << "\n";
			vt[src].push_back({weight, dest});
			vt[dest].push_back({weight, src});
		}
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, 0});
	
	while(!pq.empty()){
		auto it = pq.top();
		pq.pop();
		long long accumulated = it.first;
		int current_node = it.second;
		
		if(visit[current_node]) continue;

		visit[current_node] = true;
		dist[current_node] = accumulated;
		//cout << "current node and accumulated: " << current_node << ", "  << accumulated << "\n";	
		for(auto v: vt[current_node]) {
			long long expense = v.first; 
			int next_node = v.second;
			pq.push({expense + accumulated, next_node});
		}
	}
	cout << dist[N - 1] << "\n";
	return 0;

}
