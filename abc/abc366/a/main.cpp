#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,t,a; cin >> n >> t >> a;
  int r = n - t - a;
  int d = abs(t-a);
  cout << (d <= r ? "No" : "Yes") << endl;
  return 0;
}