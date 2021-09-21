#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int x,l,r;
  cin >> x >> l >> r;
  int ans = 1;
  int mi = INF;
  for(int i = l; i <= r; i++) {
    if (abs(x-i) < mi) {
      ans = i;
      mi = abs(x-i);
    }
  }
  cout << ans << endl;
  return 0;
}