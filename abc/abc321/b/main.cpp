#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,x; cin >> n >> x;
  vector<int> a(n-1);
  REP(i,n-1) cin >> a[i];

  int ans = -1;
  REP(i,101) {
    auto b = a;
    b.push_back(i);
    sort(b.begin(),b.end());
    int tot = accumulate(b.begin()+1,b.end()-1,0);
    if (tot >= x) { ans = i; break; }
  }

  cout << ans << endl;
  return 0;
}