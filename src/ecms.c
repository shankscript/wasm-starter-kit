#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <emscripten/emscripten.h>

int main(int argc, char ** argv)
{
    printf("WASM loaded\n");
}


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
   int    num;
   char*    name;
} Person;


int EMSCRIPTEN_KEEPALIVE roll_dice() {
    srand ( time(NULL) );
    return rand() % 6 + 1;
}

EMSCRIPTEN_KEEPALIVE int  myFunction(int count, char ** argv) {
  printf("MyFunction Called !! \n");
  Person p = {320, "shanks"};
  return p.num * count;
}

#ifdef __cplusplus
}
#endif