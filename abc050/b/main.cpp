#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,m,sum=0,p,x;
  cin >> n;
  int t[n];
  REP(i,n) { cin >> t[i]; sum += t[i]; }
  cin >> m;
  REP(i,m) { cin >> p >> x; cout << sum - (t[p-1] - x) << endl; }
}