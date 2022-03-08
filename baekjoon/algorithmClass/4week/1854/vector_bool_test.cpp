#include <iostream>
#include <vector>
using namespace std;

int main(){
	//vector bool은 초기화된 값으로 나타난다.

	vector<int> vt(500);
	//vector<bool> vt(500);
	for(auto v: vt) cout << v << "\n";
	return 0;
}
