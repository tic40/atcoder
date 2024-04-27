#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> b;
  REP(i,n) {
    b.push_back(a[i]);
    while(b.size() > 1) {
      if (b[b.size() - 1] != b[b.size() - 2]) break;
      int add = b.back()+1;
      b.pop_back(); b.pop_back();
      b.push_back(add);
    }
  }

  cout << b.size() << endl;
  return 0;
}