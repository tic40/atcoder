#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int ans = 0;
  REP(i,n) {
    int a; cin >> a;
    if (i % 2 == 0) ans += a;
  }
  cout << ans << endl;
  return 0;
}