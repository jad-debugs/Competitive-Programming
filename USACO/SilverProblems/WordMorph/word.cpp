#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define pii pair<int, int>

int main()
{
    string start; cin >> start;
    string end; cin >> end;

    vector<string> words;
    words.push_back(start);
    words.push_back(end);

    int len = (int)start.size();

    vector<vector<int>> graph(20005);

    string s;
    while (cin >> s) {
        if ((int)s.size() != len)
            continue;

        for (int i = 0; i < (int)words.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < len; j++) {
                if (words[i][j] != s[j])
                    cnt++;
            }
            if (cnt == 1) {
                int nextIdx = (int)words.size();
                graph[i].push_back(nextIdx);
                graph[nextIdx].push_back(i);
                words.push_back(s);
            }
        }
    }


    return 0;
}
