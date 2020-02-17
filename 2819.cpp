#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int arr[4][4] = {0,};
set<int> possible;

void init(){
    memset(arr,0,sizeof(int)*4*4);
    possible.clear();
}

void dfs(int y, int x, int nowNum, int remain){
    
    if(remain == 0){
        possible.insert(nowNum);
    }else{
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir], ny = y + dy[dir];
            if(nx>=0 && nx < 4 && ny >=0 && ny < 4){
                dfs(ny,nx, nowNum*10+arr[ny][nx], remain-1);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int T=10;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case=1;test_case<=T;++test_case){
        init();
        int answer = 0;
        for(int y=0;y<4;y++){
            for(int x=0;x<4;x++){
                cin >> arr[y][x];
            }
        }
        for(int y=0;y<4;y++){
            for(int x=0;x<4;x++){
                dfs(y,x,arr[y][x], 6);
            }   
        }
        

        answer = possible.size();
        
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}
