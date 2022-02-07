#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std; 

vector<int> solution(int n, int m) {
    vector<int> answer;

    vector<int> n약수;
    vector<int> m약수;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            n약수.push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (m % i == 0) {
            m약수.push_back(i);
        }
    }

    int n_for공약수 = n약수.size() - 1;
    int m_for공약수 = m약수.size() - 1;

    while (n_for공약수 != 0 || m_for공약수 != 0) {
        if (n약수[n_for공약수] == m약수[m_for공약수]) {
            answer.push_back(m약수[m_for공약수]);
            break;
        }
        if (n약수[n_for공약수] < m약수[m_for공약수]) {
            if (m_for공약수 > 0) m_for공약수--;
        }
        else {
            if (n_for공약수 > 0) n_for공약수--;
        }
    }

    if (answer.size() == 0) answer.push_back(0);
        

    int n_for공배수 = n;
    int m_for공배수 = m;
    int n_for공배수_count = 1;
    int m_for공배수_count = 1;

    while (n_for공배수 != m_for공배수) {
        if (n_for공배수 > m_for공배수) {
            m_for공배수 = m * ++m_for공배수_count;
        }
        else {
            n_for공배수 = n * ++n_for공배수_count;
        }
    }

    answer.push_back(n_for공배수);

    return answer;
}

void main() {
    cout << solution(3, 12)[0] << endl;
    cout << solution(3,12)[1] << endl;
}


/*
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요. 배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다. 
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

제한 사항
두 수는 1이상 1000000이하의 자연수입니다.
입출력 예
n	m	return
3	12	[3, 12]
2	5	[1, 10]
입출력 예 설명
입출력 예 #1
위의 설명과 같습니다.

입출력 예 #2
자연수 2와 5의 최대공약수는 1, 최소공배수는 10이므로 [1, 10]을 리턴해야 합니다.



*/
