#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int k; cin >> k;
  string s,t; cin >> s >> t;

  int ss = s.size();
  int ts = t.size();

  if (abs(ss-ts) > 1) { cout << "No" << endl; return 0; }

  if (ss == ts) {
    int cnt = 0;
    REP(i,ss) { if (s[i] != t[i]) cnt++; }
    cout << (cnt <= 1 ? "Yes" : "No") << endl;
  }

  if (ss < ts) {
    s.push_back('_');
    int si = 0;
    int cnt = 0;
    REP(i,ts) {
      if (s[si] != t[i]) {
        cnt++;
        if (cnt > 1) { cout << "No" << endl; return 0; }
      } else {
        si++;
      }
    }
    cout << "Yes" << endl;
  }

  if (ss > ts) {
    int cnt = 0;
    int si = 0;
    REP(i,(int)t.size()) {
      while (s[si] != t[i]) {
        si++;
        cnt++;
        if (cnt > 1) { cout << "No" << endl; return 0; }
      }
      si++;
    }
    cout << "Yes" << endl;
  }

  return 0;
}