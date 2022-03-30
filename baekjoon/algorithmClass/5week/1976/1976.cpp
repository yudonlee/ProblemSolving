#include <iostream>
using namespace std;

int parents[201];
int Find(int node) {
    if(parents[node] == node) return node;
    return node = Find(parents[node]);
}

void Union(int left, int right) {
    int left_parents = Find(left);
    int right_parents = Find(right);
    if(left_parents < right_parents) parents[right_parents] = left_parents;
    else parents[left_parents] = right_parents;
}
int main(){

    int N, M, command;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) parents[i] = i;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
           cin >> command;
           if(command) Union(i, j);
        }
    }
    bool status = true;
    int city, root;
    for(int i = 0; i < M; i++) {
        cin >> city;
        if(i == 0) root = Find(city);
        if(root != Find(city)) status = false;
    }

    if(status) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}