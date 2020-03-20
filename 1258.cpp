#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
class Square{
    public:
    int x;
    int y;
    int size;
    Square(int x, int y){
        this->x = x;
        this->y = y;
        this->size = x*y;
    }
    bool operator<(const Square &that) const{
        if(this->size == that.size){
            return this->y < that.y;
        }else{
            return this->size < that.size;
        }
        
    }
    void print(){
        cout << " " << this -> y << " " << this -> x;
    }
};
vector<Square> lst;

bool visited[100][100];
int mat[100][100];
int n;
void init(){
    memset(visited, 0, sizeof(bool)*100*100);
    lst.clear();
}

void dfs(){
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(!visited[y][x] && mat[y][x] != 0){
                int nx = x, ny = y;
                while(nx<n && mat[y][nx] != 0) nx++;
                while(ny<n && mat[ny][x] != 0) ny++;
                for(int i=y;i<ny;i++){
                    for(int j=x;j<nx;j++){
                        visited[i][j] = true;
                    }
                }
                lst.push_back(Square(nx-x, ny-y));
            }
            
        }
    }
}

int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        init();
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> mat[i][j];
            }
        }
        dfs();
        sort(lst.begin(), lst.end());
        cout << "#" << test_case << " " << lst.size();
        for(auto elem: lst){
            elem.print();
        }
        cout << '\n';
    }
}