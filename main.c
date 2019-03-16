#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void clearconsole()
{
    system("@cls||clear");
}

//srand(time(NULL));
//	int zZ = (rand() % (999 - (1) + 1)) + (1);

void shuffle(int array[], int size, int count)
{
	srand(time(NULL));
	int a;
	int b;

	for(a = 0; a < count; a++)
	{
		for(b = 0; b < size; b++)
		{
			int randomz = rand() % size;
			int temp = array[b];
			array[b] = array[randomz];
			array[randomz] = temp;
		}
	}
}

bool help(int value, int array[], int size)
{
	int i;
	for( i = 0; i < size; i++)
	{
		if(array[i] == value)
		{
			return true;
		}
	}
	return false;
}


int main(int argc, char *argv[])
{
	int array[4];
	int arraylength  = sizeof(array) / sizeof(array[0]);
	int zahl1;
	bool richtig = false;
	int zahl2;
	int zahl3;
	int zahl4;
	int zahl5;
	int eingabe = 0;
	int eingab;
	int random;
	int charZahl = 48; // minus 48 weil char zu int 
	char deutsch[][20] = {"Buch","Apfel","Reh","Baum","Erde","Blume"};
	char english[][20] = {"book","apple","deer","tree","Earth","flower"};
	int length = sizeof(deutsch) / sizeof(deutsch[0]);
	bool wert;
	srand(time(NULL));
	
	do
	{
		zahl1 = rand() % length;
		zahl5 = zahl1;
		
	
		
		
		do
		{
			array[0] = zahl1;
			do
			{		
				zahl2 = rand() % length;	
			} while(help(zahl2,array,arraylength));
			array[1] = zahl2;
			
			do
			{		
				zahl3 = rand() % length;	
			} while(help(zahl3,array,arraylength));
			array[2] = zahl3;
			
			do
			{		
				zahl4 = rand() % length;	
			} while(help(zahl4,array,arraylength));
			array[3] = zahl4;
			
			shuffle(array, arraylength, 5);
			
			printf("\ntranslate: %s",english[zahl5]);
			printf("\n1)%s",deutsch[array[0]]);
			printf("\n2)%s",deutsch[array[1]]);
			printf("\n3)%s",deutsch[array[2]]);
			printf("\n4)%s\n",deutsch[array[3]]);
					
			
			//printf("\n%d%d%d%d%d\n",zahl1,zahl2,zahl3,zahl4,zahl5);
			
								
			eingabe  = getche();
			eingabe = eingabe - 48;
			
			clearconsole();
			
			switch(eingabe)
			{
				case 0: return 0;
				case 1: eingabe = array[0]; break;
				case 2: eingabe = array[1]; break;
				case 3:	eingabe = array[2]; break;
				case 4: eingabe = array[3]; break;
				default: printf("Error 404: eingegebene Zahl unbekannt\n");  break;
			}
			
			
			
			if(eingabe != zahl5)
			{
				printf("FALSCH");	
			} 
			
		} while(eingabe != zahl5);

		printf("RICHTIG!");	
	
	
		
	} while(1 == 1);
	
	
	return 0;
}
