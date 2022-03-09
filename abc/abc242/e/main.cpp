#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using mint = modint998244353;

vector<mint> pw(1000000/2);

void solve(int n, string s) {
  int l = (n+1)/2;
  mint ans = 0;
  REP(i,l) {
    int x = s[i] - 'A';
    ans += pw[l-i-1] * x;
  }

  string t1 = s.substr(0,l);
  string t2 = s.substr(0,n/2);
  reverse(t2.begin(),t2.end());
  string t = t1+t2;

  if (t <= s) ans++;
  cout << ans.val() << endl;

  return;
}

int main() {
  int t; cin >> t;
  pw[0] = 1;
  REP(i,1000000/2) pw[i+1] = pw[i]*26;

  REP(i,t) {
    int n; string s;
    cin >> n >> s;
    solve(n,s);
  }

  return 0;
}