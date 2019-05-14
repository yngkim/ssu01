#include<stdio.h>

int main(void){

	/*
	 *  Sokoban
	 *	@:Sokoban(Player), #:Wall, $:Gold, O:Safe, .:Blank
	*/


	int c;
	int i = 0, j = 0;
	int map[155][31] = {0};
	FILE *ifp;
	
	// Load a map
    if ((ifp = fopen("map","r")) == NULL)
		printf("Error : Cannot open the file.");
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
			else
				map[i][j++] = c;
		}
	}

	for(i = 0; i<30 ;i++)
		for(j = 0; j<30 ; j++){
			switch(map[i][j]){
				case '@' : putchar('@'); break;
				case '#' : putchar('#'); break;
				case '$' : putchar('$'); break;
				case 'O' : putchar('O'); break;
				case '.' : putchar(' '); break;
				case '\n' : putchar('\n');i++; j = -1; break;
				default : break;
			}
		}
		
	return 0;
}
