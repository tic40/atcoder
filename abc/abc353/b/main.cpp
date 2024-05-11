#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  int ans = 1, now = 0;
  REP(i,n) {
    int a; cin >> a;
    now += a;
    if (now > k) { ans++; now = a; }
  }
  cout << ans << endl;
  return 0;
}