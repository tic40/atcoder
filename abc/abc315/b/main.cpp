  #include <bits/stdc++.h>
  using namespace std;
  #define REP(i,n) for(int i=0;i<n;i++)
  #define endl '\n'

  int main() {
    int m; cin >> m;
    vector<int> d(m);
    REP(i,m) cin >> d[i];
    int tot = accumulate(d.begin(),d.end(),0);
    int mid = (tot+1)/2;

    REP(i,m) {
      if (mid > d[i]) mid -= d[i];
      else {
        cout << i+1 << " " << mid << endl;
        break;
      }
    }
    return 0;
  }