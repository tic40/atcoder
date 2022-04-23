#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

vector<int> divisor(int n) {
  vector<int> res;
  for(int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> m(200001);
  vector<bool> used(200001);
  REP(i,n) m[a[i]]++;

  ll ans = 0;
  for(int i: a) {
    if (used[i]) continue;
    used[i] = true;
    for(int j: divisor(i)) {
      int k = i / j;
      ans += (ll)m[i] * m[j] * m[k];
    }
  }
  cout << ans << endl;
  return 0;
}