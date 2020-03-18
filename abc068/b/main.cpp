#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  int i = 0;
  int ans = 0;
  while(1) {
    int x = pow(2,i);
    if (x > n) break;
    ans = x;
    i++;
  }
  cout << ans << endl;
  return 0;
}
