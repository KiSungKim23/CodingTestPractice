#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    int Temp = 0;

    for (int i = left; i <= right; i++) {
        for (int j = 2; j <= i; j++) {
            if ((i % j) == 0) {
                Temp++;
            }
        }
        if (Temp % 2) answer += i;
        else answer -= i;

        Temp = 0;
    }


    return answer;
}
void main() {
	
    cout << solution(1, 13) << endl;
}


/*
* ���� ����
�� ���� left�� right�� �Ű������� �־����ϴ�. left���� right������ ��� ���� �߿���, ����� ������ ¦���� ���� ���ϰ�, ����� ������ Ȧ���� ���� �� ���� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1 �� left �� right �� 1,000
����� ��
left	right	result
13	17	43
24	27	52
����� �� ����
����� �� #1

���� ǥ�� 13���� 17������ ������ ����� ��� ��Ÿ�� ���Դϴ�.
��	���	����� ����
13	1, 13	2
14	1, 2, 7, 14	4
15	1, 3, 5, 15	4
16	1, 2, 4, 8, 16	5
17	1, 17	2
����, 13 + 14 + 15 - 16 + 17 = 43�� return �ؾ� �մϴ�.
����� �� #2

���� ǥ�� 24���� 27������ ������ ����� ��� ��Ÿ�� ���Դϴ�.
��	���	����� ����
24	1, 2, 3, 4, 6, 8, 12, 24	8
25	1, 5, 25	3
26	1, 2, 13, 26	4
27	1, 3, 9, 27	4
����, 24 - 25 + 26 + 27 = 52�� return �ؾ� �մϴ�.
*/