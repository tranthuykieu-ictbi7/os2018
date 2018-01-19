#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 10

typedef struct{
    char type;
        // 0 = fried chicken, 1 = French fries
    int amount;
        // pieces or weight
    char unit;
        // 0 = piece, 1 = gram
} item;

item buffer[BUFFER_SIZE];
int first = 0; 
int last = 0;

void produce(item *i){
    while ((first + 1) % BUFFER_SIZE == last){
        // do thing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume(){
    item *i = malloc(sizeof(item));
    while (first == last){
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    return i;
}

int main(){
    item *tiramisu = (item *) malloc(sizeof(item));
    tiramisu->type = '1';
    tiramisu->amount = 10;
    tiramisu->unit = '1';

    item *coffe = (item *) malloc(sizeof(item));
    coffe->type = '2';
    coffe->amount = 20;
    coffe->unit = '2';
    

    printf("\nHello, welcome to #apieceofcake :)) \n\n");
    produce(tiramisu);
    printf("Tiramisu is ready\n\n");
    produce(coffe);
    printf("Coffe is ready, too\n\n");

    item *eat = consume();
    printf("Delivered Tiramisu = %c\n\n", eat->type);

    return 0;
}
    

