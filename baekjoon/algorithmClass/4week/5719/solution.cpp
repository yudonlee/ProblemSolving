#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, vector<int> > pivt;


int main(){
	vector<vector<pi>> vt(501, vector<pi>(0));
	int dist[501] = {0,};
	int visit[501] = {0, };
	int N, M;
	cin >> N >> M;
	int start, end;
	cin >> start >> end;
	
	int src, dest, weight;
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		vt[src].push_back({weight, dest});
	}
	
	priority_queue<pivt, vector<pivt>, greater<pivt>> pq;
	//vector<int> params = {0};
	pq.push({{0, 0}, {0}});

	vector<int> result;
	while(!pq.empty()){
		auto t = pq.top();
		int accumulated = t.first.first;
		int current_node = t.first.second;
		vector<int> p = t.second;
		pq.pop();
		if(!dist[current_node]) dist[current_node] = accumulated;
		if(current_node == end) {
			if(dist[current_node] == accumulated) {
//				cout << "dist:" << dist[current_node] << "accumulated: " << accumulated << "\n";
				for(auto node: p) {
					visit[node] = 1;
	//				cout << "node: " << node << "\n";	
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
	cout << "output " << output << "\n";
}

