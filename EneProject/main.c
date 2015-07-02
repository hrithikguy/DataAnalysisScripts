#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	FILE *part1;
	FILE *Ene;

	part1 = fopen("part1", "r");
	Ene = fopen("Ene.txt", "r");

	char filename[100];
	double value;

	char **part1files;
	part1files = malloc(2000 * sizeof(char*));
	int i;
	for (i = 0; i < 2000; ++i) {
		part1files[i] = malloc(100 * sizeof(char));
	}

	char **Enefiles;
        Enefiles = malloc(2000 * sizeof(char*));
        for (i = 0; i < 2000; ++i) {
                Enefiles[i] = malloc(100 * sizeof(char));
        }

	double  *Enevalues;
	Enevalues = malloc(2000 * sizeof(double));

	double *part1values;
	part1values = malloc(2000 * sizeof(double));



	int counter = 0;
	while (fscanf(part1, "%s %lf", &filename, &value) == 2) {
		//part1files[counter] = filename;
		strcpy(part1files[counter], filename);
		part1values[counter] = value;
		++counter;
	}
/*	
	for (i = 0; i < 5; ++i) {
                printf("%s\n", part1files[i]);
                printf("%f \n", part1values[i]);
                //printf("now Ene\n");
        //      printf("%s %f\n", Enefiles[i], Enevalues[i]);
                      }	
*/

	double value2;

	int counter2 = 0;
	while (fscanf(Ene, "%s %lf", &filename, &value2) == 2) {
		strcpy(Enefiles[counter2], filename);
		Enevalues[counter2] = value2;
		++counter2;
	}
	

/*
	counter = 0;
	while (!feof(Ene)) {
		if (fscanf(Ene, "%s %f", &filename, &value) != 2) {
			break;
		}
		strcpy(Enefiles[counter], filename);
		Enevalues[counter] = value;
		++counter;
	}

*/
	//fscanf(part1, "%s %f", &filename, &value);
	//fscanf(part1, "%f", &value);
	//fscanf(Ene, "%f", &value);
/*
	for (i = 0; i < 5; ++i) {
		printf("%s\n", Enefiles[i]);
		printf("%lf \n", Enevalues[i]);
		printf("now Ene\n");
	//	printf("%s %f\n", Enefiles[i], Enevalues[i]);
	}
*/	
	int j;
	for (i = 0; i < 1717; ++i) {
			if(Enevalues[i] == 0) {
			continue;
			}
		for (j = 0; j < 1559; ++j) {
			if (strcmp(Enefiles[i], part1files[j]) == 0) {
				printf("%s native %lf %lf %lf\n", Enefiles[i], part1values[j], Enevalues[i], (part1values[j] - 0.5 - Enevalues[i])*27.21);
				break;
			}
		}
		if (j == 1559) {
			printf("%s native NA %lf NA\n", Enefiles[i], Enevalues[i]);
		}
	}

}
