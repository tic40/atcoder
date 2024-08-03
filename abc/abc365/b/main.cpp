#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; cin>>n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<P> pa(n);
  REP(i,n) pa[i] = {a[i],i};
  sort(pa.rbegin(),pa.rend());
  cout << pa[1].second + 1 << endl;
  return 0;
}