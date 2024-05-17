#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  const int M = 2147483647;
  int n,q; cin >> n >> q;
  string s; cin >> s;
  string rs = s;
  reverse(rs.begin(),rs.end());

  vector<ll> power(n+1);
  power[0] = 1;
  REP(i,n) power[i+1] = power[i] * 100 % M;

  vector<ll> h(n+1);
  REP(i,n) h[i+1] = (h[i] * 100 + (s[i] - 'a' + 1)) % M;
  vector<ll> hr(n+1);
  REP(i,n) hr[i+1] = (hr[i] * 100 + (rs[i] - 'a' + 1)) % M;

  auto hash1 = [&](int l, int r, int rev) {
    ll res = h[r+1] - ((h[l] * power[r-l+1]) % M);
    return res < 0 ? res+M : res;
  };

  // 左から読んだときのハッシュ計算
  auto hash_value = [&](int l, int r) {
    ll val = h[r+1] - ((h[l] * power[r-l+1]) % M);
    if (val < 0) val += M;
    return val;
  };

  // 右から読んだときのハッシュ計算
  auto hash_value_r = [&](int l, int r) {
    int nl = n-(r+1), nr = n-(l+1);
    ll val = hr[nr+1] - ((hr[nl] * power[nr-nl+1]) % M);
    if (val < 0) val += M;
    return val;
  };

  REP(_,q) {
    int l,r; cin >> l >> r; l--; r--;
    cout << (hash_value(l,r) == hash_value_r(l,r) ? "Yes" : "No") << endl;
  }
  return 0;
}