#include <iostream>
#include <vector>
#include <string>
using namespace std;
string alphabets = "abcdefghijklmnopqrstuvwxyz";
int indexs[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

int L, C;
int used_alphabet[26] = {0, };
void dfs(vector<int> nodes, int index){
  
  if(nodes.size() == L) {
    string output = "";
    int count[2] ={0,};
    for(auto it: nodes) {
        output += alphabets[it];
        count[indexs[it]]++;
    }
    if(count[0] > 1 && count[1] > 0) cout << output << "\n";
    return;
  } 
  if(index == C) return;
  
  vector<int> no = nodes;
  nodes.push_back(used_alphabet[index]);
  dfs(nodes, index + 1);
  dfs(no, index + 1);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> L >> C;
  char input;
  for(int i = 0; i <C; i++) {
      cin >> input;
      used_alphabet[i] = input - 'a';
      
  }
  sort(used_alphabet, used_alphabet + C);
  vector<int> nodes;
  dfs(nodes, 0);
  return 0;
}
