#include <iostream>
#include <vector>
#define INF 99999999999
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;
long long dist[101][101];
//3차 vector int.
vector<vector<vector<int> > > vt(101, vector<vector<int>>(101, vector<int>(0)));

int main(){
	int N, M;
	cin >> N >> M;
	int src, dest, weight;
	fill(&dist[0][0], &dist[100][101], INF);
	for(int i = 1; i <= N; i++) dist[i][i] = 0;
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		if(dist[src][dest] == INF) {
			dist[src][dest] = weight;
			vt[src][dest] = {src, dest};
		} else if(dist[src][dest] > weight) {
			dist[src][dest] = weight;
			vt[src][dest] = {src, dest};
		}
	}
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				//dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
//					cout << i << ", " << j << "is bigger than " << i << ", " << k << ", " << j << "\n";
					vector<int> new_path;
					for(auto it: vt[i][k]) {
						if(it != k) new_path.push_back(it);
					} 
					for(auto it: vt[k][j]) new_path.push_back(it);
					vt[i][j] = new_path;
				}
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(dist[i][j] == INF) dist[i][j] = 0;		
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(dist[i][j] != 0) {
				cout << vt[i][j].size() << " ";
				for(auto it: vt[i][j]) cout << it << " ";
				cout << "\n";
			} else cout << "0\n";
		}
	}
	return 0;
}
