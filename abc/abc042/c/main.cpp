#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,k;
string s;
vector<int> d;

int dfs(string t = "") {
  if (s.size() <= t.size()) {
    int ti = stoi(t);
    if (n <= ti) return ti;
    if (s.size() < t.size()) return INF;
  }

  int ans = INF;
  for (char c: d) {
    string nt = t + char('0'+c);
    ans = min(ans, dfs(nt));
  }
  return ans;
}

int main() {
  cin >> n >> k;
  vector<int> tmp(10);
  REP(i,k) {
    int _; cin >> _;
    tmp[_] = 1;
  }
  REP(i,10) if (tmp[i] == 0) d.push_back(i);
  s = to_string(n);

  cout << dfs() << endl;
  return 0;
}