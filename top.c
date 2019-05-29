#include <stdio.h> //헤더파일 명시는 붙일 때 지워도 되나?
#include <stdlib.h> //일단 잘 작동하는지 확인할려면 필요한 듯?

void top(int)
{
	FILE *ranking.txt;  //텍스트 파일 그냥 만들면 되는지?

	int score, level;
	char new_name, name[5];

	int rank[5][5];

	for (int i=4;i>=0;i--){ // 이렇게 되면 모든 순위가 score가 됨.
		if (score > rank[level-1][i]) 
			rank[level-1][i] = score; // 수정 필요함

	if (score > rank[level-1][4]){ // 지우기 전에 참고함
		rank[level-1][4] = score;
		if (score > rank[level-1][3]){
			rank[level-1][3] = score;
			if (score > rank[level-1][2]){
				rank[level-1][2] = score;
				if (score > rank[level-1
