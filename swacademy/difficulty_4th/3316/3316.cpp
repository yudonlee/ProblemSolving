#include<iostream>
#include <map>
using namespace std;

char members[4] = {'A', 'B', 'C', 'D'};
map<char, int> matches;
char input[10001];
int end_day;
long long cases;

long long days[10001][16];
long long divisor = 1000000007;

/*재귀적 호출로 인해 발생하는 약 100만번의 함수호출은 너무나 많은 시간지연을 유발한다.
void count(int set, int day){
  if(day == end_day - 1) {
      if (matches[input[end_day - 1]] & set) {
          cases++;
          cases %= divisor;
      }
      return;
  }
  for(int subset = 0; subset < (1 << 4); subset++) {
    //이전날과 겹치는 멤버가 하나라도 존재하고, 책임자가 일치할때 다음날 탐색
    if((subset & set) && (matches[input[day]] & subset)) count(subset, day + 1);
  }
}
*/
int main(int argc, char** argv)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;
  matches.insert({'A', (1 << 3)});
  matches.insert({'B', (1 << 2)});
  matches.insert({'C', (1 << 1)});
  matches.insert({'D', (1 << 0)});

	for(test_case = 1; test_case <= T; ++test_case)
	{
    cin >> input;
    end_day = strlen(input);
    cases = 0;
    memset(days, 0, sizeof(days));

    for(int day = 0; day < end_day; day++) {
	    for(int i = 1; i < (1 << 4); i++) {
        //첫날이 아닐 때, 그 전날의 경우의 수를 반영해야한다.
        if(day != 0) {
          for(int j = 1; j < (1 << 4); j++) {
            //전날 j값이 사용되었다면, 이를 근거로 오늘의 경우의 수를 만드는게 가능하다.
            if(days[day - 1][j] != 0) {
              //i와 j가 같은 부분집합을 가지고 있고, day번째 책임자가 i값의 비트로 존재한다면 사용 가능한 경우의 수이다. 
              // 이때 day-1번째 j값이 될 수 있는 경우의 수를 더해줘야 한다.
              // day - 1 지역의 j까지 갈수 있는 경우의 수가 10가지이고, 해당 지역에서 day 지역의 i까지 갈 수 있는 경우의 수가 1개라면 시작점에서 i까지 갈 수 있는 경우의 수는 10개이기 때문이다.
              if((i & j) && (matches[input[day]] & i)) {
                  days[day][i] += days[day-1][j]; 
                  days[day][i] %= divisor;
              }
            }
          }
        }

        else {
          if((matches[input[day]] & i) && (matches['A'] & i)) days[day][i] = 1;
        }
      }
    }

    for(int i = 1; i < (1 << 4); i++) {
      cases += days[end_day - 1][i];
      cases %= divisor;
    }
    cout << "#" << test_case << " " << cases << "\n";
  }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
