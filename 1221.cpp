#include <iostream>
#include <cstring>
using namespace std;
 
int n;
char num[91][91][91];
int cnt[10];
char numbers[10][3] = { 
    {'Z', 'R', 'O'},
    {'O', 'N', 'E'},
    {'T', 'W', 'O'},
    {'T', 'H', 'R'},
    {'F', 'O', 'R'},
    {'F', 'I', 'V'},
    {'S', 'I', 'X'},
    {'S', 'V', 'N'},
    {'E', 'G', 'T'},
    {'N', 'I', 'N'}
};
void init(){
    memset(cnt, 0, sizeof(int)*10);
}
int main()
{
    int T= 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    num['Z']['R']['O'] = 0;
    num['O']['N']['E'] = 1;
    num['T']['W']['O'] = 2;
    num['T']['H']['R'] = 3;
    num['F']['O']['R'] = 4;
    num['F']['I']['V'] = 5;
    num['S']['I']['X'] = 6;
    num['S']['V']['N'] = 7;
    num['E']['G']['T'] = 8;
    num['N']['I']['N'] = 9;

    freopen("input.txt", "r", stdin);
    cin >> T;

    for(int test_case = 1; test_case <= T; test_case++){
        init(); 
        char tt[10];
        cin >> tt >> n;
        for (int i = 0;i < n;i++)
        {
            cin >> tt;
            cnt[num[tt[0]][tt[1]][tt[2]]]++;
        }
 
        cout << "#" << test_case << endl;
        for (int i = 0;i < 10;i++)
        {
            for (int j = 0;j < cnt[i];j++)
            {
                cout << numbers[i][0] << numbers[i][1] << numbers[i][2] << " ";
            }
        }
 
        cout << endl;
    }
     
    return 0;
}