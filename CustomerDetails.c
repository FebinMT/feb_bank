#include <stdio.h>
#include <conio.h>
#include <string.h>

struct customer {

    long int pin;
    long int balance;
    char sname[20];
    char lname[20];

} c[10];

void main() {

    int i;
    char choice;

    FILE *p;
    FILE *fp;
    
    char name[30];
    
    clrscr();

    fp = fopen("FebBank.txt", "a+");

    do {

        printf("\n****** Feb Bank Customer Details ******\n");

        printf("\nEnter the Username of the Customer : ");
        scanf("%s", &name);

        p = fopen(name, "w+");

        for(i = 0; i < 10; i++) {

            printf("\nEnter the PIN number of the Customer : ");
            scanf("%ld", &c[i].pin);

            printf("\nEnter the surname of the Customer : ");
            scanf("%s", &c[i].sname);

            printf("\nEnter the last name of the Customer :  ");
            scanf("%s", &c[i].lname);

            printf("\nEnter the balance of the Customer :");
            scanf("%ld", &c[i].balance);

            fprintf(p, "%ld\n%s %s\n%ld", c[i].pin, c[i].sname, c[i].lname, c[i].balance);
            
            break;

        }

        fprintf(fp, "%s\n", name);

        printf("\n****** Do you want to continue filling in Customer details? (Y/N) ****** : ");
        choice = getche();
    
    } while(choice == 'Y' || choice == 'y');
    
    fclose(fp);
    fclose(p);

    getch();

}