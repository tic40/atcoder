#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  string s; cin >> s;
  vector<int> cnt1(26);
  for(auto c: s) cnt1[c-'a']++;
  vector<int> cnt2(101);
  REP(i,26) cnt2[cnt1[i]]++;

  int ok = 1;
  for(int i = 1; i <= 100; i++) ok &= (cnt2[i] == 0 || cnt2[i] == 2);
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}