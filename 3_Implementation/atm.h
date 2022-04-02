#include<string.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    char statement[50];
    struct node* link;
} node;

void Withdraw(node **, int *);
void Updateamount(node **, char *);
void Modifyhistory(node **);
void History(node **);
void Generator(void);
int validation(void);
void Balanceamount(int *);
void Deposit(node **, int *);
