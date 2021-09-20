#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1e9+7;

int n,q;
vector<ll> x(100),y(100),z(100),w(100);
vector<ll> X(100),Y(100),Z(100),W(100);

ll bit_search() {
  ll ret = 0;
  REP(i, 1<<n) {
    vector<ll> bit(n+1);
    REP(j,n) bit[j] = i >> j & 1;

    bool flag = true;
    REP(j,q) {
      if ((bit[X[j]] | bit[Y[j]] | bit[Z[j]]) != w[j]) {
        flag = false;
        break;
      }
    }
    if (flag) ret++;
  }
  return ret;
}

void solve() {
  ll ans = 1;
  REP(i,60) {
    REP(j,q) w[j] = W[j] >> i & 1;
    ans *= bit_search();
    ans %= MOD;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> q;
  REP(i,q) {
    cin >> X[i] >> Y[i] >> Z[i] >> W[i];
    X[i]--; Y[i]--; Z[i]--;
  }

  solve();
  return 0;
}