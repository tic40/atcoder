#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  string s; cin >> s;

  int cnt = 0;
  REP(i,n) {
    if (cnt < k && s[i] == 'o') { cout << 'o'; cnt++; }
    else cout << 'x';
  }
  return 0;
}