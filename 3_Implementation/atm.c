#include "header.h"

int main(void) {
    int value1, value2, pin = 0, balance = 0;
    node *head = NULL;
    while (1) {
        printf("\nATM System");
        printf("\nSelect a valid option");
        printf("1. Generate PIN\n2. Use ATM\n3. Exit\n");
        scanf("%d", &value1);

        switch (value1) {
            case 1: Generator();
                    exit(EXIT_SUCCESS);

            case 2: pin = validation();

                    if (pin) {
                        printf("\nSUCCESS\n");
                    } else {
                        printf("\nInvalid PIN\n");
                        printf("\nTry agian\n");
                        exit(EXIT_FAILURE);
                    }

                    while(pin) {
                        printf("\nMenu\n");
                        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. History\n5. Exit\n\n");

                        printf("Enter your choice: ");
                        scanf("%d", &value2);

                        switch(value2) {
                            case 1: Balanceamount(&balance);
                                    break;
                            case 2: Deposit(&head, &balance);
                                    break;
                            case 3: Withdraw(&head, &balance);
                                    break;
                            case 4: History(&head);
                                    break;
                            case 5: printf("\nTHANK YOU\n");
                                    exit(EXIT_SUCCESS);
                            default: printf("\nInvalid option \n");
                                     break;
                        }
                    }

            case 3: exit(EXIT_SUCCESS);

            default: printf("\nInvalid choice\n");
                     break;
        }
    }
    return 0;
}
int validation(void) {
    FILE *fp;
    char pin1[8];
    char key[8];
    int pin = 0;

    printf("\n\nEnter the PIN: \n");
    scanf("%s", key);

    fp = fopen("pin.txt", "r");
    if (NULL == fp) {
        printf("\nFile cannot be opened\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(pin1, sizeof(pin1), fp) != NULL) {
        if (strstr(pin1, key)) {
            pin = 1;
        }
    }
    fclose(fp);

    return pin;
}


void Generator(void) {
    FILE *fp;
    srand(time(NULL));
    int generatedPin = 1000+rand()%9000;

    printf("\nPIN generated successfully\n");
    printf("\nYour generated PIN: %d\n", generatedPin);
   
    fp = fopen("pin.txt", "a");
    if (NULL == fp) {
        printf("\nFile not found!");
        exit(EXIT_FAILURE);
    }

    
    fprintf(fp, "%d\n", generatedPin);
    fclose(fp);
}


void Balanceamount(int *balance) {
    printf("\nbalance Amount : %d\n", *balance);
}


void Withdraw(node **head, int *balance) {
    int wAmount;
    char withdrawStmt[50];

    printf("\nWithdraw amount...");
    scanf("%d", &wAmount);

    if (wAmount > 0) {
        if (wAmount > *balance) {
            printf("Not sufficent Balance");
        } else {
            *balance -= wAmount;
            printf("\nRs.%d withdrawn\n", wAmount);
            snprintf(withdrawStmt, sizeof(withdrawStmt), "Rs.%d withdrawn\n", wAmount);
            Updateamount(head, withdrawStmt);
        }
    } else {
        printf("\nInvalid amount\n.");
    }
}


void Updateamount(node **head, char *str) {
    static int count = 0;
    node *temp;
    temp = (node *)malloc(sizeof(node));

    strcpy(temp->statement, str);
    temp->link = NULL;

    if (NULL == *head) {
        *head = temp;
        count++;
    } else {
        if (10 == count) {
            Modifyhistory(head);
            count--;
        }
        node *p;
        p = *head;
        while (NULL != p->link) {
            p = p->link;
        }
        p->link = temp;
        count++;
    }
}

void Modifyhistory(node **head) {
    node *temp;
    temp = *head;
    *head = (*head)->link;
    temp->link = NULL;
    free(temp);
}
void Deposit(node **head, int *balance) {
    int dAmount;
    char depositStmt[50];

    printf("\nEnter the amount....");
    scanf("%d", &dAmount);

    if (dAmount > 0) {
        *balance += dAmount;
        printf("\n%d deposited\n", dAmount);

        snprintf(depositStmt, sizeof(depositStmt), "Rs.%d deposited\n", dAmount);
        Updateamount(head, depositStmt);
    } else {
        printf("\nInvalid amount\n.");
    }
}

void History(node **head) {
    node *temp;
    temp = *head;

    if (NULL == temp) {
        printf("\nNo transaction history...\n");
    } else {
        printf("\nTransaction History\n-------------------\n\n");
        while (NULL != temp) {
            printf("%s\n", temp->statement);
            temp = temp->link;
        }
    }
}