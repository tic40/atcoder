#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m,k; cin >> n >> m >> k;
  vector<int> h(n),b(m);
  REP(i,n) cin >> h[i];
  REP(i,m) cin >> b[i];
  sort(h.begin(),h.end());
  sort(b.begin(),b.end());

  REP(i,k) if (h[i] > b[m-k+i]) cout << "No" << endl; return 0;
  cout << "Yes" << endl;
  return 0;
}