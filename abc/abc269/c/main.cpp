#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

string f(ll n) {
  string ans = "";
  while(n>=1) {
    if (n % 2 == 0) ans = "0" + ans;
    if (n % 2 == 1) ans = "1" + ans;
    n/=2;
  }
  return ans;
}

string b = "";
vector<ll> ans;

void dfs(int i, ll now) {
  if (i == (int)b.size()) {
    ans.push_back(now);
    return;
  }

  dfs(i+1, now);
  if (b[i] == '1') dfs(i+1, now + powl(2,i));
  return;
}

int main() {
  ll n; cin >> n;
  b = f(n);
  reverse(b.begin(),b.end());

  dfs(0,0);
  sort(ans.begin(),ans.end());
  for(auto v: ans) cout << v << endl;
  return 0;
}