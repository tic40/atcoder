#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int op(int x, int y) { return max(x,y); }
int e() { return 0; }
int mapping(int f, int x) { return x+f; }
int composition(int f, int g) { return f+g; }
int id() { return 0; }

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // pre[v] := 値 v が最後に入っている位置 index
  vector<int> pre(n), pos(n+1,-1);
  REP(i,n) {
    pre[i] = pos[a[i]];
    pos[a[i]] = i;
  }

  // dp[j][i] = j個目の切れ目を i にしたときの max
  // dp[j+1][i] = max(dp[j][p] + f(p,i)) // p < i
  using seg = lazy_segtree<int,op,e,int,mapping,composition,id>;
  vector<seg> t(3,seg(n));

  REP(i,n) {
    REP(j,2) t[j+1].set(i,t[j].all_prod());
    REP(j,3) t[j].apply(pre[i]+1,i+1,1);
  }
  cout << t[2].all_prod() << endl;
  return 0;
}
