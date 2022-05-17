#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

vector<int> divisor(int n) {
  vector<int> res;
  for(int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (n / i != i) res.push_back(n/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  for(int v: divisor(n)) {
    int cnt = k;
    vector<vector<int>> m(v,vector<int> (26));
    REP(i,n) m[i%v][s[i] - 'a']++;
    REP(i,v) {
      sort(m[i].begin(), m[i].end());
      cnt -= n/v - m[i].back();
    }

    if (0 <= cnt) { cout << v << endl; return 0; }
  }

  return 0;
}