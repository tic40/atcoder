#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  string s; cin >> s;
  vector<int> in, ex;
  REP(i,10) {
    if (s[i] == 'o') in.push_back(i);
    if (s[i] == 'x') ex.push_back(i);
  }

  auto include = [&](int x, int i, int j, int k, int l) {
    return (x == i || x == j || x == k || x == l);
  };

  int ans = 0;

  REP(i,10000) {
    int x = i;
    vector<int> cur(4);
    int j = 0;
    while(0 < x) {
      cur[j] = x%10;
      x/=10;
      j++;
    }

    bool ok = true;
    for(int v: in) {
      if (!include(v,cur[0],cur[1],cur[2],cur[3])) ok = false;
    }
    for(int v: ex) {
      if (include(v,cur[0],cur[1],cur[2],cur[3])) ok = false;
    }

    if (ok) ans++;
  }

  cout << ans << endl;
  return 0;
}