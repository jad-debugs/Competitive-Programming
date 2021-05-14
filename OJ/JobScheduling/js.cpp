// Author : Jad Isaac
// ID: jadDebugs
// TASK: -----
// LANG: C++                 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int n, d, m;

bool works(int robots, vector<pii> jobs)
{
    int endT[robots] = {0};
    int maxD = 0;

    for (int i = 0, cur = 0; i < m; i++, cur++) {
        if (cur == robots)
            cur = 0;
        // if our end time for this job is > than our start time for this job
        // there will be delay
        if (endT[cur] + 1 > jobs[i].f) {
            endT[cur]++;
            maxD = max(maxD, endT[cur] - jobs[i].f);
        }
        else
            endT[cur] = jobs[i].f;
    }
    return maxD <= d;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); 

    cin >> n >> d >> m;

    // first = day of req
    // second = id or req
    vector<pii> jobs(m);

    for (int i = 0; i < m; i++) {
        cin >> jobs[i].f;
        jobs[i].s = i+1;
    }
    sort(begin(jobs), end(jobs));
    int l = 0, r = m;

    while (l < r) {
        int mid = l + (r-l)/2;
        if (works(mid, jobs))
            r = mid;
        else
            l = mid+1;
    }
    cout << l << '\n';

    const int hi = 1e5+12;
    vector<int> ans[hi];
    int endT[l] = {0};

    for (int i = 0, cur = 0; i < m; i++, cur++) {
        if (cur == l)
            cur = 0;
        endT[cur] = max(jobs[i].f, endT[cur]+1);
        ans[endT[cur]].push_back(jobs[i].s);
    }

    for (int i = 1; i <= n; i++) {
        for (int x: ans[i])
            cout << x << ' ';
        cout << "0\n";
    }
    return 0;
}
