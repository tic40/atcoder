#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  double n; cin >> n;
  int ans = 1;
  if (n < 38.0) ans++;
  if (n < 37.5) ans++;
  cout << ans << endl;
  return 0;
}
