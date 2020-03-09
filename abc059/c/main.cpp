#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n; cin >> n;
  int a[n]; REP(i,n) cin >> a[i];

  int ans1 = 0;
  int sum = 0;
  // 奇数を負,偶数を正
  REP(i,n) {
    int cur = a[i];
    if (i%2) {
      if (sum+cur >= 0) cur = -(sum+1);
    } else {
      if (sum+cur <= 0) cur = -sum+1;
    }
    sum+=cur;
    ans1+=abs(a[i]-cur);
  }

  int ans2 = 0;
  sum = 0;
  // 奇数を正, 偶数を負
  REP(i,n) {
    int cur = a[i];
    if (i%2 == 0) {
      if (sum+cur >= 0) cur = -(sum+1);
    } else {
      if (sum+cur <= 0) cur = -sum+1;
    }
    sum+=cur;
    ans2+=abs(a[i]-cur);
  }

  cout << min(ans1, ans2) << endl;
  return 0;
}