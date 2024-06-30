#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s,t; cin >> s >> t;
  int n = s.size();
  for(int w = 1; w < n; w++) for(int c = 0; c < w; c++) {
    string now = "";
    for(int i = c; i < n; i+=w) now += s[i];
    if (now == t) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
  return 0;
}