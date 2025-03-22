#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  string ans(n,'-');
  ans[n/2] = '=';
  if (n%2 == 0) ans[n/2-1] = '=';
  cout << ans << endl;
  return 0;
}
