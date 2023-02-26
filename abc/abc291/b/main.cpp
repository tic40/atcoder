#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int n5 = n*5;
  vector<int> x(n5);
  REP(i,n5) cin >> x[i];

  sort(x.begin(),x.end());
  int tot = 0;
  for(int i = n; i < n5-n; i++) tot += x[i];
  double ans = (double)tot / (3.0 * n);
  printf("%.10f\n",ans);
  return 0;
}