#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  P ans = {0,0};
  vector<int> b(n);

  REP(i,m) {
    int a; cin >> a; a--;
    b[a]++;
    ans = max(ans,{b[a],-a});
    cout << -ans.second+1 << endl;
  }
  return 0;
}