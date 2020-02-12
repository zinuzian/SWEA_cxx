#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int w, h;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<int>> map;
vector<vector<int>> visited;
queue<vector<int>> que;
queue<vector<int>> delq;

int bfs()
{
    int ret = 0;
    vector<int> pos;
    while (!que.empty())
    {
        pos = que.front();
        que.pop();
        int x = pos[1], y = pos[0];
        
        if(visited[y][x])
            continue;
        
        int is_border = 0;
        for (int dir = 0; dir < 4; dir++)
        {
            int new_y = y + dy[dir], new_x = x + dx[dir];
            if (map[new_y][new_x] == 0)
            {
                is_border = 1;
                break;
            }
        }

        if (is_border)
        {
            visited[y][x] = 1;
            delq.push(pos);
            ret += 1;
            for (int dir = 0; dir < 4; dir++)
            {
                int new_y = y + dy[dir], new_x = x + dx[dir];
                if (new_y >= h || new_y < 0 || new_x >= w || new_x < 0)
                    continue;
                if (visited[new_y][new_x] == 0 && map[new_y][new_x] == 1)
                {
                    vector<int> next_pos;
                    next_pos.push_back(new_y);
                    next_pos.push_back(new_x);
                    que.push(next_pos);
                }
            }
        }
    }
    return ret;
}

int dfs(int y, int x)
{
    int ret = 0;
    if (map[y][x] == 1)
    {
        vector<int> loc;
        loc.push_back(y);
        loc.push_back(x);
        que.push(loc);
        ret += bfs();
    }
    else
    {
        visited[y][x] = 1;
        for (int dir = 1; dir < 4; dir++)
        {
            int new_y = y+dy[dir], new_x = x + dx[dir];
            if (!(new_y >= h || new_y < 0 || new_x >= w || new_x < 0))
                if(visited[new_y][new_x] == 0)
                    ret += dfs(new_y, new_x);
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int cheese = 0;
    int now = 0;
    cin >> h >> w;
    int start_y = 0;
    for (int i = 0; i < h; i++)
    {
        vector<int> row;
        vector<int> v_row;
        for (int j = 0; j < w; j++)
        {
            int c;
            cin >> c;
            if(start_y == 0 && c == 1){
                start_y = i;
            }
            row.push_back(c);
            v_row.push_back(0);
            cheese += c;
        }
        map.push_back(row);
        visited.push_back(v_row);
    }

    while (cheese > 0)
    {
        now = 0;
        int flag = 1;
        for (int i = 0; i < h && flag; i++)
        {
            for (int j = 0; j < w && flag; j++)
            {
                if(i<start_y){
                    visited[i][j] = 1;
                    continue;
                }
                if (visited[i][j] == 0 && map[i][j] == 0)
                {
                    now += dfs(i, j);
                    flag = 0;
                }
            }
        }
        while(!delq.empty()){
            vector<int> pos = delq.front();
            delq.pop();
            cout << pos[0] << " " << pos[1] << endl;
            map[pos[0]][pos[1]] = 0;
        }
        cheese -= now;
        answer += 1;
    }

    cout << answer << endl;
    cout << now << endl;
}