#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const vector<int> days =  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int calc(int y, int m, int d) {
  int ret = (y-1) * 365;
  // 閏年分
  ret += (y-1) / 4 - (y-1) / 100 + (y-1)/400;
  REP(i,m) ret += days[i];
  // 閏年分
  if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
    if (m > 2) ret++;
  }
  ret += d;

  return ret;
}

int main() {
	int s1,s2,s3,t1,t2,t3;
	scanf("%d-%d-%d %d-%d-%d",&s1,&s2,&s3,&t1,&t2,&t3);

  int s = calc(s1,s2,s3) - calc(2022,1,1)+1;
  int t = calc(t1,t2,t3) - calc(2022,1,1)+1;

  int ans = 0;
  ans += (t+6) / 7 - (s+5) / 7;
  ans += (t+5) / 7 - (s+4) / 7;
  cout << ans << endl;
  return 0;
}