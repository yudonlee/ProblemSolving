#include <iostream>
using namespace std;

int parents[1000001];

int Find(int node) {
    if(parents[node] == node) return node;
    return parents[node] = Find(parents[node]);
}

void Union(int left, int right){
    int left_parent = Find(left);
    int right_parent = Find(right);
    parents[left_parent] = right_parent;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, command, left, right;
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> command >> left >> right;
        if (command)
        {
            if(Find(left) == Find(right)) cout << "YES\n";
            else cout << "NO\n";
        }
        else Union(left, right); 
    }
    return 0;
}