class Stack {
private: 
    int top;
    int stacks[41];
public: 
  Stack() {
    top = -1;
  }
  bool isEmpty() {
    if(top == -1) return true;
    return false;
  }
  bool isFull() {
    if(top == 40) return true;
    return false;
  }
  void push(int element){
    if(!isFull()) stacks[++top] = element;
  }
  int pop(){
    if(!isEmpty()) return stacks[top--];
    return -1;
  }
};

int parents[100][5];
int childs[100];
void dfs_init(int N, int path[100][2])
{ 
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 5; j++) parents[i][j] = 0;
    childs[i] = 0;
  }
  for(int i = 0; i < N - 1; i++) {
    int pn = path[i][0];
    int cn = path[i][1];
    parents[pn][childs[pn]++] = cn;
  }

}

int dfs(int n)
{
  int result = 0;
  bool check[100] = {0, };
  Stack stacks;
  stacks.push(n);
  while(!stacks.isEmpty() && result < n) {  
    int next = stacks.pop();
    
    if(next > n) return next;
    
    if(!check[next]){
      check[next] = true;
      int count = childs[next];
      for(int i = childs[next] - 1; i >= 0; i--) {
        stacks.push(parents[next][i]);
      }
    }
 
  }
  return -1;
}

