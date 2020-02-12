#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int map[16][16];
bool visited[16][16];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int s_x, s_y;
int e_x, e_y;
bool found = false;

void init(){
    memset(visited, false, sizeof(bool)*16*16);
    found = false;
}

void backtracking(int y, int x){
    if(x == e_x && y == e_y){
        found =  true;
        return;
    }

    for(int dir=0;dir<4 && !found;dir++){
        int nx=x+dx[dir], ny=y+dy[dir];
        if(map[ny][nx] != 1 && !visited[ny][nx]){
            visited[ny][nx] = true;
            backtracking(ny,nx);
        }
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	// cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        int t;
        cin >> t;

        

        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                char k;
                cin >> k;
                int c = (int)(k-'0');
                if( c == 2 ){
                    s_x = j;
                    s_y = i;
                }else if( c == 3 ){
                    e_x = j;
                    e_y = i;
                }
                map[i][j] = c;
            }
        }
        visited[s_y][s_x] =  true;
        backtracking(s_y, s_x);

        cout << "#" << test_case << " " << found? 1:0;
        cout << endl;

    }
    return 0;
}