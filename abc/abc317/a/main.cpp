#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,h,x; cin >> n >> h >> x;
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  auto it = lower_bound(p.begin(),p.end(), x-h);
  cout << it - p.begin() + 1 << endl;

  return 0;
}