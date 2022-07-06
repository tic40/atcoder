#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int f(int x) {
  if (x == 0) return 0;
  return f(x % __builtin_popcount(x))+1;
}

int main() {
  int n; string s;
  cin >> n >> s;
  vector<int> x(n);
  REP(i,n) x[i] = s[i]-'0';
  // popcount
  int pc = accumulate(x.begin(),x.end(),0);

  vector<int> ans(n);
  // ビット反転したときにありえるpopcountは+1か-1のどちらかだけ
  REP(b,2) {
    int npc = (b == 0) ? pc+1 : pc-1;
    if (npc <= 0) continue;

    // r0 = 反転していない状態のxから今の popcount で割った余りを10進数で持つ
    int r0 = 0;
    REP(i,n) {
      r0 = (r0*2)%npc;
      r0 += x[i];
    }

    // 各桁についてフリップしたときの値を求めていく
    int k = 1;
    // 下の桁から見ていく
    for(int i = n-1; i >= 0; i--) {
      if (x[i] == b) { // フリップしたとき
        int r = r0;
        if (b == 0) r = (r+k)%npc; // フリップして1になるとき
        else r = (r-k+npc)%npc; // フリップして0になるとき. マイナスを考慮する
        ans[i] = f(r)+1;
      }
      k = (k*2)%npc;
    }
  }

  for(int v: ans) cout << v << endl;
  return 0;
}