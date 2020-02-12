#include <iostream>
#include <queue>
#include <cstring>
#include <string>


using namespace std;

int h, w, ret=0;
int map[50][50];

class Pos{
public:
    int x;
    int y;
    Pos(int x, int y){
        this->x = x;
        this->y = y;
    }
    Pos operator+(Pos& next){
        return Pos(this->x + next.x, this->y + next.y);
    }
    string toString(){
        return to_string(this->x) + " " + to_string(this->y);
    }
};
typedef struct node{
    Pos p;
    int nth;
};

Pos d[4] = {
    Pos(0,-1), 
    Pos(1,0), 
    Pos(0,1), 
    Pos(-1,0)
};

//bfs queue
queue<node> que;
//한 점에서 가장 멀리있는 최단거리
int shortest[50] = {0};

int bfs(){

    while(!que.empty()){
        node now = que.back();
        Pos nowp = now.p;
        int num = now.nth;
        que.pop();
        
        for(int i=0;i<4;i++){
            Pos nextp = nowp + d[i];
            node next = {nextp, num+1};
            que.push(next);
        }
    }
}



int main(int argc, char const *argv[])
{
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    
    cin >> h >> w;

    memset(map,0,sizeof(int)*50*50);
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            char c;
            cin >> c;
            if(c == 'L'){
                map[y][x] = 1;
            }
        }
    }




    


    // 출력
    cout << endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}