#include <iostream>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 99999999999
using namespace std;

long long roads[101][101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(&roads[0][0], &roads[100][101], INF);
	int N, M;
	cin >> N >> M;

	for(int i = 1; i <= N; i++) roads[i][i] = 0;
	int src, dest;
  long long	weight;
	for(int i = 0; i < M; i++) {
		cin >> src >> dest >> weight;
		roads[src][dest] = MIN(roads[src][dest], weight);
	}
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				roads[i][j] = MIN(roads[i][j], roads[i][k] + roads[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(roads[i][j] != INF) cout << roads[i][j] << " ";
			else cout << "0 ";
		}
		cout << "\n";
	}
	return 0;
}
