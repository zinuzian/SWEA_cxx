#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;

int n=0, rain_max=0;
int map[100][100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dfs(int y, int x, int rain_lev){
    if(y>=n || y<0 || x>=n || x<0) return 0;
    if(map[rain_lev][y][x] > 0){
        map[rain_lev][y][x] = 0;
        for(int dir=0;dir<4;dir++){
            dfs(y+dy[dir], x+dx[dir], rain_lev);
        }
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 1;
    

    cin >> n;
    memset(map,0,sizeof(int)*100*100*100);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;
            cin >> t;
            t-='0';
            if(rain_max < t){
                rain_max = t;
            }
            for(int k=0;k<100;k++){
                map[k][i][j] = t-k;
            } 
        }
    }

    
    
    for(int k=1;k<rain_max;k++){
        int local_max = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[k][i][j] > 0){
                    local_max += dfs(i,j,k);
                }
            }
        }
        if(local_max > answer)
            answer = local_max;
    }
    cout << answer << endl;
    return 0;
}

