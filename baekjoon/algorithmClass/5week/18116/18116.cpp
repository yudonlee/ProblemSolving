#include <iostream>
using namespace std;

int robots[1000002];
int counts[1000002];

int Find(int node) {
    if(robots[node] == node) return node;
    return robots[node] = Find(robots[node]);
}
void Union(int left, int right) {
    int left_parent = Find(left);
    int right_parent = Find(right);
    if(left_parent != right_parent) {
        robots[right_parent] = left_parent;
        counts[left_parent] += counts[right_parent];
    }

}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, left, right, part;
    char command;
    cin >> N;
    for (size_t i = 0; i < 1000001; i++)
    {
        robots[i] = i, counts[i] = 1;
    }
    

    for (size_t i = 0; i < N; i++)
    {
        cin >> command;
        if(command == 'I') {
            cin >> left >> right;
            Union(left, right);           
        } else {
            cin >> part;
            cout << counts[Find(part)] << "\n";
        }
    }
    return 0;
}

