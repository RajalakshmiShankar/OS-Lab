#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;

void producer()
{

    --mutex;

    ++full;

    --empty;

    x++;

    printf("\nProducer Produces "
           "item %d",x);

    ++mutex;
}


void consumer()
{
    --mutex;

    --full;

    ++empty;

    printf("\nConsumer Consumes "
           "item %d",x);
     x--;

    ++mutex;
}

int main()
{
    int ch, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");



    do {

        printf("\nEnter Your Choice:");
        scanf("%d", &ch);


        switch (ch) {
        case 1:


            if ((mutex == 1)
                && (empty != 0))
            {
                producer();
            }


            else
            {
                printf("Buffer is Full!");
            }
            break;

        case 2:

            if ((mutex == 1)
                && (full != 0))
            {
                consumer();
            }


            else
            {
                printf("Buffer is Empty!");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }while(ch!=3);
}