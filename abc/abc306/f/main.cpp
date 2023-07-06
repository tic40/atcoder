#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<P> b;
  REP(i,n) REP(j,m) {
    int a; cin >> a;
    b.emplace_back(a,i);
  }
  // 全体を繋げたものを sort する
  sort(b.begin(),b.end());

  // 1+2+3...m = (m+1)*m/2
  // nC2 通り = n*(n-1) / 2
  ll ans = ll((m+1)*m/2) * (n*(n-1)/2);

  // 転倒数分を ans に足す
  // 1 2 3 4 6 8
  fenwick_tree<int> fw(n);
  for(auto [_,x]: b) {
    fw.add(x,1);
    ans += fw.sum(x+1,n);
  }
  cout << ans << endl;
  return 0;
}