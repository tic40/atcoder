#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int op(int a, int b) { return max(a,b); }
int e() { return 0; }

int main() {
  int n,q; cin >> n >> q;
  vector<int> h(n);
  REP(i,n) cin >> h[i];
  vector qs(n,vector<P>());
  REP(i,q) {
    int l,r ; cin >> l >> r; l--; r--;
    qs[r].emplace_back(l,i);
  }

  segtree<int,op,e> seg(h);
  vector<int> ans(q);
  vector<int> st;
  for(int i = n-1; i >= 0; i--) {
    for(auto [l,qi]: qs[i]) {
      // max_h: l+1 〜 r までの最大の高さ
      int max_h = seg.prod(l+1,i+1);
      // 降順になっているので逆順で lower_bound
      auto it = lower_bound(st.begin(),st.end(),max_h,greater<int>());
      ans[qi] = it - st.begin();
    }
    while(st.size() && st.back() < h[i]) st.pop_back();
    st.push_back(h[i]);
  }
  REP(i,q) cout << ans[i] << endl;
  return 0;
}