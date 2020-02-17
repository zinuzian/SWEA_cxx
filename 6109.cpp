#include <iostream>
#include <vector>
#include <cstring>
#include <string>



using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int start_x[4] = {0, };
int start_y[4] = {0, };



void init(int N){
    start_x[1] = N-1;
    start_y[2] = N-1;
}
void swap(int& a, int& b){
    int temp1 = a;
    a = b;
    b = temp1;
}
vector<vector<int>>& move(int dir, int N, vector<vector<int>>& board){
    if(dir%2 == 0){
        for(int x=0;x<N;x++){
            int accum = start_y[dir];
            int y = start_y[dir];
            bool flag = false;
            while(y>=0 && y<N){
                if(board[y][x] != 0){
                    swap(board[y][x], board[accum][x]);
                    if(flag && board[accum][x] == board[accum-dy[dir]][x]){
                        board[accum-dy[dir]][x] *= 2;
                        board[accum][x] = 0;
                        flag = false;
                    }else{
                        flag = true;
                        accum += dy[dir];
                    }
                }
                y += dy[dir];
            }
        }
    }else{
        for(int y=0;y<N;y++){
            int accum = start_x[dir];
            int x = start_x[dir];
            bool flag = false;
            while(x>=0 && x<N){
                if(board[y][x] != 0){
                    swap(board[y][x], board[y][accum]);
                    if(flag && board[y][accum] == board[y][accum-dx[dir]]){
                        board[y][accum-dx[dir]] *= 2;
                        board[y][accum] = 0;
                        flag = false;
                    }else{
                        flag = true;
                        accum += dx[dir];
                    }
                    
                }
                x += dx[dir];
            }
        }
    }
    return board;
}
void print_board(int len, vector<vector<int>>& board){
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
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
        int N;
        char input[6];
        cin >> N >> input;
        init(N);
        vector<vector<int>> board;
        for(int i=0;i<N;i++){
            vector<int> row;
            for(int j=0;j<N;j++){
                int temp;
                cin >>temp;
                row.push_back(temp);
            }
            board.push_back(row);
        }

        
        if(!strcmp(input,("up"))){
            board = move(0, N, board);
        }else if(!strcmp(input,"right")){
            board = move(1, N, board);
        }else if(!strcmp(input,("down"))){
            board = move(2, N, board);
        }else if(!strcmp(input,"left")){
            board = move(3, N, board);
        }
        cout << "#" << test_case << endl;
        print_board(N, board);
    }
    return 0;
}