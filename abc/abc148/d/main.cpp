#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int a, next = 1, ans = 0;
  REP(i, n) {
    cin >> a;
    if (a == next) next++;
    else ans++;
  }
  if (next > 1) cout << ans << endl;
  else cout << -1 << endl;
}