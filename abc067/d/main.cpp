#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,a,b;
vector<int> x;

void solve() {
  ll ans = 0;

  REP(i,n-1) {
    ll d = x[i+1] - x[i];
    if (b < a*d) ans+=b;
    else ans+=a*d;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> a >> b;
  x.resize(n);
  REP(i,n) cin >> x[i];

  solve();
  return 0;
}