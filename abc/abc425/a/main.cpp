#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int ans = 0;
  int x = 1;
  REP(i,n) {
    x *= -1;
    ans += x * pow((i+1),3);
  }
  cout << ans << endl;
  return 0;
}