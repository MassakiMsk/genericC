#include <stdio.h>

typedef struct stc {
    int num;
    char c;
} stc;

typedef enum en {
    um,
    dois,
    tres
} en;

typedef enum en1 {
    um1,
    dois1,
    tres1
} en1;

#define print_any(X) _Generic((X), int: print_int, \
                                   char: print_char, \
                                   char*: print_char_array, \
                                   float: print_float, \
                                   stc: print_struct, \
                                   en: print_enum, \
                                   en1: print_enum1, \
                                   default: print_default)(X)\

int print_int(int i) {
  return printf("int: %d\n", i);
}

int print_float(float f) {
  return printf("float: %f\n", f);
}

int print_char(char c) {
  return printf("char: %c\n", c);
}

int print_char_array(char* s) {
  return printf("string: %s\n", s);
}

int print_struct(stc e) {
  return printf("Struct: %d %c\n", e.num, e.c);
}

int print_enum(en e) {
  return printf("enum en: %d\n", e);
}

int print_enum1(en1 e) {
  return printf("enum en1: %d\n", e);
}

int print_default() {
  return printf("Tipo nao reconhecido\n");
}

int main() {
    int i = 10;
    float f = 3.1;
    char c = 'a';
    char s[10] = "teste";
    stc e = {30, 'b'};
    en enu = tres;
    en1 enu1 = dois1;

    printf("\n\n");
    print_any(i);
    print_any(f);
    print_any(c);
    print_any(s);
    print_any(e);
    print_any(enu);
    print_any(enu1);
    printf("\n\n");
    
    return 0;
}
