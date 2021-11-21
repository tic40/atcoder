#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int main() {
  int n,q;
  cin >> n >> q;

  fenwick_tree<ll> fw(n);
  REP(i,n) {
    int a; cin >> a;
    fw.add(i,a);
  }
  REP(i,q) {
    int t; cin >> t;
    if (t == 0) {
      int p,x;
      cin >> p >> x;
      fw.add(p,x);
    } else {
      int l,r;
      cin >> l >> r;
      cout << fw.sum(l,r) << endl;
    }
  }
  return 0;
}