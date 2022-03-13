#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main() {
  int n; ll x; string s;
  cin >> n >> x >> s;

  deque<int> dq;
  REP(i,n) {
    if (dq.size() && dq.back() != 'U' && s[i] == 'U') {
      dq.pop_back();
      continue;
    }
    dq.push_back(s[i]);
  }

  while(dq.size()) {
    char c = dq.front(); dq.pop_front();
    if (c == 'U') x = x >> 1;
    else x = (x << 1) + (c == 'R');
  }

  cout << x << endl;
  return 0;
}