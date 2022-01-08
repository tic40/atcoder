#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
void dfs(string s, char mx) {
  if (s.size() == n) {
    cout << s << endl;
    return;
  }

  for(char c = 'a'; c <= mx+1; c++) {
    string t = s;
    t += c;
    dfs(t, max(mx,c));
  }
}

int main() {
  cin >> n;
  dfs("", 'a'-1);

  return 0;
}