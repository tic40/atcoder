#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int t,n,T,ans=0,y=0; cin >> n >> T;
  REP(i,n) {
    cin >> t;
    ans += min(T,t-y);
    y = t;
  }
  cout << ans + T << endl;
  return 0;
}