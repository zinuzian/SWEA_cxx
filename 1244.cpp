#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        
        int answer=0;
        int num, avail;
        cin >> num >> avail;
        vector<int> list;
        while(num!=0){
            list.insert(list.begin(), num%10);
            num /= 10;
        }
        int cnt = 0;
        int len = list.size();
        
        for(int i=0;cnt<avail && i<len-1;i++){
            int max=i;
            vector<int> s;
            int smalls=0;
            // max들 찾기
            for(int j=i+1;j<len;j++){
                if(list[max] <= list[j]){
                    if(list[max] != list[j]){
                        s.clear();
                        max = j;
                    }
                    s.push_back(j);   
                }else if(list[i] > list[j]){
                    smalls++;
                }
            }

            // max 조정
            if(max != i){
                if(s.size() != 1)
                    max = s[s.size()-1-smalls];
                int temp = list[i];
                list[i] = list[max];
                list[max] = temp;
                cnt++;
            }
        }

        for(int i=0;i<len-1 && cnt < avail;i++){
            for(int j=i+1;j<len;j++){
                if(list[i] == list[j]){
                    cnt=avail;
                    break;
                }
            }
        }

        int diff = avail - cnt;
        for(;diff>0;diff--){
            int temp = list[len-1];
            list[len-1] = list[len-2];
            list[len-2] = temp;
        }

        int mul=1;
        for(int i=len-1;i>=0;i--){
            answer += list[i] * mul;
            mul *= 10;
        }
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}
