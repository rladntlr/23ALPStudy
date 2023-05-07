#include <bits/stdc++.h>//아 뭔말인지 몰라서 정답보고 하는중
using namespace std;

int n;

bool am[102][102];
bool vis[102];

bool dfs(int st, int tar) {
    fill(vis, vis + n + 2, 0);
    stack<int> s;
    s.push(st);

    while (!s.empty()) {
        int cur =s.top();
        s.pop();

        if (vis[cur]) 
            continue;
        if (cur != st) vis[cur] = 1;

        for (int nxt = 0; nxt < n; nxt++) {
            if (vis[nxt]) 
                continue;
            if (am[cur][nxt]) {
                if (nxt == tar) return true;
                s.push(nxt);
            }
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> am[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dfs(i, j) << ' ';
        cout << '\n';
    }
}