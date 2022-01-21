#include<iostream>
#include <bitset>
using namespace std;

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int test_case;
	int T;
  cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
  int N, M;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> N >> M;
    bool status = true;
    int compare = (1 << N) - 1;
    if(compare != (compare & M)) {
        status = false;
    }
    if(!status) cout << "#" << test_case << " OFF\n";
    else cout << "#" << test_case << " ON\n";
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
