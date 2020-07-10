
#ifndef LIB_H
#define LIB_H

#define REG_SUCCESS 1
#define REG_FAIL 0

typedef struct lib{
    char* name;
    char* type;
    char* category;
    struct lib* next;
}lib;

struct lib* lib_head;

struct lib* find_lib(char* name);

void remove_lib(char* name);

int reg_lib(char* category, char* type, char* name);


#endif
