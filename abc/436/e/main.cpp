#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  REP(i,n) { cin >> p[i]; p[i]--; }

  ll ans = 0;
  vector<int> visited(n);
  REP(i,n) {
    ll cnt = 0;
    int now = i;
    while (!visited[now]) {
      visited[now] = 1;
      now = p[now];
      cnt++;
    }
    ans += cnt * (cnt-1) / 2;
  }
  cout << ans << endl;
}
