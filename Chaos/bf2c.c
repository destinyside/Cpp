#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * brainf**k to c
 *
 */
int main(int argc, char* argv[]){
    char* words = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+.<.";
    char* code = malloc(sizeof(char) * 5000);
    if(argc >= 1){
	char* file_name = argv[1];
	int len = 0,p = 0;
	FILE* fp;
	if(!(fp=fopen(file_name,"r")))
	{
	    printf("file error\n");
	    return 0;
	}
	while((code[p++]=fgetc(fp))!=EOF);{
	    len=strlen(code)-1;
	}
	words = code;
    } else {
	printf("usage: bf2c file\n");
	return 0;
    }
    printf("#include<stdio.h>\n");
    printf("#include<stdlib.h>\n");
    printf("int main(){\n");
    printf("char* ptr = malloc(sizeof(char) * 1000);\n");
    for(char* p=words;p!=NULL && *p!='\0'; *p++){

	switch(*p){
	    case '>':{
			 printf("++ptr;\n");
			 break;	 
		     }
	    case '<':{
			 printf("--ptr;\n");
			 break;	 
		     }
	    case '+':{
			 printf("++*ptr;\n");
			 break;	 
		     }
	    case '-':{
			 printf("--*ptr;\n");
			 break;	 
		     }
	    case '.':{
			 printf("putchar(*ptr);\n");
			 break;	 
		     }
	    case ',':{
			 printf("*ptr=getchar();\n");
			 break;	 
		     }
	    case '[':{
			 printf("while(*ptr) {\n");
			 break;	 
		     }
	    case ']':{
			 printf("}\n");
			 break;	 
		     }
	    default:{
			break;
		    }


	}
    }
    printf("}\n");

}
