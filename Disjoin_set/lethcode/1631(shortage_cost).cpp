#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights)
{
    int n = heights.size();
    int m = heights[0].size();


    vector<vector<int>> dist(n, vector<int>(m, 1e9));


    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});


    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int effort = cur[0];
        int r = cur[1];
        int c = cur[2];


        if (r == n - 1 && c == m - 1)
            return effort;


        if (effort > dist[r][c])
            continue;


        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                continue;

            int diff = abs(heights[r][c] - heights[nr][nc]);


            int new_effort = max(effort, diff);

            if (new_effort < dist[nr][nc])
            {
                dist[nr][nc] = new_effort;
                pq.push({new_effort, nr, nc});
            }
        }
    }

    return 0;
}

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << minimumEffortPath(heights) << endl;  // Output: 2

    return 0;
}
