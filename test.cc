#include <stdio.h>
#include <stdlib.h>
#include <math.h>


	int line[10];
	int sudoku[10][10];
	

int ipow(int base, int exp){				//mocnina
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
    return result;
}

int print_grid(){							//vytisknuti gridu

	for(int i = 1; i < 10; i++){
			
		if(i == 4 || i == 7){
			printf("\n");
		}
		
	for(int j = 1; j < 10; j++) {
		
		if(j == 4 || j == 7){
			printf(" ");
		}
		
		printf("%d ", sudoku[i][j]);
	}
	printf("\n");
	}
}

int full_square9(){							//doplneni chybejici hodnoty ve ctverci, nefunguje!!!

	for(int pp = 0; pp < 3; pp++){				//ktera rada ctvercu
	
	for(int cc = 0; cc < 3; cc++){				//ktery ctverec v rade
		
		int num_zero = 0;
		
	for(int ii = 1; ii < 4; ii++){
		
		
		for(int jj = 1; jj < 4; jj++){
	
			if(sudoku[ii + pp * 3][jj + cc * 3] == 0){num_zero++;}
			if(num_zero > 1){ii = 4; jj =4;}
		}
		
		if(num_zero == 1 && ii == 3){
			
			int celkem = 0;
			
			for(int ii = 1; ii < 4; ii++){
		
		
				for(int jj = 1; jj < 4; jj++){
				
					int radek;
					int sloupec;
				
					celkem = celkem + sudoku[ii + pp * 3][jj + cc * 3];
					
					
					if(sudoku[ii + pp * 3][jj + cc * 3] == 0){
						radek = ii + pp * 3;
						sloupec = jj + cc * 3;
					}
					
					if(ii==3){sudoku[radek][sloupec] = 45 - celkem;}
				}
			}
		}
	}
	}
	//printf("\n pp %d\n", pp);
	}
}
	
int full_line9(){
	for(int ii = 1; ii < 10; ii++){
		
		int celkem = 0;
		int num_zero = 0;
		int radek;
		int sloupec;
		
		for(int jj = 1; jj < 10; jj++){
			
			if(sudoku[ii][jj] == 0){
				
				num_zero++;
				radek = ii;
				sloupec = jj;
				}
			
			if(num_zero > 1){jj=10;}
			
			celkem = celkem + sudoku[ii][jj];
			
			if(num_zero == 1 && jj == 9){
				sudoku[radek][sloupec] = 45 - celkem;
			}
		}
	}
}

int full_column9(){
	for(int jj = 1; jj < 10; jj++){
		
		int celkem = 0;
		int num_zero = 0;
		int radek;
		int sloupec;
		
		for(int ii = 1; ii < 10; ii++){
			
			if(sudoku[ii][jj] == 0){
				
				num_zero++;
				radek = ii;
				sloupec = jj;
				}
			
			if(num_zero > 1){ii=10;}
			
			celkem = celkem + sudoku[ii][jj];
			
			if(num_zero == 1 && ii == 9){
				sudoku[radek][sloupec] = 45 - celkem;
			}
		}
	}
}
	
int main(){
	
	for(int ii = 1; ii < 10; ii++){			//nacteni cisel do gridu
		//printf("Zadej %d radek \n", ii);
		//scanf("%d", &line[ii]);
		
			line[1] =      4090;
			line[2] = 812973450;
			line[3] = 901200300;
			line[4] =     49157;
			line[5] =  13050920;
			line[6] = 579120346;
			line[7] =   7002603;
			line[8] =     38205;
			line[9] =  20500000;
		
		
		int gg = 8;
	
	    for(int jj = 1; jj < 10; jj++){
;
				int k;
				k = line[ii] / ipow(10, gg);
				sudoku[ii][jj] = k;
				line[ii] = (line[ii]) % (ipow(10, gg));
				gg--;

			}
	}
	
	printf("\nUvodni hodnoty: \n");
	print_grid();
	
	full_square9();
	printf("\nPo doplneni do ctvercu \n");
	print_grid();
	
	full_line9();
	printf("\nPo doplneni do radku \n");
	print_grid();
	
	full_column9();
	printf("\nPo doplneni do sloupce \n");
	print_grid();
	
	
	
}