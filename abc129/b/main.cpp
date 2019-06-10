#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, left = 0, total = 0;
  cin >> n;
  vector<int> w(n);
  REP(i, n) {
    cin >> w[i];
    total += w[i];
  }
  int ans = total, sum = 0;
  REP(i , n) {
    sum += w[i];
    ans = min(ans, abs(sum * 2 - total));
  }
  cout << ans << endl;
}