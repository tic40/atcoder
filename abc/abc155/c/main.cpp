#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  sort(s.begin(), s.end());

  map <string, int> m;
  REP(i,n) {
    m[s[i]] += 1;
  }
  int mx = 0;
  REP(i,n) {
    mx = max(mx, m[s[i]]);
  }

  for(auto x : m) {
    if (x.second == mx) { cout << x.first << endl; }
  }
}