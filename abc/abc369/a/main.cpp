#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int a,b; cin >> a >> b;
  int ans = 0;
  for(int c = -100; c <= 200; c++) {
    vector<int> t = { a,b,c };
    sort(t.begin(),t.end());
    if (t[1]-t[0] == t[2]-t[1]) ans++;
  }
  cout << ans << endl;
  return 0;
}