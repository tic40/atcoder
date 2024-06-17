#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

using S = int;
S op(S a, S b) { return max(a,b); }
S e() { return 0; }

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  {
    CC<int> c;
    REP(i,n) c.add(a[i]);
    REP(i,n) a[i] = c(a[i]);
  }

  auto lis = [&]() {
    vector<int> dp(n);
    segtree<S,op,e> seg(n);
    REP(i,n) {
      dp[i] = seg.prod(0,a[i]) + 1;
      seg.set(a[i],dp[i]);
    }
    return dp;
  };

  auto dl = lis();
  // 値の大小を反対にする
  REP(i,n) a[i] = n-1-a[i];
  reverse(a.begin(),a.end());
  auto dr = lis();

  auto mx = *max_element(dl.begin(),dl.end());
  vector<int> ans;
  // i := LIS に含まれている値
  REP(i,n) if (dl[i] + dr[n-i-1] - 1 == mx) ans.push_back(i);
  cout << ans.size() << endl;
  for(auto v: ans) cout << v+1 << " ";
}

int main() {
  int t; cin >> t;
  REP(i,t) solve();
  return 0;
}