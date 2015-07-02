#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *BDE;
	FILE *part2;

	part2 = fopen("part2programinput", "r");
	BDE = fopen("BDE.txt", "r");

	char filename[100];
	double value;
	int filenumber;
	int part2atomicnumber;

	char **BDEfiles;
	BDEfiles = malloc(2000 * sizeof(char*));
	int i;
	for (i = 0; i < 2000; ++i) {
		BDEfiles[i] = malloc(100 * sizeof(char));
	}

	int BDEfilenumbers[2000];
	double BDEvalues[2000];
	
	char **part2files;
	part2files = malloc(2000 * sizeof(char*));
	for (i = 0; i < 2000; ++i) {
		part2files[i] = malloc(100 * sizeof(char));
	}

	double part2values[2000];
	int part2atomicnumbers[2000];


	int counter = 0;
	while (fscanf(BDE, "%s %d %lf", &filename, &filenumber, &value) == 3) {
		strcpy(BDEfiles[counter], filename);
		BDEfilenumbers[counter] = filenumber;
		BDEvalues[counter] = value;
		++counter;
	}


	counter = 0;
	while (fscanf(part2, "%s %d %lf", &filename, &part2atomicnumber, &value) == 3) {
		strcpy(part2files[counter], filename);
		part2atomicnumbers[counter] = part2atomicnumber;
		part2values[counter] = value;
		++counter;
	}

	int j;
	for (i = 0; i < 1703; ++i) {
		if (part2values[i] == 0) {
			continue;
		}
		for (j = 0; j < 1674; ++j) {
			if (strcmp(part2files[i], BDEfiles[j]) == 0) {
				printf("%s %d %lf %d %lf %lf\n", part2files[i], part2atomicnumbers[i], part2values[i], BDEfilenumbers[j], BDEvalues[j], part2values[i] - BDEvalues[j]);
			}
		}
	}

}
