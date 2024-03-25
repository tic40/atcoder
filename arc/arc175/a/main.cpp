#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353; // modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) { cin >> p[i]; p[i]--; }
  string s; cin >> s;

  vector<int> m(n);
  auto check = [&](int i, char lorr) {
    int l = m[i], r = m[(i+1)%n];
    if (lorr == 'L') {
      m[i] = 1;
      if (l || (!l && !r && s[i] == 'R')) return 0;
      if (!l && r && s[i] == '?') return 2;
    } else {
      m[(i+1)%n] = 1;
      if (r || (!l && !r && s[i] == 'L')) return 0;
      if (l && !r && s[i] == '?') return 2;
    }
    return 1;
  };

  auto fl = [&]() {
    m = vector<int>(n);
    mint res = 1;
    for(int i: p) res *= check(i,'L');
    return (int)res.val();
  };

  auto fr = [&]() {
    m = vector<int>(n);
    mint res = 1;
    for(int i: p) res *= check(i,'R');
    return (int)res.val();
  };

  mint ans = fl() + fr();
  cout << ans.val() << endl;
  return 0;
}