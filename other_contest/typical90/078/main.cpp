#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> s(n);
  int a,b;
  REP(i,m) {
    cin >> a >> b;
    a--; b--;
    a < b ? s[b]++ : s[a]++;
  }

  int ans = 0;
  REP(i,n) if (s[i] == 1) ans++;

  cout << ans << endl;
  return 0;
}