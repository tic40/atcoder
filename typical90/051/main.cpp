#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll n,k,p;
vector<ll> a;

void solve() {
  int mid = n/2;
  vector<vector<ll>> group1(n+1), group2(n+1);

  REP(bit, 1 << mid) {
    ll tot = 0;
    int cnt = 0;
    REP(i,mid) {
      if (bit >> i & 1) {
        tot += a[i];
        cnt++;
      }
    }
    group1[cnt].push_back(tot);
  }

  REP(bit, 1 << (n-mid)) {
    ll tot = 0;
    int cnt = 0;
    REP(i,n-mid) {
      if (bit >> i & 1) {
        tot += a[mid + i];
        cnt++;
      }
    }
    group2[cnt].push_back(tot);
  }

  REP(i,n+1) {
    sort(group1[i].begin(), group1[i].end());
    sort(group2[i].begin(), group2[i].end());
  }

  ll ans = 0;
  REP(h,k+1) REP(i,(int)group1[h].size()) {
    ll pos1 = lower_bound(
      group2[k - h].begin(),
      group2[k - h].end(),
      p - group1[h][i] + 1
    ) - group2[k - h].begin();
    ans += pos1;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> k >> p;
  a.resize(n);
  REP(i,n) cin >> a[i];

  solve();
  return 0;
}