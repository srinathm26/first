#include<string.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char statement[50];
    struct node* link;
} node;

void withdrawMoney(node **, int *);
void saveHistory(node **, char *);
void removeHistory(node **);
void History(node **);
void Generator(void);
int validation(void);
void Balanceamount(int *);
void Deposit(node **, int *);
