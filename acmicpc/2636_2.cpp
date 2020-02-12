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

int dfs(int y, int x)
{
    visited[y][x] = 1;
    int ret = 0;
    if (map[y][x] == 1)
    {
        vector<int> loc;
        loc.push_back(y);
        loc.push_back(x);
        que.push(loc);
        ret += 1;
    }
    else
    {
        for (int dir = 0; dir < 4; dir++)
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


    for (int i = 0; i < h; i++)
    {
        vector<int> row;
        vector<int> v_row;
        for (int j = 0; j < w; j++)
        {
            int c;
            cin >> c;
            row.push_back(c);
            v_row.push_back(0);
            cheese += c;
        }
        map.push_back(row);
        visited.push_back(v_row);
    }

    while(cheese > 0){
        int y,x;
        bool flag = true;
        for(y=0;y<h&&flag;y++){
            for(x=0;x<w&&flag;x++){
                if (visited[y][x] == 0)
                    flag = false;
            }
        }
        x -= 1;
        y -= 1;
        // cout<<"found: ";
        // cout << y << " " << x << endl;
        now = dfs(y,x);
        while(!que.empty()){
            vector<int> pos = que.front();
            que.pop();
            // cout << pos[0] << " " << pos[1] << endl;
            map[pos[0]][pos[1]] = 0;
        }
        for(y=0;y<h;y++){
            for(x=0;x<w;x++){
                visited[y][x] = 0;
            }
        }
        cheese -= now;
        answer += 1;
    }

    cout << answer << endl;
    cout << now << endl;
    return 0;
}
