//https://school.programmers.co.kr/learn/courses/30/lessons/12912
#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b) 
{
    long long int large = std::max(a, b);
    long long int small = std::min(a, b);
    return (large + small)*(large-small+1) / 2;
}

//https://school.programmers.co.kr/learn/courses/30/lessons/12912
#include <bits/stdc++.h>

using namespace std;

long long solution(int a, int b) 
{
    return (long long int)(a+b)*(std::abs(a-b)+1) / 2;
}