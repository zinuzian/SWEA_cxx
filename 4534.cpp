#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

using namespace std;
int answer;
int n;
int dp[100001][2];
vector<vector<int>> tree;

void init()
{
    memset(dp, 0, sizeof(int) * 100001 * 2);
    answer = 0;
}

int main(int argc, char const *argv[])
{
    int T = 10;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        init();
        cin >> n;
        
        
        cout << "#" << test_case << " " << answer << endl;
    }
}