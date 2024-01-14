#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'


int main() {
  int n; cin >> n;
  int ans = 0;
  while(n > 0) {
    if (n % 2) break;
    ans++;
    n /= 2;
  }
  cout << ans << endl;
  return 0;
}