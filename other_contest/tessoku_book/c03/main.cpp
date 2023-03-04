#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int d,x; cin >> d >> x;
  vector<int> a(d);
  for(int i = 1; i < d; i++) cin >> a[i];

  vector<int> sum(d+1);
  sum[0] = x;
  for(int i = 1; i <= d; i++) sum[i] = sum[i-1] + a[i];

  int q; cin >> q;
  REP(_,q) {
    int s,t; cin >> s >> t;
    s--; t--;
    int diff = sum[s] - sum[t];
    if (diff == 0) cout << "Same";
    else if (diff > 0) cout << s+1;
    else cout << t+1;
    cout << endl;
  }

  return 0;
}