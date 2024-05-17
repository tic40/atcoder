#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  string s; cin >> s;

  const int M = 2147483647;
  vector<ll> power100(n+1);
  power100[0] = 1;
  REP(i,n) power100[i+1] = 100LL * power100[i] % M;
  vector<ll> h(n+1);
  REP(i,n) h[i+1] = (100LL * h[i] + (s[i] - 'a' + 1)) % M;

  // string[l,r] のハッシュを返す
  auto hash = [&](int l, int r) {
    ll v = h[r+1] - (h[l] * power100[r-l+1] % M);
    if (v < 0) v += M;
    return v;
  };

  REP(i,q) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    ll h1 = hash(a,b);
    ll h2 = hash(c,d);
    cout << (h1 == h2 ? "Yes" : "No") << endl;
  }

  return 0;
}