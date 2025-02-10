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
  REP(i,n) cin >> p[i], p[i]--;

  segtree<int,op,e> seg(vector<int>(n,1));
  vector<int> ans(n);

  for(int i = n-1; i >= 0; i--) {
    // segtree 上を二分探索して k番目の index を取得
    int kth = seg.max_right(0,[&](int x){ return x <= p[i]; });
    ans[kth] = i+1;
    seg.set(kth,0);
  }
  for(auto v: ans) cout << v << " ";
  return 0;
}
