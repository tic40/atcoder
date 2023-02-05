#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k,ans=0; cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      int d = k-(i+j);
      if (1 <= d && d <= n) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}