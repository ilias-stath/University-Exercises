#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
#define M 4
#define K 20

/* SUPERMARKET_DATABASE */

int main() {
	int i,j,x,y;
	float p;
	char sM[M][K];
	float pP[M][N] = {{2.5,3.8,4.6},{2.6,3.1,4.9},{2,4,5.5},{3,2.9,5.2}};
	
	/* Sets the names of the supermarkets */
	strcpy(sM[0], "Sklavenitis");
	strcpy(sM[1], "My Market");
	strcpy(sM[2], "Vasilopoulos");
	strcpy(sM[3], "Lidl");
	
	/* Asks for a price and checks how many supermarkets have products at this price */
	printf("Type a price.\n");
	scanf("%f",&p);
	for(i=0; i<M; i++){
		x=0;
		for(j=0; j<N; j++){
			if(pP[i][j] == p){
				x++;
			}
			else{
				continue;
			}
		}
		printf("The %s Supermarket has: %d product/products at that price.\n", sM[i],x);
	}
	
	/* Asks for a price and prints the supermarkets that have all of their products below the given price */
	printf("\nType a second price.\n");
	scanf("%f",&p);
	for(i=0; i<M; i++){
		x=0;
		for(j=0; j<N; j++){
			if(pP[i][j] < p){
				x++;
			}
			else{
				continue;
			}
		}
		if(x == N){
			printf("The %s Supermarket has its product prices below that price.\n", sM[i]);
		}
		else{
			y++;
		}
		if(y == N){
			printf("No Supermarket has its product prices below that price.\n");
		}
		else{
			continue;
		}
	}
	
	
	/* Asks for a product and prints the supermarket that this product is cheaper */
	printf("\nSelect a product by typing 1,2 or 3.\n");
	scanf("%d", &y);
	x=0;
	p=0;
	do{
		if(y == 1 || y == 2 || y == 3){
			for(i=0; i<M; i++){
				if(i == 0){
					p = pP[i][y-1];
					x = i;
				}
				else{
					if(pP[i][y-1] < p){
						p = pP[i][y-1];
						x = i;
					}
					else{
						continue;
					}
				}
			}
		}
		else{
			printf("Error. You must type 1,2 or 3.\n");
			scanf("%d", &y);
		}
			
	}while(y != 1 && y != 2 && y != 3);
	
	printf("The Supermarket that offers the product number %d in the lowest price is %s with the price being at %f euros.\n\n", y,sM[x],p);
	
	
	
	system("PAUSE");
	return 0;
}
