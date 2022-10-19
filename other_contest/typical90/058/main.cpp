#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
const int MOD = 1e5;

int main() {
  int n; ll k;
  cin >> n >> k;

  auto dsum = [](int x) {
    int res = 0;
    while(x>0) { res+=x%10; x/=10; }
    return res;
  };

  vector<int> mem(1e5,-1);
  int cnt = 0;
  while(mem[n] == -1) {
    mem[n] = cnt;
    n += dsum(n);
    n %= MOD;
    cnt++;
  }

  // mem[n] := サイクルに入るまでのカウント
  // rd := サイクル一周のカウント
  int rd = cnt - mem[n];
  if (mem[n] < k) {
    k = (k - mem[n]) % rd;
    k += mem[n];
  }

  REP(i,1e5) {
    if (mem[i] == k) { cout << i << endl; break; }
  }
  return 0;
}