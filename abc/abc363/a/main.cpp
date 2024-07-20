#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;

  int ans = 0;
  if (n < 100) ans = max(ans,100 - n);
  else if (n < 200) ans = max(ans,200 - n);
  else if (n < 300) ans = max(ans,300 - n);

  cout << ans << endl;
  return 0;
}