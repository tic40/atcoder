#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
string s;

char f(ll t, ll k) {
  if (t == 0) return s[k];
  if (k == 0) return 'A' + (s[0] - 'A' + t) % 3;

  char c = f(t-1, k/2);
  return (k%2 == 0) ?
    'A' + (c - 'A' + 1) % 3
    : 'A' + (c - 'A' + 2) % 3;
}

int main() {
  int q; cin >> s >> q;

  REP(i,q) {
    ll t,k; cin >> t >> k;
    k--;

    cout << f(t,k) << endl;
  }
  return 0;
}