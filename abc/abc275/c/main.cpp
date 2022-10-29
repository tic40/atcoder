#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

bool check(vector<int>& x, vector<int>& y) {
	vector<int> v;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j];
			v.push_back(dx * dx + dy * dy);
		}
	sort(v.begin(), v.end());
	int l = v[0];
	if (l == 0) return false;
	return v[0]==l && v[1]==l && v[2]==l && v[3]==l && v[4]==l*2 && v[5]==l*2;
}

int main() {
  vector<string> s(9);
  REP(i,9) cin >> s[i];

  vector<P> pa;
  REP(i,9) REP(j,9) if (s[i][j] == '#') pa.emplace_back(i,j);

  int sz = pa.size();
  int ans = 0;
  REP(i,sz) {
    for(int j = i+1; j < sz; j++) {
      for(int k = j+1; k < sz; k++) {
        for(int l = k+1; l < sz; l++) {
          // i,j,k,lが正方形かどうか
          vector<int> x = {pa[i].first, pa[j].first, pa[k].first, pa[l].first};
          vector<int> y = {pa[i].second, pa[j].second, pa[k].second, pa[l].second};
          if (check(x,y)) ans++;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}