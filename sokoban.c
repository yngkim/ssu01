#include<stdio.h>
#include<stdlib.h>
#include<termio.h>


	/*
	 *  Sokoban / 19.05.30
	 *
	 *	Who made? Mj Cho, Dn Seo, Gw Lee, Yg Kim.
	 *
	 *	@:Player,  #:Wall,  $:Gold,  O:Safe,  .:Blank
	 *
	*/


int x=0, y=0, isOnGame = 0;
int allMap[5][31][31] = {0};
int curMap[31][31] = {0};

int getch(void);							// 엔터없이 입력
int getMap(void);							// 맵불러오기
void setMap(int lvl, char n[11]);			// 맵 출력
int onGame(int lvl, char name[11]);			// 게임 

int main(void){

	char player_name[11] = {0};
	int level = 1;

	system("clear");

	printf("Loading...\n");
	if(getMap() == 1)			// 맵 불러올시 에러가 있으면
		goto end;

	printf("Start...\n\n");
	
	// Get a name
	printf("input name : ");
	scanf("%10s", player_name);
	
//	do{
		onGame(level, player_name);	
//	}while(level < 6);

	end :

	return 0;
}


int getch(void){
	int ch;

	struct termios buf;
	struct termios save;

	tcgetattr(0, &save);
	buf = save;
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;

	tcsetattr(0, TCSAFLUSH, &save);

	return ch;
}

void getKey(void){
	int key;

	key = getch();

	switch(key){
		case 'h' :
		case 'j' :
		case 'k' :
		case 'l' :
		case 'u' :
		case 'r' :
		case 'n' :
		case 'e' :
		case 's' :
		case 'f' :
		case 'd' :
		case 't' :
		default : break;
	}

	return;
}


int getMap(void){
	
	int c, lvl = 0, i = 0, j = 0, cmp = 0;

	FILE *ifp;
	
	// Load maps
    if ((ifp = fopen("map","r")) == NULL){
		printf("Error : Cannot open the map file!\n");
		system("cat >> eLog <<EOF\nError : Cannot open the map file!\nEOF");
		fclose(ifp);
		return 1;
	}
	else{
		while((c = getc(ifp)) != EOF){				// '1' = 49, '\n' = 10
			switch(c){
				case '\n' :
					if(j != 0){                     // 스테이지가 바뀌지 않았을 때 
						allMap[lvl][i++][j] = c;
						j = 0;
					}
			 		break;
				case 'e' :
					break;
				case '2' :
				case '3' :
				case '4' :
				case '5' :
					lvl++; i=0; j=0;
					if(cmp != 0){                   // 금과 금고개수 확인
						printf("Error : [Stage-%d] The number of $ and O is different!\n", lvl+1);
						system("cat >> eLog <<EOF\nError : The number of $ and O is different!\nEOF");
						fclose(ifp);
						return 1;
					}
					break;
				case '$' :					// $,O,@,#,.
				case 'O' :
				case '@' :
				case '#' :
				case '.' :
					if(c == '$')
						cmp++;
					else if(c == 'O')
						cmp--;
					allMap[lvl][i][j++] = c;
					break;
			}
		}
	}
	fclose(ifp);

	printf("\nDone\n");
 		
	return 0;
}


void setMap(int lvl, char n[11]){
	
	int i,j;
	
	system("clear");

	printf("Hello %s\n\nStage %d\n\n\n", n, lvl);	

	for(i = 0; i < 31; i++){
		for(j = 0; j < 31; j++){
			switch(curMap[i][j]){
				case '@' : putchar('@'); x=j; y=i; break;			// 플레이어 위치
				case '#' : putchar('#'); break;
				case '$' : putchar('$'); break;
				case 'O' : putchar('O'); break;
				case '.' : putchar(' '); break;
				case '\n' : putchar('\n');i++; j = -1; break;
				default : break;
			}
			
		}
	}
	
	printf("\n\n\n(Command) ");
	return;
}


int onGame(int lvl, char name[11]){
	
	int steps = 0;

	isOnGame = 1;	

	for(int i = 0; i < 31; i++){
		for(int j = 0; j < 31; j++){
			curMap[i][j]=allMap[lvl-1][i][j];
		}
	}

	do{
		setMap(lvl, name);
		printf("%d\n",steps++);
		getKey();
	}while(isOnGame == 1);

	return steps;
}















