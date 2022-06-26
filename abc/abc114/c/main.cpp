#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int n, ans = 0;
const vector<int> t = {7,5,3};

// bit: 753 で 3bit flagを持つ
void dfs(ll now, int bit) {
  if (n < now) return;
  if (bit == 7) ans++;

  REP(i,3) dfs(now*10+t[i], bit|(1<<i));
  return;
}

int main() {
  cin >> n;
  dfs(0,0);
  cout << ans << endl;
  return 0;
}