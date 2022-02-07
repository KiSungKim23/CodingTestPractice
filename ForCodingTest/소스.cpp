#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include<algorithm>

using namespace std; 

string solution(string s, int n) {
    int iTemp = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && 'z' >= s[i]) {
            iTemp = s[i] + n;
            if (iTemp > 'z')
                s[i] = iTemp - 'z' + 'a' - 1;
            else
                s[i] = iTemp;
        }
        else if ('A' <= s[i] && 'Z' >= s[i]) {
                iTemp = s[i] + n;
                if (iTemp > 'Z')
                    s[i] = iTemp - 'Z' + 'A' - 1;
                else
                    s[i] = iTemp;
            }
    }
    return s;
}


void main() {
    for (int i = 0; i <= 25; i++) {
        cout << i << " : " << solution("z", i) << endl;
    }


    cout << 6 << " : " << solution("z", 6) << endl;
}


/*
* 어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 합니다.
예를 들어 "AB"는 1만큼 밀면 "BC"가 되고, 3만큼 밀면 "DE"가 됩니다. "z"는 1만큼 밀면 "a"가 됩니다. 문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수, solution을 완성해 보세요.

제한 조건
공백은 아무리 밀어도 공백입니다.
s는 알파벳 소문자, 대문자, 공백으로만 이루어져 있습니다.
s의 길이는 8000이하입니다.
n은 1 이상, 25이하인 자연수입니다.
입출력 예
s	n	result
"AB"	1	"BC"
"z"	1	"a"
"a B z"	4	"e F d"





*/
