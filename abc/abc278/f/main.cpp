#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n;
vector<string> s(16);
vector dp(1<<16, vector<bool>(16));
vector mem(1<<16, vector<bool>(16));

bool f(int bit, int p) {
  if (mem[bit][p]) return dp[bit][p];
  mem[bit][p] = true;
  bool res = false;
  REP(i,n) {
    if (bit >> i & 1) continue;
    // bit = 0 のときは何でも選べるのでスキップしない
    if (bit && s[i][0] != s[p].back()) continue;
    // 次は相手のターンなので!f()
    res |= !f((bit | 1 << i), i);
  }
  return dp[bit][p] = res;
}

int main() {
  cin >> n;
  REP(i,n) cin >> s[i];
  cout << (f(0,0) ? "First" : "Second") << endl;
  return 0;
}