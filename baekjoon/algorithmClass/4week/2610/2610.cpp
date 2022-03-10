//it is wrong source code. i need to fix it!
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#define INF 100000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;

int group[101];
int dist[101][101];
int group_number;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, src, dest;
	group_number = 1;
	cin >> N >> M;
	memset(group, 0, sizeof(group));
	memset(dist, 0, sizeof(dist));
	fill(&dist[0][0], &dist[100][101], INF);		
	for(int i = 1; i <= N; i++) dist[i][i] = 0;
	vector<vector<int> > vt(101, vector<int>(0));

	for(int i = 0; i < M; i++) {
		cin >> src >> dest;
		dist[src][dest] = 1;
		dist[dest][src] = 1;
		if(group[src] == 0 && group[dest] == 0) {
			vt[group_number].push_back(src);
			vt[group_number].push_back(dest);
			group[src] = group_number;
			group[dest] = group_number++;
		}
		else if(!group[src]) {
			group[src] = group[dest];
			vt[group[src]].push_back(src);
		} else if(!group[dest]) {
			group[dest] = group[src];
			vt[group[dest]].push_back(dest);
		} 
	}
	for(int i = 1; i <= N; i++) {
		if(!group[i]) {
			group[i] = group_number;
			vt[group_number++].push_back(i);
		}
	}

	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	

	set<int> leaders;	
	
	for(int i = 1; i < group_number; i++) {
		int group_max_min = INF;
		int max_min_node = -1;
		sort(vt[i].begin(), vt[i].end());

		for(auto lead : vt[i]) {
			int max_length = -1;
			for(auto follower: vt[i]) {
				max_length = MAX(max_length, dist[follower][lead]);
			}
			if(max_length < group_max_min) {
				group_max_min = max_length;
				max_min_node = lead; 
			}
		}
		leaders.insert(max_min_node);
	}
	cout << group_number - 1 << "\n";
	for(auto it: leaders) cout << it << "\n";
	return 0;
}
