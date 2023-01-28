#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  int cnt = 0;
  REP(i,n) {
    string s; cin >> s;
    if (s == "For") cnt++;
  }
  cout << (cnt > n/2 ? "Yes" : "No") << endl;
  return 0;
}