#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  vector<int> s(n); // s[i] := p[i-1] < p[i] が成り立つ個数の累積和
  REP(i,n-1) s[i+1] = s[i] + (p[i+1] > p[i] ? 1 : 0);
  vector<int> sm(n,1e9); // sm[i] := p[n-k]...p[i] の累積 min
  for(int i = n-k; i < n; i++) sm[i] = min(sm[i-1], p[i]);

  // l-r 間をソートして答えを出力
  auto ans = [&](int l = 0, int r = 0) {
    sort(p.begin()+l,p.begin()+r);
    for(auto v: p) cout << v << " ";
    exit(0);
  };

  REP(l,n) {
    int r = l+k-1;
    if (r >= n) break;
    // p[l] < p[l+1] < p[l+2] < ... < p[r] が成り立つ
    if (s[r] - s[l] == k-1) ans();
  }

  REP(l,n) {
    int r = l+k-1;
    if (r >= n) break;
    if (r < n-k) continue;
    // 条件1: p[l] < p[l+1] < ... < p[n-k]
    bool ok = (s[n-k] - s[l]) == n-k-l;
    // 条件2: p[n-k], p[n-k+1],..., p[r] の最小値は p[n-k-1] より大きい
    ok = ok && p[n-k-1] < sm[r];
    if (ok) ans(l,r+1);
  }

  ans(n-k,n);
  return 0;
}