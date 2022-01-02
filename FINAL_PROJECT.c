/* This is a simple project with c Banking Management System */

#include <stdio.h>

struct customer
{
    int balance;
    int serial;
    int account_no;
    char name[100];
};

void passing(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void withdraw(struct customer[], int, int, int);
void deposit(struct customer[], int, int, int);
int up(struct customer[], int, int);
void delete(struct customer[],int,int);

int main()
{
    struct customer data[100];
    int n, choice, account_no, amount, index, dlt, ac_d;

    printf("\n\n\t   ----------------------------------------------------------------------------------------\n");
    printf("\n            \t\t  -------->>>Hello CEO Welcome To Your Banking System<<<-----------\n");
    printf("\n\t   ----------------------------------------------------------------------------------------\n");
    printf("\n            Please Sir enter the number of customer records you want to enter? : ");
    scanf("%d", &n);
    passing(data, n);
    do
    {

        printf("\n\n\t\t\t-------->>Check the banking menu list<<--------\n\n");
        printf("\t\t\tEnter 1 to display all records.\n");
        printf("\t\t\tEnter 2 to search a record.\n");
        printf("\t\t\tEnter 3 to deposit amount.\n");
        printf("\t\t\tEnter 4 to withdraw amount.\n");
        printf("\t\t\tEnter 5 to delete AC.\n");
        printf("\t\t\tEnter 6 to update a record from the banking menu list.\n");
        printf("\t\t\tEnter 0 to exit\n");
        printf("\n\t\t\tPlease Sir enter your choice --> : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(data, n);
            break;
        case 2:
            printf("\n\t\tSir kindly you have to enter the account number to search --> : ");
            scanf("%d", &account_no);
            index = search(data, n, account_no);
            if (index ==  - 1) printf("\n\t(error 404)Record not found )): ");

            else printf("\t\tA/C Number: %d\n\t\tName: %s\n\t\tBalance: %d\n",data[index].account_no, data[index].name, data[index].balance);
            break;

        case 3:
            printf("\n\t\tEnter your account number to deposit: -->> ");
            scanf("%d", &account_no);
            printf("\t\tEnter the amount to deposit : -->> ");
            scanf("%d", &amount);
            deposit(data, n, account_no, amount);
            break;

        case 4:
            printf("\n\t\tEnter your account number for withdraw -->> : ");
            scanf("%d", &account_no);
            printf("\t\tEnter the amount to withdraw -->> : ");
            scanf("%d", &amount);
            withdraw(data, n, account_no, amount);

        case 5:
            printf("\n\t\tEnter your account number to delete -->> : ");
            scanf("%d",&dlt);
            delete(data,n,dlt);
            break;

        case 6:
            printf("\n\t\tEnter the account  number that you  wanna to update : ");
            scanf("%d",&ac_d);
            up(data, n, ac_d);
            //if(ind == -1) printf("\n\t(error 404)Record not found )): ");
            printf("\n\t\t-->>Update successfully -->>");
            break;
        }
    }
    while (choice != 0);

    return 0;
}

void passing(struct customer list[100], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\n\t\t\tEnter the data for Record --> %d", i+1);

        printf("\n\t\t\tEnter the account_no -->> ");
        scanf("%d", &list[i].account_no);
        getchar();
        printf("\t\t\tEnter name -->> ");
        gets(list[i].name);
        list[i].balance = 0;
    }
}


void delete(struct customer list[100], int s,int dlt)
{
    int i,data;
    //printf("Enter the account number to delete : \n");
    //scanf("%d",&data);
    for(i=0; i<s; i++)
    {

        if(dlt == list[i].account_no )
        {
            list[i].account_no=0;
            strcpy(list[i].name,"*****");
            list[i].balance=0;
        }
    }

}


void display(struct customer list[100], int s)
{
    int i;

    printf("\n\n\n\t\tA/c No\t\tName\t\tBalance\n");
    for (i = 0; i < s; i++) printf("\n\t\t%d\t\t%s\t\t%d\n", list[i].account_no, list[i].name, list[i].balance);
}

int search(struct customer list[100], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number) return i;
    }
    return  - 1;
}

void deposit(struct customer list[], int s, int number, int amnt)
{
    int i = search(list, s, number);
    if (i ==  -1) printf("\n\t(error 404)Record not found )):\n");
    else list[i].balance += amnt;
}

void withdraw(struct customer list[], int s, int number, int amnt)
{
    int i = search(list, s, number);
    if (i ==  -1) printf("\n\t(error 404)Record not found )):\n");

    else if (list[i].balance < amnt) printf("\n\tSorry Sir your balance is insufficient \n");

    else list[i].balance -= amnt;
}

int up(struct customer list[100], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            printf("\n\t\t\tEnter the account_no -->> ");
            scanf("%d", &list[i].account_no);
            getchar();
            printf("\t\t\tEnter name -->> ");
            gets(list[i].name);
            list[i].balance = 0;
        }
    }
    return  - 1;
}
