#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();

// a^b <= n を満たす最大の a を返す
ll calc(int b, ll n) {
  ll ok = 0, ng = n+1;
  while(abs(ok-ng) > 1) {
    ll mid = (ok+ng) / 2;

    auto judge = [&] {
      ll x = 1;
      REP(i,b) {
        if (n/x < mid) return false;
        x *= mid;
      }
      return x <= n;
    };

    if (judge()) ok = mid;
    else ng = mid;
  }
  return ok-1;
}

int main() {
  ll n; cin >> n;

  const int M = 60;
  // f[b] := a^b <= n を満たす最大の a の値
  vector<ll> f(M);
  ll ans = 1;
  // b を固定
  for(int b = M-1; b >= 2; b--) {
    f[b] = calc(b,n);
    for(int i = b*2; i < M; i += b) f[b] -= f[i];
    ans += f[b];
  }

  cout << ans << endl;
  return 0;
}