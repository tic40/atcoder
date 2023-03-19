#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<ll,ll>;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

struct V {
  ll left,right,x;
};

int main() {
  ll l,n1,n2;
  cin >> l >> n1 >> n2;
  queue<V> v1,v2;
  ll pos = 0;
  REP(i,n1) {
    ll a,b; cin >> a >> b;
    v1.push({ pos, pos+b-1, a });
    pos += b;
  }
  pos = 0;
  REP(i,n2) {
    ll a,b; cin >> a >> b;
    v2.push({ pos, pos+b-1, a });
    pos += b;
  }

  ll ans = 0;
  auto now1 = v1.front(); v1.pop();
  auto now2 = v2.front(); v2.pop();

  auto f = [&]() {
    if (now1.right <= now2.right) {
      if (now1.x == now2.x && now1.right >= now2.left) {
        ans += now1.right - max(now2.left, now1.left) + 1;
      }
      if (v1.size()) { now1 = v1.front(); v1.pop(); }
    }
    else {
      if (now1.x == now2.x && now2.right >= now1.left) {
        ans += now2.right - max(now1.left, now2.left) + 1;
      }
      if (v2.size()) { now2 = v2.front(); v2.pop(); }
    }
  };

  while(v1.size() || v2.size()) f();
  f();
  cout << ans << endl;
  return 0;
}