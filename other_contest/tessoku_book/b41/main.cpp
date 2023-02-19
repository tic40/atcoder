#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int x,y; cin >> x >> y;

  vector<P> ans;
  while(x > 1 || y > 1) {
    ans.emplace_back(x,y);
    if (x >= y) x -= y;
    else y -= x;
  }

  reverse(ans.begin(),ans.end());
  cout << ans.size() << endl;
  for(auto [a,b]: ans) cout << a << " " << b << endl;
  return 0;
}