#include <stdio.h>
#include <stdlib.h>
//In this code, it finds who the town judge is with the following constraints of, the town judge trusts nobody, everybody(except the judge) trusts
//the town judge, there is exactly one person that satisfies properties 1 and 2. there are n people labeled from 0 to n-1.

int Judge(int n, int** trust) {
	//dynamically allocates memory
    int* trustj = (int*)malloc((n + 1) * sizeof(int)); 
    int* trustx = (int*)malloc((n + 1) * sizeof(int));
    
    // initializes arrays
    for (int i = 0; i <= n; i++) {
        trustj[i] = 0;
        trustx[i] = 0;
    }
    // Count 
    for (int i = 0; i < n; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        trustj[a]++;
        trustx[b]++;
    }
    // Find the town judge
    for (int i = 1; i <= n; i++) { // starts from 1 since people are labeled from 0 to n-1
        if (trustj[i] == 0 && trustx[i] == n - 1) { // judge doesnt trust anyone and is trusted by everyone else
            free(trustj);
            free(trustx);
            return i;
        }
    }
    free(trustj); 
    free(trustx);
    return -1;
}

int main(int argc, char* argv[]) {
	//if argument number is not valid
    if (argc != 2) {
        printf("invalid arguments\n");
        return 1;
    }
	//file error handling
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n); //reads first integer as n

    int** trust = (int**)malloc(n * sizeof(int*)); //allocates mem for 2d array
    for (int i = 0; i < n; i++) { 
        trust[i] = (int*)malloc(2 * sizeof(int)); //allocates mem for 2 integers 
    }
	if (trust == NULL){ //memory handling error
		printf("memory alloc failed\n");
		fclose(file);
		return 1;
	}
	
    for (int i = 0; i < n; i++) { //iterates between 0 and trustsize-1 which is i
        fscanf(file, "%d%d", &trust[i][0], &trust[i][1]);
    }

    fclose(file);

    int judge = Judge(n, trust);
    printf("%d\n", judge);

    for (int i = 0; i < n; i++) {
        free(trust[i]);
    }
    free(trust);

    return 0;
}

