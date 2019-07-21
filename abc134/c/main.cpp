#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, max = 0, second = 0;
  cin >> n;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    if (a[i] > max) { second = max; max = a[i]; }
    else if (a[i] > second) { second = a[i]; }
  }
  int ans;
  REP(i, n) {
    ans = (a[i] == max) ? second : max;
    cout << ans << endl;
  }
}