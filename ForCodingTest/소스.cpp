#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main() {
	vector<int> nums = { 1,2,7,6,4 };

	bool CountResult = true;

	int answer = 0;

	vector<int> Temp;

	for (int iF = 0; iF < nums.size() - 2; iF++) {
		for (int iS = iF + 1; iS < nums.size() - 1; iS++) {
			for (int iT = iS + 1; iT < nums.size(); iT++) {
					Temp.push_back(nums[iF] + nums[iS] + nums[iT]);
			}
		}
	}

	for (int i = 0; i < Temp.size(); i++) {
		for (int k = 2; k < Temp[i]; k++) {
			if (0 == (Temp[i] % k)) {
				CountResult = false;
				break;
			}
		}

		if (CountResult)
			answer++;
		CountResult = true;
	}


	cout << answer << endl;

}


/*
* �־��� ���� �� 3���� ���� ������ �� �Ҽ��� �Ǵ� ����� ������ ���Ϸ��� �մϴ�. 
���ڵ��� ����ִ� �迭 nums�� �Ű������� �־��� ��, nums�� �ִ� ���ڵ� �� ���� �ٸ� 3���� ��� ������ �� �Ҽ��� �Ǵ� ����� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
nums�� ����ִ� ������ ������ 3�� �̻� 50�� �����Դϴ�.
nums�� �� ���Ҵ� 1 �̻� 1,000 ������ �ڿ����̸�, �ߺ��� ���ڰ� ������� �ʽ��ϴ�.
����� ��
nums	result
[1,2,3,4]	1
[1,2,7,6,4]	4
����� �� ����
����� �� #1
[1,2,4]�� �̿��ؼ� 7�� ���� �� �ֽ��ϴ�.

����� �� #2
[1,2,4]�� �̿��ؼ� 7�� ���� �� �ֽ��ϴ�.
[1,4,6]�� �̿��ؼ� 11�� ���� �� �ֽ��ϴ�.
[2,4,7]�� �̿��ؼ� 13�� ���� �� �ֽ��ϴ�.
[4,6,7]�� �̿��ؼ� 17�� ���� �� �ֽ��ϴ�.


*/