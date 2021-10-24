#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }

int main() {
  int n; cin >> n;
  ll g = -1;
  REP(i,n) {
    ll a; cin >> a;
    if (g == -1) g = a;
    else g = gcd(g,a);
  }

  int ans = 0;
  for (ll i = 1; i*i <= g; i++) {
    if (g % i == 0) {
      ans++;
      if (g/i != i) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}