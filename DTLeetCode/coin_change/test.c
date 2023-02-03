#include<stdio.h>

int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                for(int l=0; l<10; l++){
                    if(419*i+408*j+186*k+83*l==6249){
                        printf("419: %d 408: %d 186: %d 83 %d\n", i,j,k,l);
                    }
                }
            }
        }
    }
    return 0;
}