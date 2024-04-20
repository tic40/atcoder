#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  int x = stoi(s.substr(3,3));
  if (x == 316 || x == 0) { cout << "No" << endl; return 0; }
  cout << (x < 350 ? "Yes" : "No") << endl;
  return 0;
}