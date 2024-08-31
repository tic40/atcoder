#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(2,-1);
  int ans = 0;
  REP(i,n) {
    int a; char s;
    cin >> a >> s;
    int idx = s == 'L' ? 0 : 1;
    if (p[idx] != -1) ans += abs(p[idx] - a);
    p[idx] = a;
  }
  cout << ans << endl;
  return 0;
}