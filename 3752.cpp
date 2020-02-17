#include <iostream>
#include <vector>
using namespace std;
vector<int> possibleScoreAsc;
void init(){
    possibleScoreAsc.clear();
}
int binarySearch(int v, int s, int e){
    
    int m = (s+e)/2;
    if(possibleScoreAsc[m] == v){
        return m;
    }else if(possibleScoreAsc[m] > v){
        if(s == m){
            return -(s);
        }else{
            return binarySearch(v, s, m-1);
        }        
    }else{
        if(e == m){
            return -(e+1);
        }else{
            return binarySearch(v, m+1, e);
        }
    }
}

int main(int argc, char const *argv[])
{
    int T = 10;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case =1;test_case <= T;test_case++){
        init();
        int N;
        cin >> N;
        possibleScoreAsc.push_back(0);
        for(int i=0;i<N;i++){
            int temp;
            cin >> temp;
            int len = possibleScoreAsc.size();
            vector<int> temp_vec(len);
            for(int j=0;j<len;j++){
                temp_vec[j] = possibleScoreAsc[j];
            }
            for(int j=0;j<len;j++){
                int idx = binarySearch(temp_vec[j]+temp,0,possibleScoreAsc.size()-1);
                if(idx<0){
                    possibleScoreAsc.insert(possibleScoreAsc.begin()-idx, temp_vec[j]+temp);
                }
            }
        }
        cout << "#" << test_case << " " << possibleScoreAsc.size() << endl;
    }
    return 0;
}
