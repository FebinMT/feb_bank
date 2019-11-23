#include <stdio.h>
#include <conio.h>

struct customer {

    long int pin;
    long int balance;
    char sname[30];
    char lname[30];

} c[10];

void main() {

    long int pinch, pinnew, balance;
    long int amount, withdraw;
    int i, choice, ch;
    char name[30];

    FILE *fp;
    FILE *p;

    clrscr();
    
    fp = fopen("FebBank.txt", "r");

    printf("\n********** Welcome to Feb Bank ATM Services **********\n");
    printf("\nInsert your ATM card !\n");
    printf("\nVerifying ... \nConnecting to our servers, this may take a few seconds ...\n");
    printf("\nEnter your PIN number and press Enter\n");
    scanf("%ld", &pinch);
    printf("\nAuthenticating ...\n");

    for(i = 0; i < 10; i++) {

        fscanf(fp, "%s", &name);

        p = fopen(name, "r");

        fscanf(p, "%ld\n%s %s\n%ld", &c[i].pin, &c[i].sname, &c[i].lname, &c[i].balance);

        if(c[i].pin == pinch) {

            printf("\nWelcome %s %s\n", c[i].sname, c[i].lname);

            do {

                printf("\n******************************");
                
                printf("\nPress 1 to Check Balance\n");
                printf("\nPress 2 to Withdraw Cash\n");
                printf("\nPress 3 to Change your PIN number\n");
                printf("\nPress 4 to Quit\n");

                printf("\n******************************");
                
                scanf("%d", &choice);
                
                fclose(p);

                switch(choice) {

                    case 1:
                        
                        printf("\nYour balance is Rs : %ld ", c[i].balance);
                    
                    break;

                    case 2:
                    
                        printf("\nEnter the amount to withdraw: ");
                        scanf("%ld", &withdraw);

                        if (withdraw > (c[i].balance - 500)) {

                            printf("\nInsufficient funds !");
                        
                        }

                        else {

                            p = fopen(name,"w");
                            c[i].balance = c[i].balance - withdraw;

                            printf("\nKindly collect cash");
                            printf("\nYour balance is %ld", c[i].balance);
                            
                            fprintf(p,"%ld\n%s %s\n%ld", c[i].pin, c[i].sname, c[i].lname, c[i].balance);
                            
                            fclose(p);

                        }
                        
                    break;

                    case 3:

                        printf("\nEnter your current PIN number :\n");
                        scanf("%ld", &pinnew);
                        printf("\nAuthenticating.....\n");

                        if(pinnew == c[i].pin) {

                            p = fopen(name, "w");
                            
                            printf("\nPIN number verified\nEnter new PIN number :");
                            scanf("%ld", &c[i].pin);

                            fprintf(p, "\n%ld\n%s\n%ld", c[i].pin, c[i].sname, c[i].balance);
                            fclose(p);
                            
                            break;

                        }

                        else {

                            printf("\nInvalid PIN number");
                        
                        }
                    
                    break;

                    case 4:
                        
                        printf("\nThank you for using Feb Bank ATM Services");
                    
                    break;
                    
                    default:
                        
                        printf("\nInvalid choice !");

                }

                printf("\n\n\nDo you want to carry out another transaction? (y/n): ");

                ch = getche();

            } while(ch=='y' || ch=='Y');

        }
        
        else
            printf("\n\nInvalid card. Kindly contact the nearest branch for more details\n\n");
        
        break;
        
    }

    printf("\n\nHave a nice day !");
    fclose(fp);
    getch();

}