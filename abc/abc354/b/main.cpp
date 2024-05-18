#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,tot = 0; cin >> n;
  vector<string> s(n);
  REP(i,n) {
    cin >> s[i];
    int c; cin >> c;
    tot += c;
  }
  sort(s.begin(),s.end());
  cout << s[tot%n] << endl;
  return 0;
}