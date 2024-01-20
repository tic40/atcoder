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
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  map<int,int> mp;
  REP(i,n) {
    mp[a[i]] = i;
  }
  int now = -2;
  int cnt = 0;
  vector<int> ans(n);
  while(mp.count(now)) {
    now = mp[now];
    ans[cnt] = now;
    cnt++;
  }
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}