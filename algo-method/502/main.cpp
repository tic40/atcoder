#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

struct student {
  int point;
  int no;
  bool operator<(const student& right) const {
    return point == right.point ? no > right.no : point < right.point;
  }
};

int main() {
  int n; cin >> n;

  vector<student> vp(n);
  REP(i,n) vp[i] = { 0, i };
  REP(i,n) {
    int a; cin >> a;
    vp[a].point++;
  }

  sort(vp.rbegin(), vp.rend());
  REP(i,n) cout << vp[i].no << " " << vp[i].point << endl;
  return 0;
}