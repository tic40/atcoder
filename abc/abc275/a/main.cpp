#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<P> p(n);
  REP(i,n) {
    int h; cin >> h;
    p.emplace_back(h,i+1);
  }
  sort(p.begin(),p.end());
  cout << p.back().second << endl;
  return 0;
}