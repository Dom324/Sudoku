#include <stdio.h>
#include <stdlib.h>
#include <math.h>


	int line[10];
	int sudoku[10][10];
	int sudoku_poss[10][10][10] = {1};
	int hura = 0;
	int hura2 = 0;
	int hura3 = 0;
	int hura4 = 0;
	int hura5 = 0;


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

int clear_pos(int ii, int jj){
	
	for(int dd = 1; dd < 10; dd++){
		
		sudoku_poss[ii][jj][dd] = 0;
		
	}
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

int print_possibilities(){
	
	
	for(int i = 1; i < 10; i++){
			
		if(i == 4 || i == 7){
			printf("\n");
		}
		
	for(int j = 1; j < 10; j++) {
		
		if(sudoku[i][j] != 0){printf("x x x ");}else{
		for(int dd = 1; dd < 4; dd++){
			if(sudoku_poss[i][j][dd] == 1){
				printf("%d ", dd);
			}
			else{
				printf("x ");
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
		
		if(sudoku[i][j] != 0){printf("x x x ");}else{
		for(int dd = 4; dd < 7; dd++){
			if(sudoku_poss[i][j][dd] == 1){
				printf("%d ", dd);
			}
			else{
				printf("x ");
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
		
		if(sudoku[i][j] != 0){printf("x x x ");}else{
		for(int dd = 7; dd < 10; dd++){
			if(sudoku_poss[i][j][dd] == 1){
				printf("%d ", dd);
			}
			else{
				printf("x ");
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

int same_line_column(){
	
	for(int dd = 1; dd < 10; dd++){
		for(int ii = 1; ii < 10; ii++){										//jedine moznosti v radku jsou v jednom ctverci
			
			int pp = (ii - 1) / 3;
			int c0 = 0;
			int c1 = 0;
			int c2 = 0;

			
			for(int jj = 1; jj < 10; jj++){
				
				int cc = (jj - 1) / 3;

				
				if((c0 + c1 + c2) > 4){break;}
				if(sudoku[ii][jj] == dd){break;}
				if(sudoku[ii][jj] == 0 && sudoku_poss[ii][jj][dd] == 1){
					
					switch(cc){
						case 0: c0++; break;
						case 1: c1++; break;
						case 2: c2++; break;
					}
				}
				if(jj == 9){
					for(int tt = 1; tt < 4; tt++){
						for(int rr = 1; rr < 4; rr++){
							
							int radek = tt + pp * 3;
							if(radek != ii){
					
								if(c0 != 0 && c1 == 0 && c2 == 0 && sudoku_poss[radek][rr][dd] == 1){
									sudoku_poss[radek][rr][dd] = 0; hura2++;
								}
								
								if(c0 == 0 && c1 != 0 && c2 == 0 && sudoku_poss[radek][rr + 3][dd] == 1){
									sudoku_poss[radek][rr + 3][dd] = 0; hura2++;
								}
								
								if(c0 == 0 && c1 == 0 && c2 != 0 && sudoku_poss[radek][rr + 6][dd] == 1){
									sudoku_poss[radek][rr + 6][dd] = 0; hura2++;
								}
							}
						}
					}
				}
			}
		}
	
	
		for(int jj = 1; jj < 10; jj++){										//jedine moznosti ve sloupci jsou v jednom ctverci
			
			int cc = (jj - 1) / 3;
			int p0 = 0;
			int p1 = 0;
			int p2 = 0;

			
			for(int ii = 1; ii < 10; ii++){
				
				int pp = (ii - 1) / 3;
				
				if((p0 + p1 + p2) > 4){break;}
				if(sudoku[ii][jj] == dd){break;}
				if(sudoku[ii][jj] == 0 && sudoku_poss[ii][jj][dd] == 1){
					
					switch(pp){
						case 0: p0++; break;
						case 1: p1++; break;
						case 2: p2++; break;
					}
				}
				if(ii == 9){
					for(int tt = 1; tt < 4; tt++){
						for(int rr = 1; rr < 4; rr++){
					
							int sloupec = rr + cc * 3;
							if(sloupec != jj){
					
								if(p0 != 0 && p1 == 0 && p2 == 0 && sudoku_poss[tt][sloupec][dd] == 1){
									sudoku_poss[tt][sloupec][dd] = 0; hura2++;
								}
								
								if(p0 == 0 && p1 != 0 && p2 == 0 && sudoku_poss[tt + 3][sloupec][dd] == 1){
									sudoku_poss[tt + 3][sloupec][dd] = 0; hura2++;
								}
								
								if(p0 == 0 && p1 == 0 && p2 != 0 && sudoku_poss[tt + 6][sloupec][dd] == 1){
									sudoku_poss[tt + 6][sloupec][dd] = 0; hura2++;
								}
							}
						}
					}
				}
			}
		}
	
	
	
	
	}
}

int same_square(){
	
	for(int dd = 1; dd < 10; dd++){
		
		for(int cc = 1; cc < 4; cc++){
			for(int pp = 1; pp < 4; pp++){
				
				int r0 = 0;
				int r1 = 0;
				int r2 = 0;
				int r = 0;
				
				for(int tt = 1; tt < 4; tt++){
					for(int rr = 1; rr < 4; rr++){
						
						int radek = tt + 3 * (pp - 1);
						int sloupec = rr + 3 * (cc - 1);
						
						if(sudoku[radek][sloupec] == dd){break;}
						if(sudoku[radek][sloupec] == 0 && sudoku_poss[radek][sloupec][dd] == 1){
							switch(rr){
								case 1: r0++; break;
								case 2: r1++; break;
								case 3: r2++; break;
							}
						}
						if(rr == 3 && tt == 3){
							if(r0 != 0 && r1 == 0 && r2 == 0){r = 1;}
							if(r0 == 0 && r1 != 0 && r2 == 0){r = 2;}
							if(r0 == 0 && r1 == 0 && r2 != 0){r = 3;}
							
							if(r != 0){
								if(pp == 1 || pp == 2){ hura3++;
									sudoku_poss[9][r + 3 * (cc - 1)][dd] = 0;
									sudoku_poss[8][r + 3 * (cc - 1)][dd] = 0;
									sudoku_poss[7][r + 3 * (cc - 1)][dd] = 0;
								}
								if(pp == 1 || pp == 3){ hura3++;
									sudoku_poss[6][r + 3 * (cc - 1)][dd] = 0;
									sudoku_poss[5][r + 3 * (cc - 1)][dd] = 0;
									sudoku_poss[4][r + 3 * (cc - 1)][dd] = 0;
								}
								if(pp == 2 || pp == 3){ hura3++;
									sudoku_poss[3][r + 3 * (cc - 1)][dd] = 0;
									sudoku_poss[2][r + 3 * (cc - 1)][dd] = 0;
									sudoku_poss[1][r + 3 * (cc - 1)][dd] = 0;
								}
							}
						}
					}
				}
			}
		}
		
		
		for(int pp = 1; pp < 4; pp++){
			for(int cc = 1; cc < 4; cc++){
				
				int t0 = 0;
				int t1 = 0;
				int t2 = 0;
				int t = 0;
				
				for(int rr = 1; rr < 4; rr++){
					for(int tt = 1; tt < 4; tt++){
						
						int radek = tt + 3 * (pp - 1);
						int sloupec = rr + 3 * (cc - 1);
						
						if(sudoku[radek][sloupec] == dd){break;}
						if(sudoku[radek][sloupec] == 0 && sudoku_poss[radek][sloupec][dd] == 1){
							switch(tt){
								case 1: t0++; break;
								case 2: t1++; break;
								case 3: t2++; break;
							}
						}
						if(rr == 3 && tt == 3){
							if(t0 != 0 && t1 == 0 && t2 == 0){t = 1;}
							if(t0 == 0 && t1 != 0 && t2 == 0){t = 2;}
							if(t0 == 0 && t1 == 0 && t2 != 0){t = 3;}
							
							if(t != 0){
								if(cc == 1 || cc == 2){ hura3++;
									sudoku_poss[t + 3 * (pp - 1)][9][dd] = 0;
									sudoku_poss[t + 3 * (pp - 1)][8][dd] = 0;
									sudoku_poss[t + 3 * (pp - 1)][7][dd] = 0;
								}
								if(cc == 1 || cc == 3){ hura3++;
									sudoku_poss[t + 3 * (pp - 1)][6][dd] = 0;
									sudoku_poss[t + 3 * (pp - 1)][5][dd] = 0;
									sudoku_poss[t + 3 * (pp - 1)][4][dd] = 0;
								}
								if(cc == 2 || cc == 3){ hura3++;
									sudoku_poss[t + 3 * (pp - 1)][3][dd] = 0;
									sudoku_poss[t + 3 * (pp - 1)][2][dd] = 0;
									sudoku_poss[t + 3 * (pp - 1)][1][dd] = 0;
								}
							}
						}
					}
				}
			}
		}
	}
}

int pair(){	

	for(int jj = 1; jj < 10; jj++){									//par ve sloupci
	
		int pocet[10] = {0};
		int souradnice[10][10] = {0};
	
		for(int ii = 1; ii < 10; ii++){

			for(int dd = 1; dd < 10; dd++){

				if(sudoku[ii][jj] !=0){break;}
				if(sudoku_poss[ii][jj][dd] == 1){
					
					pocet[dd]++;
					souradnice[dd][pocet[dd]] = ii;
					
				}
			}
		}
		
		for(int gg = 1; gg < 10; gg++){
			
			if(pocet[gg] != 2){continue;}
			
			for(int dd = gg + 1; dd < 10; dd++){
				
				if(pocet[dd] != 2){continue;}
				if(dd == gg){continue;}
				
				if(souradnice[dd][1] == souradnice[gg][1] && souradnice[dd][2] == souradnice[gg][2]){
					
					hura5++;
					printf("\npocet[dd] %d pocet[gg] %d \n dd %d gg %d \n souradnice[dd][1] %d souradnice[gg][1] %d \n souradnice[dd][2] %d souradnice[gg][2] %d \n \n \n",
					pocet[dd], pocet[gg], dd, gg, souradnice[dd][1], souradnice[gg][1], souradnice[dd][2], souradnice[gg][2]);
					
					
					clear_pos(souradnice[dd][1], jj);
					clear_pos(souradnice[dd][2], jj);
					
					sudoku_poss[souradnice[dd][1]][jj][dd] = 1;
					sudoku_poss[souradnice[dd][1]][jj][gg] = 1;
					sudoku_poss[souradnice[dd][2]][jj][dd] = 1;
					sudoku_poss[souradnice[dd][2]][jj][gg] = 1;
				}
			}
		}
	}
	
	
	for(int ii = 1; ii < 10; ii++){									//par v radku
	
		int pocet[10] = {0};
		int souradnice[10][10] = {0};
	
		for(int jj = 1; jj < 10; jj++){

			for(int dd = 1; dd < 10; dd++){

				if(sudoku[ii][jj] !=0){break;}
				if(sudoku_poss[ii][jj][dd] == 1){
					
					pocet[dd]++;
					souradnice[dd][pocet[dd]] = jj;
					
				}
			}
		}
		
		for(int gg = 1; gg < 10; gg++){
			
			if(pocet[gg] != 2){continue;}
			
			for(int dd = gg + 1; dd < 10; dd++){
				
				if(pocet[dd] != 2){continue;}
				if(dd == gg){continue;}
				
				if(souradnice[dd][1] == souradnice[gg][1] && souradnice[dd][2] == souradnice[gg][2]){
					
					hura5++;
					printf("\npocet[dd] %d pocet[gg] %d \n dd %d gg %d \n souradnice[dd][1] %d souradnice[gg][1] %d \n souradnice[dd][2] %d souradnice[gg][2] %d \n \n \n",
					pocet[dd], pocet[gg], dd, gg, souradnice[dd][1], souradnice[gg][1], souradnice[dd][2], souradnice[gg][2]);
					
					
					clear_pos(ii, souradnice[dd][1]);
					clear_pos(ii, souradnice[dd][2]);
					
					sudoku_poss[ii][souradnice[dd][1]][dd] = 1;
					sudoku_poss[ii][souradnice[dd][1]][gg] = 1;
					sudoku_poss[ii][souradnice[dd][2]][dd] = 1;
					sudoku_poss[ii][souradnice[dd][2]][gg] = 1;
				}
			}
		}
	}
	
	
	for(int cc = 1; cc < 4; cc++){											//par ve ctverci
		for(int pp = 1; pp < 4; pp++){
			
			int pocet[10] = {0};
			int souradnice[10][10];
	
			for(int tt = 1; tt < 4; tt++){
				for(int rr = 1; rr < 4; rr++){
						
					int radek = tt + 3 * (pp - 1);
					int sloupec = rr + 3 * (cc - 1);
						
					for(int dd = 1; dd < 10; dd++){
							
						if(sudoku[radek][sloupec] != 0){break;}
						if(sudoku_poss[radek][sloupec][dd] == 1){
							pocet[dd]++;
							souradnice[dd][pocet[dd]] = radek * 10 + sloupec;
						}
					}
				}
			}
			
			for(int gg = 1; gg < 10; gg++){
				
				if(pocet[gg] != 2){continue;}
			
				for(int dd = gg + 1; dd < 10; dd++){
				
					if(pocet[dd] != 2){continue;}
					if(dd == gg){continue;}
					if(souradnice[dd][1] == souradnice[gg][1] && souradnice[dd][2] == souradnice[gg][2]){
						
						hura5++;
						printf("\npocet[dd] %d pocet[gg] %d \n dd %d gg %d \n souradnice[dd][1] %d souradnice[gg][1] %d \n souradnice[dd][2] %d souradnice[gg][2] %d \n \n \n",
						pocet[dd], pocet[gg], dd, gg, souradnice[dd][1], souradnice[gg][1], souradnice[dd][2], souradnice[gg][2]);
						
						int sloupec1 = souradnice[dd][1] % 10;
						int sloupec2 = souradnice[dd][2] % 10;
						int radek1 = (souradnice[dd][1] - sloupec1) / 10;
						int radek2 = (souradnice[dd][2] - sloupec2) / 10;
			
						clear_pos(radek1, sloupec1);
						clear_pos(radek2, sloupec2);
					
						sudoku_poss[radek1][sloupec1][dd] = 1;
						sudoku_poss[radek1][sloupec1][gg] = 1;
						sudoku_poss[radek2][sloupec2][dd] = 1;
						sudoku_poss[radek2][sloupec2][gg] = 1;
					}
				}
			}
		}
	}
	
}	
	
int only_option(){

	for(int dd = 1; dd < 10; dd++){
		for(int ii = 1; ii < 10; ii++){								//jedina moznost v radku
			
			int celkem;
			int rr;
			
			for(int jj = 1; jj < 10; jj++){
			
				if(sudoku[ii][jj] == dd){break;}
				
				if(sudoku_poss[ii][jj][dd] == 1){
					celkem++;
					rr = jj;
					}
					
				if(celkem > 1){break;}
				if(celkem == 1 && jj == 9){
					hura++;
					sudoku[ii][rr] = dd;
					clear_pos(ii, rr);
				}
			}
		}
		
		for(int jj = 1; jj < 10; jj++){								//jedina moznost v sloupci
			
			int celkem;
			int tt;
			
			for(int ii = 1; ii < 10; ii++){
				
				if(sudoku[ii][jj] == dd){break;}
				
				if(sudoku_poss[ii][jj][dd] == 1){
					celkem++;
					tt = ii;
					}
				
				if(celkem > 1){break;}
				if(celkem == 1 && ii == 9){
					hura++;
					sudoku[tt][jj] = dd;
					clear_pos(tt, jj);
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
						
						if(value == dd){break;}
						if(value == 0 && sudoku_poss[tt + pp * 3][rr + cc * 3][dd] == 1){
							celkem++;
							radek = tt + pp * 3;
							sloupec = rr + cc *3;
						}
						if(celkem > 1){break;}
						
						if(celkem == 1 && tt == 3 && rr == 3){
							sudoku[radek][sloupec] = dd;
							clear_pos(radek, sloupec);
						}
					}
				}
			}
		}
	}
}
	
int only_possibility(){
	
	for(int ii = 1; ii < 10; ii++){
		
			for(int jj = 1; jj < 10; jj++){
				
				int celkem = 0;
				int dd_2 = 0;
				
				for(int dd = 1; dd < 10; dd++){
			
				if(sudoku[ii][jj] != 0){break;}
				//if(ii == 7 && jj == 7){printf("\n sudoku[7][7] %d \n", sudoku[ii][jj]);}
				if(sudoku_poss[ii][jj][dd] == 1){celkem++; dd_2 = dd;}
				//if(ii == 7 && jj == 7){printf("\n celkem %d \n", celkem);}
				if(celkem > 1){break;}
				if(dd == 9 && celkem == 1){
					sudoku[ii][jj] = dd_2;
					clear_pos(ii, jj);
				}
			}
		}
	}
}
	

int main(){
	
	for(int ii = 1; ii < 10; ii++){			//nacteni cisel do gridu
		//printf("Zadej %d radek \n", ii);
		//scanf("%d", &line[ii]);
		
			line[1] = 806000000;
			line[2] =  40890000;
			line[3] =     20804;
			line[4] = 750080000;
			line[5] = 620307019;
			line[6] =     50086;
			line[7] = 509070000;
			line[8] =     15090;
			line[9] =       307;
		
		
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
				if(sudoku[ii][jj] == 0){
					sudoku_poss[ii][jj][dd] = 1;
				}
			}
		}
	}
	
	for(int ii = 0; ii < 10; ii++){					//odstranit poss u init valuse
		for(int jj = 0; jj < 10; jj++){
			if(sudoku[ii][jj] != 0){
					clear_pos(ii, jj);
			}
		}
	}
	
	
	printf("\nUvodni hodnoty: \n");
	print_grid();
	
	
	for(int i = 0; i < 9; i++){
		
		possible_values();
		same_line_column();
		same_square();
		pair();
		
		only_option();
		printf("\nPo only option %d \n", i+1);
		print_grid();

		only_possibility();
		printf("\nPo only possibility %d \n", i+1);
		print_grid();
		
		print_possibilities();
		
		printf("\nhura %d \n hura2 %d \n hura3 %d \n hura4 %d \n hura5 %d \n", hura, hura2, hura3, hura4, hura5);
	}
}