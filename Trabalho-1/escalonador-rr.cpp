#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;
typedef vector<int> vi;
#define pb push_back
#define ln "\n"

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, T, time = 0;
  cin >> N >> T;

  queue<ii> q;

  while (N--) {
    int pid, t;
    cin >> pid >> t;
    q.push(ii(pid, t * 1000));
  }

  while (!q.empty()) {
    ii p = q.front();
    p.second -= T;

    if (p.second <= 0)
      (p.second < 0 ? time += T + p.second : time += T), q.pop(),
          cout << p.first << " (" << time << ")\n";
    else
      time += T, q.pop(), q.push(p);
  }

  return 0;
}
