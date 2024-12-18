#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  int n; cin >> n;
  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  fenwick_tree<mint> fw(3001);
  fw.add(0,1);
  REP(i,n) {
    fenwick_tree<mint> old(3001);
    swap(fw,old);
    for(int j = a[i]; j <= b[i]; j++) fw.add(j,old.sum(0,j+1));
  }
  mint ans = fw.sum(0,3001);
  cout << ans.val() << endl;
  return 0;
}