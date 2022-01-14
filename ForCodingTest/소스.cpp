#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	char result[20];
	for (int i = 0; i < 20; i++) {
		result[i] = 0;
	}
	for (int i = 0; i < participant.size(); i++) {
		for (int j = 0; j < participant[i].size(); j++) {
			result[j] ^= participant[i][j];
		}
	}
	for (int i = 0; i < completion.size(); i++) {
		for (int j = 0; j < completion[i].size(); j++) {
			result[j] ^= completion[i][j];
		}
	}

	return string(result);
}

void main() {
	vector<string> participant = { "marina", "josipa", "nikola", "vinko", "filipa" };
	vector<string> completion = { "josipa", "filipa", "marina", "nikola" };

	cout << solution(participant, completion) << endl;
}


/*
������ ������ �������� �����濡 �����Ͽ����ϴ�. �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.
����� ��
participant	completion	return
["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
["mislav", "stanko", "mislav", "ana"]	["stanko", "ana", "mislav"]	"mislav"
����� �� ����
���� #1
"leo"�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.

���� #2
"vinko"�� ������ ��ܿ��� ������, ������ ��ܿ��� ���� ������ �������� ���߽��ϴ�.

���� #3
"mislav"�� ������ ��ܿ��� �� ���� ������, ������ ��ܿ��� �� ��ۿ� ���� ������ �Ѹ��� �������� ���߽��ϴ�.

�����ϰ� �غ��� �ߴٰ� �װ� �� �����ɸ��� ���Ƽ� ���ߴµ�
�˰��� �Ἥ �����ϸ� ����� �̷�....


#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++) {
		if (completion[i] != participant[i])
			return participant[i];
	}

	return participant[participant.size() - 1];
}

xor�� Ǭ Ǯ�̰� ¿������ ����;;

*/