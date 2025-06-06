#include <bits/stdc++.h>
using namespace std;
int N, cnt, dp[505][505];
std::vector<std::pair<int, int>> arr;
int Check(int start, int end)
{
    if(start >= end) return 0;
    int& ref = dp[start][end];
    if(ref != -1) return ref;
    ref = INT_MAX;
    for(int mid = start; mid < end; mid++)
        ref = std::min(ref, Check(start, mid) + Check(mid+1, end) + arr[start].first * arr[mid].second * arr[end].second);
    return ref;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    arr.resize(N+1);
    for(int i = 1; i <= N; i++)  std::cin >> arr[i].first >> arr[i].second;
    std::memset(dp, -1, sizeof(dp));
    std::cout << Check(1, N);
    return 0;
}

--------

#include <bits/stdc++.h>
using namespace std;
int N, cnt, dp[505][505];
std::vector<std::pair<int, int>> arr;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    arr.resize(N+1);
    for(int i = 1; i <= N; i++)  std::cin >> arr[i].first >> arr[i].second;
    
    for(int i = 1; i < N; i++) //len, 시작지점 / 시작지점+len으로 dp의 최소값을 구해야한다
    {
        for(int j = 1; i + j <= N; j++) //시작지점, i+j(끝지점) <= N (마지막행렬)
        {
            dp[j][i+j] = INT_MAX;
            for(int k = j; k < i + j; k++) //중간지점, dp[시작지점][끝지점] = dp[시작지점] + dp[끝지점] + 시작지점[0] * 중간지점[1] * 끝지점[1]
            {
                dp[j][i+j] = std::min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + arr[j].first * arr[k].second * arr[i+j].second);
            }
        }
    }
    std::cout << dp[1][N];
    return 0;
}
