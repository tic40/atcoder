#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

const vector<int> ps = { 4, 9, 5, 7, 11, 13, 17, 19, 23 };

int main() {
  // サイクルを作る
  vector<int> a;
  for(int p: ps) {
    int si = a.size();
    REP(i,p) a.push_back((i+1) % p + si);
  }
  int m = a.size();
  cout << m << endl;
  REP(i,m) cout << a[i] + 1 << " ";
  cout << endl;

  REP(i,m) cin >> a[i];
  REP(i,m) a[i]--;

  vector<ll> rs, ms;
  int si = 0;
  for(int p: ps) {
    rs.push_back((a[si] - si) % p);
    ms.push_back(p);
    si += p;
  }

  // 中国剰余定理を利用する
  ll ans = crt(rs,ms).first;
  cout << ans << endl;
  return 0;
}