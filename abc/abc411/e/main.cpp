#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
using mint = modint998244353;
using S = mint;
S op(S  a, S b) { return a*b; }
S e() { return 1; }
const int m = 6;
const mint inv_m = mint(m).inv();

int main() {
  int n; cin >> n;
  vector<P> pa; // {出目a, サイコロ番号} ペアを出目aの昇順で持つ
  REP(i,n) REP(j,m) { int a; cin >> a; pa.emplace_back(a,i); }
  sort(pa.begin(),pa.end());

  segtree<S,op,e> seg(vector<S>(n,0));
  mint ans = 0;
  for(auto [a,i]: pa) {
    // a := 現在の出目の最大値
    // a * inv_m := サイコロ i で a が出る期待値
    // seg.prod(0,i) * seg.prod(i+1,n) := サイコロ i 以外が全て a 以下のときの確率
    ans += a * inv_m * seg.prod(0,i) * seg.prod(i+1,n);
    seg.set(i,seg.get(i)+inv_m);
  }
  cout << ans.val() << endl;
  return 0;
}