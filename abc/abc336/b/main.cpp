#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int ans = 0;
  while((n&1) == 0) { ans++; n = n >>1; }
  cout << ans << endl;
  return 0;
}