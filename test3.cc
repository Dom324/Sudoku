#include <stdio.h>
#include <stdlib.h>
#include <math.h>


	int line[10];
	int sudoku[10][10];
	int sudoku_poss[10][10][10];
	int hura = 0;


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

int possible_values(){
	
	for(int ii = 1; ii < 10; ii++){
		for(int jj = 1; jj < 10; jj++){
			
			if(sudoku[ii][jj] == 0){
				
				int pp = (ii - 1) / 3;
				int cc = (jj - 1) / 3;
				
				for(int tt = 1; tt < 4; tt++){						//ctverec
		
		
					for(int rr = 1; rr < 4; rr++){

						int value = sudoku[tt + pp * 3][rr + cc * 3];
						
						if(value != 0){
							sudoku_poss[ii][jj][value] = 0;
						}
						}
				}
				
				for(int tt = 1; tt < 10; tt++){						//sloupce
					
					int value = sudoku[tt][jj];

					if(value != 0){
						sudoku_poss[ii][jj][value] = 0;
					}
				}
				
				for(int rr = 1; rr < 10; rr++){						//radky
					
					int value = sudoku[ii][rr];
					
					if(value != 0){
						sudoku_poss[ii][jj][value] = 0;
					}
				}
				
			}
		}
	}
}

int only_option(){
	
	for(int ii = 1; ii < 10; ii++){
		for(int jj = 1; jj < 10; jj++){
			
			int celkem = 0;
			
			for(int dd = 1; dd < 10; dd++){
				
				int radek;
				int sloupec;
				int result;
				int value = sudoku_poss[ii][jj][dd];

				celkem = celkem + value;
				
				if(value == 1){
					radek = ii;
					sloupec = jj;
					result = dd;
				}

				if(celkem > 1){dd = 10;}
				if(celkem == 1 && dd == 9){
					sudoku[radek][sloupec] = result;
				}
			}
		}
	}
}
	
int only_possibility(){

	for(int dd = 1; dd < 10; dd++){
		for(int ii = 1; ii < 10; ii++){								//jedina moznost v radku
			
			int celkem;
			int rr;
			
			for(int jj = 1; jj < 10; jj++){
			
				if(sudoku[ii][jj] == dd){ii = 10; jj = 10;}
				
				if(sudoku_poss[ii][jj][dd] == 1){
					celkem++;
					rr = jj;
					}
					
				if(celkem > 1){jj == 10;}
				if(celkem == 1 && jj == 9){
					hura++;
					sudoku[ii][rr] = dd;
				}
			}
		}
		
		for(int jj = 1; jj < 10; jj++){								//jedina moznost v sloupci
			
			int celkem;
			int tt;
			
			for(int ii = 1; ii < 10; ii++){
				
				if(sudoku[ii][jj] == dd){ii = 10; jj = 10;}
				
				if(sudoku_poss[ii][jj][dd] == 1){
					celkem++;
					tt = ii;
					}
				
				if(celkem > 1){ii == 10;}
				if(celkem == 1 && ii == 9){
					hura++;
					sudoku[tt][jj] = dd;
				}
			}
		}
		
		for(int pp = 0; pp < 3; pp++){								//jedina moznost v ctverci
			for(int cc = 0; cc < 3; cc++){
			
				int celkem = 0;
				int radek;
				int sloupec;
				
				for(int tt = 1; tt < 4; tt++){						//ctverec
		
					for(int rr = 1; rr < 4; rr++){
						
						int value = sudoku[tt + pp * 3][rr + cc * 3];
						
						if(value == dd){tt = 4; rr = 4;}
						if(value == 0 && sudoku_poss[tt + pp * 3][rr + cc * 3][dd] == 1){
							celkem++;
							radek = tt + pp * 3;
							sloupec = rr + cc *3;
						}
						if(celkem > 1){tt = 4; rr = 4;}
						
						if(celkem == 1 && tt == 3 && rr == 3){
							sudoku[radek][sloupec] = dd;
						}
					}
				}
			}
		}
	}
}
	
int main(){
	
	for(int ii = 1; ii < 10; ii++){			//nacteni cisel do gridu
		//printf("Zadej %d radek \n", ii);
		//scanf("%d", &line[ii]);
		
			line[1] =  48000906;
			line[2] =    406000;
			line[3] =  56081300;
			line[4] = 800037000;
			line[5] =  97000150;
			line[6] =    210008;
			line[7] =   3160820;
			line[8] =    803000;
			line[9] = 501000600;
		
		
		int gg = 8;
	
	    for(int jj = 1; jj < 10; jj++){

				int k;
				k = line[ii] / ipow(10, gg);
				sudoku[ii][jj] = k;
				line[ii] = (line[ii]) % (ipow(10, gg));
				gg--;

			}
	}
	
	for(int ii = 0; ii < 10; ii++){					//init values
		for(int jj = 0; jj < 10; jj++){
			for(int dd = 0; dd < 10; dd++){
				sudoku_poss[ii][jj][dd] = 1;
			}
		}
	}
	
	
	printf("\nUvodni hodnoty: \n");
	print_grid();
	
	
	for(int i = 0; i < 12; i++){
		
		possible_values();
		only_option();
		printf("\nPo only option %d \n", i+1);
		print_grid();
		
		only_possibility();
		printf("\nPo only possibility %d \n", i+1);
		print_grid();
		
		printf("\nhura %d \n", hura);
	}
}