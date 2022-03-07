#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

string s;
char g(char c, ll add) {
  return char('A' + (c - 'A' + add) % 3);
}

char f(ll t, ll k) {
  if (t == 0) return s[k];
  if (k == 0) return g(s[0], t);

  return g( f(t-1, k/2), k%2+1 );
}

int main() {
  int q; cin >> s >> q;

  REP(i,q) {
    ll t,k;
    cin >> t >> k;
    k--;

    cout << f(t,k) << endl;
  }

  return 0;
}