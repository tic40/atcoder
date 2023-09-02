#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,p; cin >> n >> m >> p;
  int ans = (n+(p-m))/p;
  cout << ans << endl;
  return 0;
}