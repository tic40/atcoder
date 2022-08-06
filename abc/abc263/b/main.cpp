#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n);
  for(int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }

  int ans = 0, cur = n-1;
  while(0 < cur) {
    cur = p[cur];
    ans++;
  }
  cout << ans << endl;
  return 0;
}