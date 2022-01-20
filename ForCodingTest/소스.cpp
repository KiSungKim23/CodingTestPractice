#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> answerArr;
    
    while (true) {
        answerArr.push_back(n % 3);
        if (n / 3 == 0) break;
        n /= 3;
    }

    int iSquared = 1;

    while (answerArr.size() != 0)
    {
        
        answer += answerArr.back() * iSquared;
        answerArr.pop_back();
        iSquared *= 3;
    }

    return answer;
}
void main() {
    cout << solution(45);

}


/*
* ���� ����
�ڿ��� n�� �Ű������� �־����ϴ�. n�� 3���� �󿡼� �յڷ� ������ ��, �̸� �ٽ� 10�������� ǥ���� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
n�� 1 �̻� 100,000,000 ������ �ڿ����Դϴ�.
����� ��
n	result
45	7
125	229
����� �� ����
����� �� #1

���� �����ϴ� ������ ������ �����ϴ�.
n (10����)	n (3����)	�յ� ����(3����)	10�������� ǥ��
45	1200	0021	7
���� 7�� return �ؾ� �մϴ�.
����� �� #2

���� �����ϴ� ������ ������ �����ϴ�.
n (10����)	n (3����)	�յ� ����(3����)	10�������� ǥ��
125	11122	22111	229
���� 229�� return �ؾ� �մϴ�.
*/