#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> a;

void solve() {
  vector<int> x(n+1);
  for (int i = n; 0 < i; i--) {
    int sum = 0;
    for (int j = i*2; j <= n; j+=i) sum += x[j];
    x[i] = sum%2 != a[i] ? 1 : 0;
  }

  vector<int> ans;
  for (int i = 1; i <= n; i++) if (x[i]) ans.push_back(i);
  cout << ans.size() << endl;
  for(int v: ans) cout << v << " ";

  return;
}

int main() {
  cin >> n;
  a.resize(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  solve();
  return 0;
}