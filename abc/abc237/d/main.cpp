#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int n; string s;
  cin >> n >> s;

  deque<int> ans = {n};
  for(int i = n-1; 0 <= i; i--) {
    if (s[i] == 'L') ans.push_back(i);
    else ans.push_front(i);
  }
  for(int v: ans) cout << v << " ";
  cout << endl;
  /*
  deque<int> fr, bk;
  REP(i,n) {
    if (s[i] == 'L') bk.push_front(i);
    else fr.push_back(i);
  }
  if (s[n-1] == 'L') bk.push_front(n);
  else fr.push_back(n);

  for(int v: fr) cout << v << " ";
  for(int v: bk) cout << v << " ";
  cout << endl;
  */
  return 0;
}