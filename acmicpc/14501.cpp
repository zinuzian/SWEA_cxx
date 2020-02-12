#include <iostream>
#include <vector>

using namespace std;

int n,m;
int n_h, n_c;
vector<vector<int>> dist;
vector<vector<int>> house;
vector<vector<int>> chick;


int calcDist(vector<bool> comb){
    int sum=0;
    for(int i=0;i<m;i++){
        if(comb[i]){
            for(int j=0;j<n_h;j++){
                sum += dist[i][j];
            }
        }
    }
    return sum;
}

void combination(int k, int s){
    if(k == m) calcDist(t);
    else{
        for(int i=s;i<)
    }
}

int main(int argc, char const *argv[])
{
    int answer = 0;
    cin >> n >> m;

    

    int c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            if(c == 1){
                vector<int> pos;
                pos.push_back(i);
                pos.push_back(j);
                house.push_back(pos);
            }else if(c == 2){
                vector<int> pos;
                pos.push_back(i);
                pos.push_back(j);
                chick.push_back(pos);
            }
        }
    }
    n_h = house.size();
    n_c = chick.size();

    for(int y=0;y<n_c;y++){
        vector<int> row;
        for(int x=0;x<n_h;x++){
            int dy = house[y][0] - chick[x][0];
            int dx = house[y][0] - chick[x][0];
            dy = dy>0? dy:-dy;
            dx = dx>0? dx:-dx;
            row.push_back(dy+dx);
        }
        dist.push_back(row);
    }





    return 0;
}
