#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main() {
  int n; cin >> n;
  map<int,int> m;
  REP(i,n) {
    int a; cin >> a;
    m[a]++;
  }

  ll ans = 0;
  for(int i = -200; i <= 200; i++) {
    for(int j = i+1; j <= 200; j++) {
      ans += pow(i-j,2)*m[i]*m[j];
    }
  }

  cout << ans << endl;
  return 0;
}