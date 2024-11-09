#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define f first
#define s second
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    double v1 = (p1.f * 1.0) / p1.s;
    double v2 = (p2.f * 1.0) / p2.s;
    return v1 > v2;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second; // v[i].first = price and v[i].second = weight
    }
    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    int w; cin >> w;
    for(int i = 0; i < n; i++)
    {
        if(w >= v[i].s)
        {
            ans += v[i].f;
            w -= v[i].s;
            continue;
        }
        double value_pw = (1.0 * v[i].f) / v[i].s;
        ans += (value_pw * w);
        w = 0;
    }
    cout << ans << endl;
    return 0;
}
