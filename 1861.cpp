#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<vector<int>> arr;
int maxDist;
int maxRoomNum;

void init(int n){
    for(int j=0;j<arr.size();j++){
        arr[j].clear();
    }
    arr.clear();

    for(int j=0;j<n;j++){
        vector<int> row;
        for(int i=0;i<n;i++){
            row.push_back(0);
        }
        arr.push_back(row);
    }
    maxDist = 0;
    maxRoomNum = 0;
}

int dfs(int y, int x, int n){
    int ret=1;
    for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir], ny = y + dy[dir];
        if(nx>=0 && nx < n && ny >=0 && ny < n){
            //이동하려는 방에 적힌 숫자가 현재 방에 적힌 숫자보다 정확히 1 더 커야 한다.
            int diff = arr[ny][nx] - arr[y][x];
            if(diff == 1){
                ret += dfs(ny,nx, n);
            }
        }
    }
    return ret;
    
}
int main(int argc, char const *argv[])
{
    int T=10;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case=1;test_case<=T;++test_case){
        int n;
        cin >> n;
        
        init(n);
        int answer = 0;
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                cin >> arr[y][x];
            }
        }
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                //처음 어떤 수가 적힌 방에서 있어야
                int temp;
                temp = dfs(y, x, n);
                if(temp == maxDist && maxRoomNum > arr[y][x]){
                    maxRoomNum = arr[y][x];
                }
                else if(temp > maxDist){
                    maxDist = temp;
                    maxRoomNum = arr[y][x];     
                }
                
            }   
        }
        
        cout << "#" << test_case << " " << maxRoomNum << " " << maxDist << endl;
    }
    return 0;
}
