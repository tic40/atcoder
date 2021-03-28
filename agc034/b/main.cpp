#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  string s,t;
  cin >> s;

  REP(i,s.size()) {
    if (s[i]=='B' && s[i+1]=='C') {
      t+='X';
      i++;
    } else {
      t+=s[i];
    }
  }

  ll ans = 0, cnt = 0;
  REP(i,t.size()) {
    if (t[i] == 'A') cnt++;
    else if (t[i] == 'X') ans += cnt;
    else cnt=0;
  }

  cout << ans << endl;
  return 0;
}