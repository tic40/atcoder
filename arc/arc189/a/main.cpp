#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using mint = modint998244353; // modint1000000007;

struct Combination {
  vector<mint> fact, ifact;
  Combination(int n):fact(n+1),ifact(n+1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // RLE
  vector<P> pa;
  REP(i,n) {
    if (pa.size() && pa.back().first == a[i]) pa.back().second++;
    else pa.emplace_back(a[i],1);
  }

  auto solve = [&]() -> int {
    // 先頭と末尾が一致していなければ 0
    if (a[0] == 0 || a.back() != n%2) return 0;
    // 同じ数が偶数個連続している場合は 0
    for(auto [_,c]: pa) if (c%2 == 0) return 0;

    int len = 0;
    mint ans = 1;
    Combination C(2e5+1);
    for(auto [_,c]: pa) {
      int v = c;
      c = (c-1) / 2;
      ans = ans * C(len+c,c);
      len += c;
      while(v >= 3) { v-=2; ans *= v; }
    }
    return ans.val();
  };

  cout << solve() << endl;
  return 0;
}