#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,l; cin >> n >> l;
  int ans = 0;
  REP(i,n) {
    int a; char b; cin >> a >> b;
    if (b == 'E') ans = max(ans,l-a);
    else ans = max(ans,a);
  }
  cout << ans << endl;
  return 0;
}