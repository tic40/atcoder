#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; string s;
  cin >> n >> s;
  REP(i,n-2) {
    string t = s.substr(i,3);
    if (t == "ABC") { cout << i+1 << endl; return 0; }
  }
  cout << -1 << endl;
  return 0;
}