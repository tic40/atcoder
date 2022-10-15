#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,k; cin >> n >> k;
  vector<int> v;
  REP(i,n) {
    int a,b; cin >> a >> b;
    v.push_back(b);
    v.push_back(a-b);
  }
  sort(v.rbegin(),v.rend());
  ll ans = accumulate(v.begin(),v.begin()+k,0LL);
  cout << ans << endl;

  return 0;
}