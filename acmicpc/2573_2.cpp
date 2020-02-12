#include <iostream>
#include <vector>


using namespace std;
int map[300][300] = {0};
int **visited;
int **glac_visited;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int h, w, ret=0;

int dfs(int y, int x, int**temp){
    
    // cout << y << " " << x << endl;
    if(map[y][x] != 0){
        //glacier
        ret += 1;
        for (int dir = 0; dir < 4; dir++){
            // water check
            int new_y = y + dy[dir], new_x = x + dx[dir];
            if (new_y >= 0 && new_x >= 0 && new_y < h && new_x < w){
                if(visited[new_y][new_x] == 0){
                    if(map[new_y][new_x] == 0){
                        temp[y][x] -= 1;
                    }else{
                        visited[new_y][new_x] = 1;
                        dfs(new_y, new_x, temp);
                    }
                }
            }
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int nGlac = 0 ,dfsGlac=0;
    cin >> h >> w;

    visited = new int*[h];
    int start_x, start_y, glac_found = false;
    for(int y=0;y<h;y++){
        visited[y] = new int[w];
        for(int x=0;x<w;x++){
            visited[y][x] = 0;
            int t;
            cin >> t;
            if(t!=0){
                nGlac += 1;
                if(!glac_found){
                    start_x = x;
                    start_y = y;
                    glac_found = true;
                }
            }
            map[y][x] = t;
        }
    }

    int **temp = new int*[h];
    for(int i=0;i<h;i++){
        temp[i] = new int[w];
        for(int j=0;j<w;j++){
            temp[i][j] = map[i][j];
        }
    }

    while(start_y < h){
        visited[start_y][start_x] = 1;
        dfsGlac = dfs(start_y, start_x, temp);
        if(nGlac != dfsGlac) break;


        nGlac = 0;
        glac_found = false;
        int n_x, n_y;
        for(int y=start_y;y<h;y++){
            for(int x=0;x<w;x++){
                if(map[y][x] != 0){
                    map[y][x] = (temp[y][x] >= 0)? temp[y][x] : 0;
                
                    if(map[y][x] != 0){
                        // cout << y << " " << x << endl;
                        nGlac += 1;
                        if(!glac_found){
                            glac_found = true;
                            n_x = x;
                            n_y = y;  
                        }
                    }

                    visited[y][x] = 0;
                    temp[y][x] = map[y][x];
                }
                
            }
        }
        ret = 0;
        start_y = n_y;
        start_x = n_x;
        answer += 1;

        //출력
        // cout << endl;
        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < w; j++)
        //     {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
    }
        
    cout<<answer<<endl;
    // getchar();
    return 0;
}
