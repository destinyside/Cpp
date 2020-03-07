#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * getHint(char * secret, char * guess){
    int len = strlen(secret);
    int* mark = malloc(sizeof(int)*len);
    int* use = malloc(sizeof(int)*len);
    for(int i=0; i<len; i++){
	if(secret[i]==guess[i]){
	    mark[i]=1;
	    use[i]=1;
	} else {
	    mark[i]=0;
	}
    }
    for(int i=0; i<len; i++){
	    printf("i %d mark[i] %d\n",i,mark[i]);
	if(mark[i]!=1){
	    for(int j=0;j<len; j++){
		if(mark[i]!=2 && use[j]!=1 && secret[i]==guess[j]){
		    mark[i]=2;
		    use[j]=1;
		}
	    }
	    printf("marks: ");
	    for(int j=0; j<len; j++){
		printf("%d ",mark[j]);
	    }
	    printf("\n");
	}
    }
    int countA = 0;
    int countB = 0;
    for(int i=0; i<len; i++){
	if(mark[i]==1){
	    countA++;
	}
	if(mark[i]==2){
	    countB++;
	}
    }
    char *p = malloc(sizeof(char)*10);
    sprintf(p,"%dA%dB",countA,countB);
    return p;
}


int main(int argc, char* argv[]){
    char* secret = "1807";
    char* guess = "7810";
    if(argc > 2){
	secret = argv[1];
	guess = argv[2];
    }
    printf("%s,%s : %s\n",secret,guess,getHint(secret,guess));
    return EXIT_SUCCESS;
}
