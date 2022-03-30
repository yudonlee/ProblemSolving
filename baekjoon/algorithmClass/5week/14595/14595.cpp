#include <iostream>
using namespace std;

int parents[1000001];
int last;
int Find(int node){
    if(parents[node] == node) return node;
    return parents[node] = Find(parents[node]);
}
void Union(int left, int right) {
    int left_parent = Find(left);
    int right_parent = Find(right); 
    
    // for (int i = left; i != right; i = Find(i + 1)) {
    //     parents[right_parent] = left_parent;
    //     cnt[left] += cnt[right];
    // }
}
int main(){ 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, x, y;
    cin >> N >> M;
    
    last = N;
    for(int i = 0; i <= N; i++) parents[i] = i;
    
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }
    cout << last << "\n";
}