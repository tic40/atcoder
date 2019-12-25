#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, a , b, arr[1000002];
  REP(i, 1000002) arr[i] = 0;
  cin >> n;

  REP(i, n) {
    cin >> a >> b;
    arr[a]++; arr[b+1]--;
  }
  int ans = arr[0];
  for (int i = 1; i < 1000002; i++) {
    arr[i] += arr[i-1];
    ans = max(ans , arr[i]);
  }
  cout << ans << endl;
}
