#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  int x[n];
  int maxX = 0;
  REP(i,n) {
    cin >> x[i];
    maxX = max(x[i], maxX);
  }

  int ans = 1001001001;

  REP(i,maxX) {
    int sum = 0;
    REP(j,n) {
      sum += pow((x[j] - (i + 1)), 2.0);
      if (sum >= ans) break;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
}