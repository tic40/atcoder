#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,l,r; cin >> n >> l >> r;
  int ans = 0;
  REP(i,n) {
    int x,y; cin >> x >> y;
    if (x <= l && r <= y) ans++;
  }
  cout << ans << endl;
  return 0;
}