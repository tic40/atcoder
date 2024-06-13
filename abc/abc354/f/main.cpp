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

int op(int a, int b) { return max(a,b); }
int e() { return 0; }

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  {
    CC<int> cc;
    REP(i,n) cc.add(a[i]);
    REP(i,n) a[i] = cc(a[i]);
  }

  auto get = [&]() {
    vector<int> dp(n);
    segtree<int,op,e> t(n);
    REP(i,n) {
      dp[i] = t.prod(0,a[i]) + 1;
      t.set(a[i],dp[i]);
    }
    return dp;
  };

  vector<int> dl = get();
  REP(i,n) a[i] = n-1-a[i];
  reverse(a.begin(),a.end());
  vector<int> dr = get();
  reverse(dr.begin(),dr.end());

  int lis = *max_element(dl.begin(), dl.end());
  vector<int> ans;
  REP(i,n) {
    if (dl[i] + dr[i] - 1 == lis) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(auto v: ans) cout << v+1 << " ";
}

int main() {
  int ts; cin >> ts;
  REP(ti,ts) solve();
  return 0;
}