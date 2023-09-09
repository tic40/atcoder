#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> l(n);
  REP(i,n) cin >> l[i];

  ll ok = LINF, ng = *max_element(l.begin(),l.end()) - 1;
  while(ok-ng > 1) {
    ll mid = (ok+ng) / 2;

    // 横幅 mid のとき、m 行に収まるか？
    int row = 1;
    ll col = 0;
    REP(i,n) {
      col += l[i];
      if (col > mid) {
        col = l[i];
        row++;
      }
      col++;
    }
    if (row <= m) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}