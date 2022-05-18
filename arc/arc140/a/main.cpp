#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

vector<int> divisor(int x) {
  vector<int> res;
  for(int i = 1; i*i <= x; i++) {
    if (x % i == 0) {
      res.push_back(i);
      if (x / i != i) res.push_back(x/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  for(int v: divisor(n)) {
    vector<vector<int>> m(v, vector<int> (26));
    int cnt = k;
    REP(i,n) m[i%v][ s[i] - 'a' ]++;
    REP(i,v) {
      sort(m[i].begin(), m[i].end());
      cnt -= n/v - m[i].back();
    }
    if (0 <= cnt) {
      cout << v << endl;
      return 0;
    }
  }
  return 0;
}
