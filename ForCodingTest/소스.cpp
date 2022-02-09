#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include<algorithm>


using namespace std; 

struct element {
    int col;
    int row;
};

void printpictur(vector<vector<int>>* picture) {
    for (int i = 0; i < picture->size(); i++) {
        for (int j = 0; j < (*picture)[i].size(); j++) {
            cout << " " << (*picture)[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void AddArea(vector<vector<int>>* picture, map<int, vector<element>*>* parea, int type ,int key ,element node, int colMax, int rowMax) {
    if (node.col >= colMax || node.row >= rowMax || node.col < 0 || node.row < 0) return;

    if ((*picture)[node.col][node.row] != type) {
        return;
    }

    element nodeTemp1{ node.col , node.row + 1 };
    element nodeTemp2{ node.col + 1,node.row };
    element nodeTemp3{ node.col - 1 , node.row };
    element nodeTemp4{ node.col ,node.row  - 1};

    AddArea(picture, parea, type, key, nodeTemp1, colMax, rowMax);
    AddArea(picture, parea, type, key, nodeTemp2, colMax, rowMax);
    if ((*picture)[node.col][node.row] == type) {
        (*parea)[key]->push_back(node);
        (*picture)[node.col][node.row] = 0;
    }
    AddArea(picture, parea, type, key, nodeTemp3, colMax, rowMax);
    AddArea(picture, parea, type, key, nodeTemp4, colMax, rowMax);


}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    element node;

    map<int, vector<element>*> area;
    vector<element>* pvecTemp = nullptr;

    int key = 0;


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0) {
                pvecTemp = new vector<element>;
                area.emplace(pair<int, vector<element>*>(key, pvecTemp));
                node.col = i;
                node.row = j;
                AddArea(&picture, &area, picture[i][j], key, node, m, n); 
                printpictur(&picture);
                key++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = area.size();
    answer[1] = 0;
    for (auto iter = area.begin(); iter != area.end(); iter++) {
        if (answer[1] < iter->second->size()) {
            answer[1] = iter->second->size();
        }
        delete iter->second;
    }
    return answer;
}
 
int main(void) {
    vector<vector<int>> picture = { 
        {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0} ,
        {0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0} ,
        {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0} ,
        {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0} ,
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0} ,
        {0,1,1,1,1,2,1,1,1,1,2,1,1,1,1,0} ,
        {0,1,1,1,2,1,2,1,1,2,1,2,1,1,1,0} ,
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0} ,
        {0,1,3,3,3,1,1,1,1,1,1,3,3,3,1,0} ,
        {0,1,1,1,1,1,2,1,1,2,1,1,1,1,1,0} ,
        {0,0,1,1,1,1,1,2,2,1,1,1,1,1,0,0} ,
        {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0} ,
        {0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0}
    };
    vector<int> answer = solution(13,16,picture);

    cout << answer[0] << endl;
    cout << answer[1] << endl;
    return 0;
}


/*
카카오 프렌즈 컬러링북
출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다.
여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 그림의 난이도를 영역의 수로 정의하였다.
(영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)

그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.

alt text

위의 그림은 총 12개 영역으로 이루어져 있으며, 가장 넓은 영역은 어피치의 얼굴면으로 넓이는 120이다.

입력 형식
입력은 그림의 크기를 나타내는 m과 n, 그리고 그림을 나타내는 m × n 크기의 2차원 배열 picture로 주어진다. 제한조건은 아래와 같다.

1 <= m, n <= 100
picture의 원소는 0 이상 2^31 - 1 이하의 임의의 값이다.
picture의 원소 중 값이 0인 경우는 색칠하지 않는 영역을 뜻한다.
출력 형식
리턴 타입은 원소가 두 개인 정수 배열이다. 그림에 몇 개의 영역이 있는지와 가장 큰 영역은 몇 칸으로 이루어져 있는지를 리턴한다.

예제 입출력
m	n	picture	answer
6	4	
[
[1, 1, 1, 0], 
[1, 2, 2, 1], 
[1, 0, 0, 1], 
[0, 0, 0, 1], 
[0, 0, 0, 3], 
[0, 0, 0, 3]]	[4, 5]
예제에 대한 설명
예제로 주어진 그림은 총 4개의 영역으로 구성되어 있으며, 왼쪽 위의 영역과 오른쪽의 영역은 모두 1로 구성되어 있지만 상하좌우로 이어져있지 않으므로 다른 영역이다. 
가장 넓은 영역은 왼쪽 위 1이 차지하는 영역으로 총 5칸이다.








*/
