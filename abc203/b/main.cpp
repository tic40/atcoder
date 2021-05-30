#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,k; cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= k; j++) {
    int cur = i * 100;
    cur += j;
    ans += cur;
  }

  cout << ans << endl;
  return 0;
}