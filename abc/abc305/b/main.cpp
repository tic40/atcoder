#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  char p,q; cin >> p >> q;
  const int n = 7;
  vector<int> a = {0,3,1,4,1,5,9};
  vector<int> s(n+1);
  REP(i,n) s[i+1] = s[i] + a[i];
  cout << abs(s[p-'A'+1] - s[q-'A'+1]) << endl;
  return 0;
}