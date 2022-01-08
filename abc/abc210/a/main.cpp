#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,a,x,y;
  cin >> n >> a >> x >> y;
  int ans = min(n,a) * x + max(0, n-a) * y;
  cout << ans << endl;
  return 0;
}