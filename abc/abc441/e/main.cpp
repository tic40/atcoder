#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; string s; cin >> n >> s;

  fenwick_tree<int> fw(2*n+1);
  fw.add(n,1);

  int sum = 0;
  ll ans = 0;
  for(auto c: s) {
    if (c == 'A') sum++;
    if (c == 'B') sum--;

    int v = n+sum;
    ans += fw.sum(0,v);
    fw.add(v,1);
  }

  cout << ans << endl;
  return 0;
}
