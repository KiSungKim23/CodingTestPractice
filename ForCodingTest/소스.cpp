#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std;


long long solution(int price, int money, int count)
{
    long long answer = 0;

    for (int i = 0; i < count; i++) {
        answer += (i + 1) * price;
    }

    cout << money - answer << endl;


    return (money - answer) < 0 ? (answer - money) : 0;
}

void main() {

    cout << solution(3,50,4) << endl;

}


/*
���� ����

���� ���� ���̱ⱸ�� �αⰡ �ſ� ���� ���� ������ �ʽ��ϴ�.
�� ���̱ⱸ�� ���� �̿��� price�� �ε�, ���̱ⱸ�� N �� ° �̿��Ѵٸ� ���� �̿���� N�踦 �ޱ�� �Ͽ����ϴ�. ��, ó�� �̿�ᰡ 100�̾��ٸ� 2��°���� 200, 3��°���� 300���� ����� �λ�˴ϴ�.
���̱ⱸ�� count�� Ÿ�� �Ǹ� ���� �ڽ��� ������ �ִ� �ݾ׿��� �󸶰� ���ڶ������ return �ϵ��� solution �Լ��� �ϼ��ϼ���.
��, �ݾ��� �������� ������ 0�� return �ϼ���.

���ѻ���
���̱ⱸ�� �̿�� price : 1 �� price �� 2,500, price�� �ڿ���
ó�� ������ �ִ� �ݾ� money : 1 �� money �� 1,000,000,000, money�� �ڿ���
���̱ⱸ�� �̿� Ƚ�� count : 1 �� count �� 2,500, count�� �ڿ���
����� ��
price	money	count	result
3	20	4	10
����� �� ����
����� �� #1
�̿�ݾ��� 3�� ���̱ⱸ�� 4�� Ÿ�� ���� ���� ���� ���� �ݾ��� 20�̶��, �� �ʿ��� ���̱ⱸ�� �̿� �ݾ��� 30 (= 3+6+9+12) �� �Ǿ� 10��ŭ �����ϹǷ� 10�� return �մϴ�.

���� ����
�̼� ���� Java, JavaScript, Python3, C++ �� �ش� �˴ϴ�.
���� �ڵ带 ������ ����� �����̶�� �ڵ带 ���� ���� ������ �в� ��ǰ�� �帳�ϴ�.
���ƿ� ���� ������ ��� �ڵ带 ���� ���� ������ �в� ��ǰ�� �帳�ϴ�.

*/