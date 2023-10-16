#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  string t; cin >> t;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ts = t.size();
  vector<int> m(ts+1);
  REP(i,n) {
    int p = ts-1;
    for(int j = s[i].size()-1; j >= 0; j--) if (s[i][j] == t[p]) p--;
    m[p+1]++;
  }

  vector<int> cs(ts+2); // 累積和
  REP(i,ts+1) cs[i+1] = cs[i] + m[i];
  reverse(cs.begin(),cs.end());

  ll ans = 0;
  REP(i,n) {
    int p = 0;
    REP(j,(int)s[i].size()) if (s[i][j] == t[p]) p++;
    ans += cs[ts-p];
  }
  cout << ans << endl;
  return 0;
}