#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<string> s;

void solve() {
  int ans = 0;
  REP(i,n) REP(j,s[i].size()-1) {
    if (s[i] == "A" && s[i+1] == "B") ans++;
  }

  int a = 0, b = 0, c = 0;
  REP(i,n) {
    if (s[i][0] == 'B' && s[i].back() == 'A') c++;
    else if (s[i].back() == 'A') a++;
    else if (s[i][0] == 'B') b++;
  }

  int add = 0;
  if (c == 0) {
    add = min(a,b);
  } else {
    if (a+b > 0) add = c+min(a,b);
    else add = c-1;
  }

  ans += add;
  cout << ans << endl;
  return ;
}

int main() {
  cin >> n;
  s.resize(n);
  REP(i,n) cin >> s[i];

  solve();
  return 0;
}