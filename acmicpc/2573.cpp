#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<vector<int>> _map;
vector<vector<int>> visited;
vector<vector<int>> glac_visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int n, m;

int dfs(int y, int x, vector<vector<int>> &temp)
{

    visited[y][x] = 1;
    if (_map[y][x] != 0)
    {
        temp[y][x] = temp[y][x] - 1;
    }
    else
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int new_y = y + dy[dir], new_x = x + dx[dir];
            if (new_y >= 0 && new_x >= 0 && new_y < n && new_x < m)
            {
                if (_map[new_y][new_x] != 0 || visited[new_y][new_x] == 0)
                    dfs(new_y, new_x, temp);
            }
        }
    }
}

bool is_divided()
{
    int start_x, start_y, end = 0;
    for (start_y = 0; start_y < n && !end; start_y++)
    {
        for (start_x = 0; start_x < m; start_x++)
        {
            if (_map[start_y][start_x] != 0)
            {
                end = 1;
                break;
            }
        }
    }
    start_y -= 1;
    glac_visited = vector<vector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        glac_visited[i] = vector<int>(m, 0);
    }

    vector<int *> st;
    int pos[2] = {start_y, start_x};
    st.push_back(pos);

    while (!st.empty())
    {
        int *now = st.back();
        st.pop_back();
        glac_visited[now[0]][now[1]] = 1;
        for (int dir = 0; dir < 4; dir++)
        {
            int new_y = now[0] + dy[dir], new_x = now[1] + dx[dir];
            if (new_y >= 0 && new_x >= 0 && new_y < n && new_x < m)
            {
                if (_map[new_y][new_x] != 0 && glac_visited[new_y][new_x] == 0){
                    st.push_back(new int[2]{new_y, new_x});
                    glac_visited[new_y][new_x] = 1;
                }
            }
        }
        
        
    }
    for (start_y = 0; start_y < n; start_y++)
    {
        for (start_x = 0; start_x < m; start_x++)
        {
            if (_map[start_y][start_x] != 0 && glac_visited[start_y][start_x] == 0)
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        vector<int> v_row;
        for (int j = 0; j < m; j++)
        {
            int c;
            cin >> c;
            row.push_back(c);
            v_row.push_back(0);
        }
        _map.push_back(row);
        visited.push_back(v_row);
    }

    while (true)
    {
        vector<vector<int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = vector<int>(m, 0);
        }
        //dfs
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (visited[y][x] == 0 && _map[y][x] == 0)
                {
                    dfs(y, x, temp);
                }
            }
        }
        //계산
        answer += 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = 0;
                _map[i][j] += temp[i][j];
                if (_map[i][j] < 0)
                {
                    _map[i][j] = 0;
                }
            }
        }
        
        //출력
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << _map[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        if (is_divided())
        {
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
