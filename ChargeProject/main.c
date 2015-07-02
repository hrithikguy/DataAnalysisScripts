
#include <stdio.h>


int main()
{	
	FILE *ifp;
	ifp = fopen("pHvaluesintermediate", "r");
	int integer;
	int inorout = 0;
	int currentsize;
	int incounter = 1;
	int charge = 0;
	while (fscanf(ifp, "%d", &integer) == 1) {
		if (inorout == 0) {
			currentsize = integer;
			inorout = 1;
		}
		else if (inorout == 1) {
			if (incounter < 2 * currentsize) {
				if (incounter % 2 == 0) {
					charge += integer;
				}
				incounter++;
			}
			else if (incounter == 2 * currentsize) {
				charge += integer;
				printf("%d\n", charge);
				inorout = 0;
				charge = 0;
				incounter = 1;
			}
		}
	}
	fclose(ifp);
}
