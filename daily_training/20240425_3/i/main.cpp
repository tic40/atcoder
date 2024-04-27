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
const int MOD = 1e9+7;
// using mint = modint998244353; // modint1000000007;

int main() {
  int n; ll l; cin >> n >> l;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  priority_queue<ll, vector<ll>, greater<ll>> q;
  REP(i,n) q.push(a[i]);
  ll sum = accumulate(a.begin(),a.end(),0LL);
  if (l-sum > 0) q.push(l - sum);

  ll ans = 0;
  while(q.size() > 1) {
    auto v1 = q.top(); q.pop();
    auto v2 = q.top(); q.pop();
    q.push(v1+v2);
    ans += v1+v2;
  }
  cout << ans << endl;
  return 0;
}