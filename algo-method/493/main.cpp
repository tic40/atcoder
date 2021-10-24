#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

struct student {
  int math;
  int english;
  int no;
  string name;
  int sum() const { return math + english; }
  bool operator<(const student& r) const {
    if (math != r.math) return math > r.math;
    if (sum() != r.sum()) return sum() < r.sum();
    return no < r.no;
  }
};

int main() {
  int n; cin >> n;
  vector<student> vp(n);
  REP(i,n) {
    string s;
    int a,b;
    cin >> s >> a >> b;
    vp[i] = { a, b, i, s };
  }

  sort(vp.begin(),vp.end());
  for(auto v: vp) cout << v.name << " " << v.math << " " << v.english << endl;
  return 0;
}