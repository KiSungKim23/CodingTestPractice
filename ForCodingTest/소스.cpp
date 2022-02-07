#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std; 

vector<int> solution(long long n) {
    vector<int> answer;
    string snToString = to_string(n);

    for (int i = snToString.size() - 1; i >= 0; i--) {
        answer.push_back(snToString[i] - '0');
    }

    return answer;
}
void main() {
    vector<int> answer = solution(12345);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
}


/*
자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.

제한 조건
n은 10,000,000,000이하인 자연수입니다.
입출력 예
n	return
12345	[5,4,3,2,1]




*/
