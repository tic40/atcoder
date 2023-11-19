#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  vector<int> cnt(n+1);
  P ans(0,-1);
  REP(i,m) {
    int a; cin >> a;
    cnt[a]++;
    ans = max(ans,{ cnt[a], -a });
    cout << -ans.second << endl;
  }
  return 0;
}