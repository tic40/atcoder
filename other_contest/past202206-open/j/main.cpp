#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

const vector<int> days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// 何日経過しているか
int calc(int y, int m, int d) {
  int res = (y - 1) * 365;
  res += (y-1)/4 - (y-1)/100 + (y-1)/400;

  for(int i = 1; i < m; i++) res += days[i];
  // 閏年
  if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
    if (m > 2) res++;
  }

  res += d;
  return res;
}

int main() {
  string s,t; cin >> s >> t;
  int s1 = stoi(s.substr(0,4));
  int s2 = stoi(s.substr(5,2));
  int s3 = stoi(s.substr(8,2));
  int t1 = stoi(t.substr(0,4));
  int t2 = stoi(t.substr(5,2));
  int t3 = stoi(t.substr(8,2));

  int d1 = calc(s1,s2,s3) - calc(2022,1,1) + 1;
  int d2 = calc(t1,t2,t3) - calc(2022,1,1) + 1;

  int ans = 0;
  // 土曜日
  ans += (d2+6)/7 - (d1+5)/7;
  // 日曜日
  ans += (d2+5)/7 - (d1+4)/7;
  cout << ans << endl;
  return 0;
}