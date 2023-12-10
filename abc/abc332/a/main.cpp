#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,s,k; cin >> n >> s >> k;
  int tot = 0;
  REP(i,n) {
    int p,q; cin >> p >> q;
    tot += p*q;
  }
  if (tot < s) tot += k;
  cout << tot << endl;
  return 0;
}