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

int main() {
  ll d; cin >> d;

  ll ans = LINF;
  for(ll i = 0; i <= 1000000; i++) {
    ll now = d - i*i;
    ll sq = sqrt(now);
    ans = min(ans, abs(now - sq*sq));
    ans = min(ans, abs(now - (sq+1)*(sq+1)));
  }

  cout << ans << endl;
  return 0;
}