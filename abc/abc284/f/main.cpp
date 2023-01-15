#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string t; cin >> n >> t;
  string s = t.substr(0,n);
  t = t.substr(n);
  reverse(t.begin(),t.end());

  string a = s+t;
  string b = t+s;
  auto za = z_algorithm(a);
  auto zb = z_algorithm(b);

  REP(i,n) {
    if (i && za[n*2-i] != i) continue;
    int j = n-i;
    if (zb[n*2-j] != j) continue;

    string ans = s.substr(0,i);
    reverse(s.begin(),s.end());
    ans += s.substr(0,j);
    cout << ans << endl;
    cout << i << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}