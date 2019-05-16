#include<stdio.h>

void set_map(int lvl, int m[][31], char n[11]){
	int i,j;
	
	for(i=0; i<30; i++)
		printf("\n");
	for(i=0; m[i][0] != lvl + 48; i++);
	j = 0;
	do{
		switch(m[i][j]){
			case '@' : putchar('@'); break;
			case '#' : putchar('#'); break;
			case '$' : putchar('$'); break;
			case 'O' : putchar('O'); break;
			case '.' : putchar(' '); break;
			case '\n' : putchar('\n');i++; j = -1; break;
			/*case '#' : 
			case '$' : 
			case 'O' : 
			case '.' : break;
			case '\n' : i++; j = -1; break;
			*/default : break;
		}
		j++;
		//printf("[%d][%d]%c\n", i, j,m[i][j]);
	}while((m[i][j] < '1' || m[i][j] > '5') && m[i][j] != 'e');
	
	printf("(Command) ");
	return;
}

int main(void){

	/*
	 *  Sokoban
	 *	@:Sokoban(Player), #:Wall, $:Gold, O:Safe, .:Blank
	*/

	char player_name[11] = {0};
	int c, i = 0, j = 0, cmp = 0, level = 1;
	int map[155][31] = {0};
	FILE *ifp;
	
	printf("Start...\n");
	// Load maps
    if ((ifp = fopen("map","r")) == NULL){
		printf("Error : Cannot open the map file!\n");
		goto end;
	}
	else{
		while((c = getc(ifp)) != EOF){				// '1' = 49, '\n' = 10
			if(c == '\n'){
				map[i++][j] = c;
				j = 0;
			}
			else if(c == 'e'){
				map[i][j] = c;
				break;
			}
			else{                               // Check maps
				if(c == '$')
					cmp++;
				else if(c == 'O')
					cmp--;
				else if(c >= '1' && c<= '5')
					if(cmp != 0){
						printf("Error : The number of $ and O is differnt!\n");
						goto end;
					}
				map[i][j++] = c;
			}
		}
	}
	
	// Get a name
	printf("input name : ");
	scanf("%10s", player_name);
	printf("Hello %s\n", player_name);
	
	set_map(level, map, player_name);


	do{
		
		
	}while(c != 'e');

	end :

	return 0;
}
