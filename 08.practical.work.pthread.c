#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>


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

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_rountine) (void*), void *arg);

void *threadFunction_produce(void *param){
    item *tea = (item*) malloc(sizeof(item));
    tea->type = '3';
    tea->amount = 5;
    tea->unit = 'a';

    item *ice = (item*) malloc(sizeof(item));
    ice->type = '4';
    ice->amount = 6;
    ice->unit = 'b';  
    
    item *candy = (item*) malloc(sizeof(item));
    candy->type = '5';
    candy->amount = 7;
    candy->unit = 'c';

    produce(tea);
    printf("Tea is ready\n");
    printf("First: %d, last: %d, \n\n", first, last);
    
    produce(ice);
    printf("Ice is ready");
    printf("First: %d, last: %d, \n\n", first, last);
    
    produce(candy);
    printf("Candy is ready");
    printf("First: %d, last: %d, \n\n", first, last);
}

void *threadFunction_consume(void *param){
    item *order1 = consume();
    printf("Order tea = %c \n\n", order1->type);
    printf("First: %d, last: %d, \n\n", first, last);
    
    item *order2 = consume();
    printf("Order ice = %c \n\n", order2->type);
    printf("first = %d , last = %d\n\n",first,last);
}

int main(){
        // create a background thread to execute threadFunction
    pthread_t produce_id;
    pthread_create(
                    &produce_id,             // get thread id
                    NULL,              // skip the attributes
                    threadFunction_produce,     // thread function name
                    NULL);              // argument to thread function

    pthread_t consume_id;
    pthread_create(&consume_id, NULL, threadFunction_consume, NULL);

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
    printf("First: %d, last: %d, \n\n", first, last);
    
    produce(coffe);
    printf("Coffe is ready, too\n\n");
    printf("First: %d, last: %d, \n\n", first, last);

    item *eat = consume();
    printf("Delivered Tiramisu = %c\n\n", eat->type);
    printf("First: %d, last: %d, \n\n", first, last);
    
    pthread_join(produce_id, NULL);
    pthread_join(consume_id, NULL);

    return 0;
}
    

