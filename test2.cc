int print_possibilities(){
	
	
	for(int i = 1; i < 10; i++){
			
		if(i == 4 || i == 7){
			printf("\n");
		}
		
	for(int j = 1; j < 10; j++) {
		
		if(sudoku[i][j] != 0){printf("xxx");}else{
		for(int dd = 1; dd < 4; dd++){
			if(sudoku_poss[i][j][dd] == 1){
				printf("%d", dd);
			}
			else{
				printf("x");
			}
		}
		}
		printf(" ");
		
		if(j == 3 || j == 6){
			printf("  ");
		}
	}
	printf("\n");
	
	for(int j = 1; j < 10; j++) {
		
		if(sudoku[i][j] != 0){printf("xxx");}else{
		for(int dd = 4; dd < 7; dd++){
			if(sudoku_poss[i][j][dd] == 1){
				printf("%d", dd);
			}
			else{
				printf("x");
			}
		}
		}
		printf(" ");
		
		if(j == 3 || j == 6){
			printf("  ");
		}
	}
	printf("\n");
	
	for(int j = 1; j < 10; j++) {
		
		if(sudoku[i][j] != 0){printf("xxx");}else{
		for(int dd = 7; dd < 10; dd++){
			if(sudoku_poss[i][j][dd] == 1){
				printf("%d", dd);
			}
			else{
				printf("x");
			}
		}
		}
		printf(" ");
		
		if(j == 3 || j == 6){
			printf("  ");
		}
	}
	printf("\n");
	printf("\n");
	
	
	}

}