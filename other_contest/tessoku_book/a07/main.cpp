#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int d,n; cin >> d >> n;
  vector<int> s(d+1);
  REP(i,n) {
    int l,r; cin >> l >> r;
    s[l]++;
    s[r+1]--;
  }
  REP(i,d+1) s[i+1] += s[i];
  for(int i = 1; i <= d; i++) cout << s[i] << endl;
  return 0;
}