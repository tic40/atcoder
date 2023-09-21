#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  vector<int> s(n); // p[i] < p[i+1] が成り立つ個数の累積和
  REP(i,n-1) s[i+1] = s[i] + (p[i+1] > p[i] ? 1 : 0);
  vector<int> sm(n,1e9); // p[n-k]以降の累積min
  for(int i = n-k; i < n; i++) sm[i] = min(sm[i-1], p[i]);

  auto output = [&]() { for(auto v: p) cout << v << " "; };

  REP(l,n-k+1) {
    int r = l+k-1;
    // p[l] < p[l+1] < p[l+2] < ... < p[r] が成り立つ
    if (s[r] - s[l] == k-1) { output(); return 0; }
  }

  for(int l = max(0,n-k*2+1); l < n-k; l++) {
    int r = l+k-1;
    // 条件1: p[l] < p[l+1] < ... < p[n-k]
    bool ok = (s[n-k] - s[l]) == n-k-l;
    // 条件2: p[n-k], p[n-k+1],..., p[r] の最小値は p[n-k-1] より大きい
    ok = ok && p[n-k-1] < sm[r];
    if (ok) {
      sort(p.begin()+l, p.begin()+l+k);
      output(); return 0;
    }
  }

  sort(p.end()-k,p.end());
  output();
  return 0;
}