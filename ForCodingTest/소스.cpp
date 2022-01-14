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
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.
입출력 예
participant	completion	return
["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
["mislav", "stanko", "mislav", "ana"]	["stanko", "ana", "mislav"]	"mislav"
입출력 예 설명
예제 #1
"leo"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #2
"vinko"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #3
"mislav"는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.

솔팅하고 해볼까 했다가 그건 더 오래걸릴거 같아서 안했는데
알고리즘 써서 솔팅하면 됬었네 이런....


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

xor로 푼 풀이가 쩔었던거 같다;;

*/