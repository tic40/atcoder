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
  int n;
  cin >> n;
  vector<int> r(n),c(n);
  REP(i,n) cin >> r[i];
  REP(i,n) cin >> c[i];

  int q;
  cin >> q;
  REP(i,q) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    int x = r[a];
    int y = c[b];
    if (n-y < x) cout << "#";
    else cout << ".";
  }

  cout << endl;
  return 0;
}