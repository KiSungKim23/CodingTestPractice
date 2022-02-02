#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;


int solution(int n) {
    for (int i = 2; i < 1000000; i++) {
        if ((n % i) == 1) {
            return i;
        }
    }
    return 0;
}

void main() {

    cout << solution(10) << endl;

}


/*
���� ����

�ڿ��� n�� �Ű������� �־����ϴ�. n�� x�� ���� �������� 1�� �ǵ��� �ϴ� ���� ���� �ڿ��� x�� return �ϵ��� solution �Լ��� �ϼ����ּ���. ���� �׻� �������� ����� �� �ֽ��ϴ�.

���ѻ���
3 �� n �� 1,000,000
����� ��
n	result
10	3
12	11
����� �� ����
����� �� #1

10�� 3���� ���� �������� 1�̰�, 3���� ���� �ڿ��� �߿��� ������ ������ �����ϴ� ���� �����Ƿ�, 3�� return �ؾ� �մϴ�.
����� �� #2

12�� 11�� ���� �������� 1�̰�, 11���� ���� �ڿ��� �߿��� ������ ������ �����ϴ� ���� �����Ƿ�, 11�� return �ؾ� �մϴ�.

*/