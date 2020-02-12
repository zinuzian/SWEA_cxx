#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>


using namespace std;
int mat[20][20];
int n;
vector<int> diffs;

void init(){
    memset(mat, 0, sizeof(int)*20*20);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int calcDiff(const bool set[]){
    int s1=0,s2=0;
    
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            if(i != j){
                if(set[i] && set[j])
                    s1 += mat[i][j];
                else if(!set[i] && !set[j])
                    s2 += mat[i][j];
            }
        }
    }
    
    int diff = s1-s2;
    return (diff>0)? diff:-diff;
}

// nCr = n-1Cr-1 + n-1Cr
void comb(bool set[], int idx, int n, int r){
    if(r == 0){
        int diff = calcDiff(set);
        diffs.push_back(diff);
    }else if(n == 0){
        return;
    }else{
        set[idx] = true;
        comb(set, idx, n-1, r-1);
        set[idx] = false;
        comb(set, idx, n-1,r);

    }
}

int main(int argc, char const *argv[])
{
    init();
    
    int answer = 0;
    
    cin >> n;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin >> mat[y][x];
        }
    }

    bool *set = new bool[n];
    memset(set, false, sizeof(bool)*n);
    comb(set, 0, n, n/2);

    cout << "diffs: ";
    for(int i:diffs){
        cout << i << " ";
    }
    cout << endl;


    return 0;
}
