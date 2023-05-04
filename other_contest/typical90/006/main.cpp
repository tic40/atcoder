#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  vector m(26, vector<int>());
  REP(i,n) m[s[i]-'a'].push_back(i);

  int l = 0, r = n - k + 1;
  REP(_,k) REP(j,26) {
    auto it = lower_bound(m[j].begin(), m[j].end(),l);
    if (it == m[j].end() || *it >= r) continue;
    l = *it + 1;
    r++;
    cout << char('a' + j);
    break;
  }
  return 0;
}