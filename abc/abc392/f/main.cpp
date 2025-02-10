#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int op(int a, int b) { return a+b; }
int e() { return 0; }

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) { cin >> p[i]; p[i]--; }

  segtree<int,op,e> seg(vector<int>(n,1));
  auto get_kth = [&](int k) {
    auto f = [&](int x) { return x <= k; };
    return seg.max_right(0,f);
  };

  vector<int> ans(n);
  // 後ろから埋めていく
  for(int i = n-1; i >= 0; i--) {
    // k番目の index を取得
    int j = get_kth(p[i]);
    ans[j] = i+1;
    seg.set(j,0);
  }

  for(auto v :ans) cout << v << " ";
  return 0;
}
