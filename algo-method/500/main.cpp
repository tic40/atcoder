#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }

int main() {
  ll a,b,r,s;
  cin >> a >> b >> r >> s;

  ll g = gcd(abs(a-r), abs(b-s));
  vector<ll> m;
  for(ll i = 1; i*i <= g; i++) {
    if (g % i == 0) {
      m.push_back(i);
      if (g / i != i) m.push_back(g/i);
    }
  }

  sort(m.begin(), m.end());
  REP(i,m.size()) {
    if (max(r,s) < m[i]) {
      cout << m[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}