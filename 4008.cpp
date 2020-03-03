#include <iostream>
#include <cstring>

using namespace std;
int _max, _min;
int n;
int opNum[4];
int ops[11];
int nums[12];

void init(){
    _max = -2147483647;
    _min = 2147483647;
}
void dfs(int nth){
    if(nth == n-1){
        int ret = nums[0];
        for(int i=0;i<n-1;i++){
            switch(ops[i]){
            case 0:
                ret += nums[i+1];
                break;
            case 1:
                ret -= nums[i+1];
                break;
            case 2:
                ret *= nums[i+1];
                break;
            case 3:
                ret /= nums[i+1];
                break;
            }
        }
        if(_max < ret){
            _max = ret;
        }
        if(_min > ret){
            _min = ret;
        }
        return;
    }
    for(int i=0;i<4;i++){
        if(opNum[i] > 0){
            opNum[i]--;
            ops[nth] = i;
            dfs(nth+1);
            opNum[i]++;
        }
    }
}
int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        init();
        int answer = 0;
        cin >> n;
        for(int i=0;i<4;i++){
            cin >> opNum[i];
        }
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        
        dfs(0);
        answer = _max - _min;
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}