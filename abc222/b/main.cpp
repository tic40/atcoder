#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n,p;
  cin >> n >> p;
  int ans = 0;
  REP(i,n) {
    int a; cin >> a;
    ans += a < p;
  }

  cout << ans << endl;
  return 0;
}