#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,ans=0;
  cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  int curMin = 1e9;
  REP(i,n) {
    curMin = min(curMin, p[i]);
    if (curMin == p[i]) ans++;
  }
  cout << ans << endl;
}