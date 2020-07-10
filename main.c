#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib.h"

void print_lib(struct lib* p){
    if(p){
        printf("name:%s\ttype:%s\tcategory:%s\n", p->name, p->type, p->category);
    }
}

void print_libs(){
    if(!lib_head){
        printf("no lib.\n");
    } else {
        struct lib* p = lib_head;
        while(p){
            print_lib(p);
            p = p->next;
        }
        printf("\n");
    }
}

void add_lib(char* category, char* type, char* name){
    struct lib* p = lib_head;
    if(!p){
        lib_head = (struct lib*)malloc(sizeof(struct lib)+3);
        lib_head->category = category;
        lib_head->type = type;
        lib_head->name = name;
        lib_head->next = NULL;
    } else {
        while(p->next){
            p = p->next;
        }
        struct lib* q = (struct lib*)malloc(sizeof(struct lib)+3);
        q->category = category;
        q->type = type;
        q->name = name;
        q->next = NULL;
        p->next = q;
    }
}

struct lib* find_lib(char* name){
    if(!lib_head){
        return NULL;
    } else {
        struct lib* p = lib_head;
        while(p){
            if(strcmp(name, p->name) == 0){
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
}

void remove_lib(char* name){
    if(strcmp(name, lib_head->name) == 0){
        lib_head = lib_head->next;
    } else {
        struct lib* p = lib_head;
        while(p->next){
            if(strcmp(name, p->next->name) == 0){
                p->next = p->next->next;
                break;
            }
        }
    }
}

void clear_lib(){
    if(!lib_head){
        return;
    } else {
        struct lib* p = lib_head;
        while(p){
            struct lib* q = p;
            p = p->next;
            free(q);
        }
    }
}

int reg_lib(char* category, char* type, char* name){
    if(!name){
        return REG_FAIL;
    }
    struct lib* p = find_lib(name);
    if(!p){
        add_lib(category, type, name);
    }
    return REG_SUCCESS;
}

void op_type(int op){
    switch (op) {
    case 1:
        print_libs();
    case 2:
        print_libs();
        break;
    case 3:{
        char* name = (char*)malloc(sizeof(char)*30);
        printf("input lib name:");
        scanf("%s", name);
        struct lib* lib = find_lib(name);
        if(!lib){
            printf("no such lib:%s\n", name);
        } else {
            getchar();
            char* args = (char*)malloc(sizeof(char)*200);
            printf("input lib args:");
            scanf("%[^\n]", args);
            char* lib_path = (char*)malloc(sizeof(char)*100);
            strcpy(lib_path, ".");
            #ifdef _WIN32
                char* sep = "\\";
            #else
                char* sep = "/";
            #endif
            strcat(lib_path, sep);
            strcat(lib_path, lib->category);
            strcat(lib_path, sep);
            strcat(lib_path, lib->type);
            strcat(lib_path, sep);
            strcat(lib_path, lib->name);
            #ifdef _WIN32
            strcat(lib_path, ".exe");
            #endif
            strcat(lib_path, " ");
            strcat(lib_path, args);
            printf("%s\n",lib_path);
            system(lib_path);
            free(lib_path);
            free(args);
        }
        free(name);
        break;
    }
    case 4:
        clear_lib();
        printf("cleared\n");
        break;
    default:
        break;
    }
}

void op_prompt(){
    int op = 1;
    while(op >= 1 && op <= 4){
        printf("\nchoose an operation:\n");
        printf("\t1   .add lib;\n");
        printf("\t2   .show libs;\n");
        printf("\t3   .exec lib;\n");
        printf("\t4   .clear lib;\n");
        printf("\telse.exit;\n");
        printf("input:");
        int flag = scanf("%d", &op);
        getchar();
        fflush(stdin);
        if(flag==1){
            op_type(op);
        }
        if(!op){
            op = 1;
        }
    }
}

#define SPLIT_CHAR ","

struct lib* parse_lib_line(char* orig){
    char* line = malloc(sizeof(char)*200);
    strcpy(line, orig);
    struct lib* q = (struct lib*)malloc(sizeof(struct lib)+3);
    char* p = line;
    char* temp;
    temp = strtok(p, SPLIT_CHAR);
    q->category = temp;
    temp = strtok(NULL, SPLIT_CHAR);
    q->type = temp;
    temp = strtok(NULL, SPLIT_CHAR);
    q->name = temp;
    if(q->name){
        q->name[strlen(q->name)-1] = 0;
    }
    q->next = NULL;
    return q;
}


int main(){
    clear_lib();
    char* file_name = "lib.txt";
    char line[200];
    FILE* fp;
    if(!(fp=fopen(file_name,"r")))
    {
        printf("file error\n");
        return 0;
    }
    while(!feof(fp))
    {
        fgets(line, 200, fp);
        struct lib* p = parse_lib_line(line);
        if(p){
            reg_lib(p->category, p->type, p->name);
        }
    }
    printf("inited libs:\n");
    print_libs();
    fclose(fp);
    op_prompt();
	return EXIT_SUCCESS;
}
