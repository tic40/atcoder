#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int x; cin >> x;
  int ans = 0;
  for(int i = 1; i <= 9; i++) for(int j = 1; j <= 9; j++) {
    if (i*j != x) ans+=i*j;
  }
  cout << ans << endl;
  return 0;
}