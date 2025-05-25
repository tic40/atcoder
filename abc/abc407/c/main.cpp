#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int n = s.size();
  reverse(s.begin(),s.end());

  int cnt = 0;
  int ans = 0;
  REP(i,n) {
    int x = s[i]-'0';
    x -= cnt;
    x = (x+10)%10;
    cnt += x;
    cnt %= 10;
    ans += x+1;
  }

  cout << ans << endl;
  return 0;
}