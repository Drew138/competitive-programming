#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;  // int vec
typedef vector<vi> vvi;  // int vec vec
typedef vector<pii> vpi; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type, vector<type>, greater<type>>
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define nl "\n"
#define in(t) while (t--)

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}

int main() {
  ios ll t;
  cin >> t;
  in(t) {
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, ll> indices;
    vector<pair<ll, ll>> arr, tmp;
    forn(i, m) {
      ll point, weight;
      cin >> point >> weight;
      arr.push_back({weight, point});
      indices[point] = i;
    }
    sort(all(arr));
    ll ans = 0;
    for (ll i = 0; i < 2 * n; ++i) {
      ans += arr[i].first;
      tmp.push_back(arr[i]);
    }
    sort(all(tmp), sortbysec);
    ll i = 0, j = tmp.size() - 1;
    cout << ans << nl;
    while (i < j) {
      cout << indices[tmp[i].second] + 1 << " " << indices[tmp[j].second] + 1
           << nl;
      ++i;
      --j;
    }
    cout << nl;
  }
}
