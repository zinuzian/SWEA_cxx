#include <iostream>
#include <vector>
// #include <stack>
// #include <queue>
#include <cstring>


using namespace std;
int numbers[11];
int op_left[4];
int n;
vector<int> cand;

void init(){
    memset(numbers, 0, sizeof(int)*11);
    memset(op_left, 0, sizeof(int)*4);
}


int calculate(int num[], int op[]){
    int ret= num[0];
    for(int i=0;i<n-1;i++){
        switch(op[i]){
        case 0:
            ret += num[i+1];
            break;
        case 1:
            ret -= num[i+1];
            break;
        case 2:
            ret *= num[i+1];
            break;
        case 3:
            ret /= num[i+1];
            break;
        }
    }
    return ret;
}

void op_dfs(int op, int op_perm[], int size){
    op_left[op] -= 1;
    op_perm[size++] = op;

    if(size == n-1){
        int a = calculate(numbers,op_perm);
        cand.push_back(a);
        --size;
    }else{
        for(int i=0;i<4;i++){
            if(op_left[i] > 0){
                op_dfs(i,op_perm, size);
            }
        }
    }
    op_left[op] += 1;
    return;
}



int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    init();
    cin >> n;

    int cnt=0;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }

    for(int i=0;i<4;i++){
        cin >> op_left[i];
    }

    int op_p[4];
    for(int i=0;i<4;i++){
        if(op_left[i] > 0){
            op_dfs(i, op_p,0);
        }
        
    }

    // for(auto i:cand){
    //     cout << i << " ";
    // }
    // cout << endl;

    int max = -1000000000, min = -max;
    for(auto i:cand){
        if(max < i){
            max = i;
        }
        if(min > i){
            min = i;
        }
    }
    cout << max << endl << min << endl;
        
    return 0;
}
