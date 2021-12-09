#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_CARD 52


int game(void);
int convert_jkq(int a);
void card(int num);
int shuff(int cards[]);

int main(void)
{
    char again;
    game();
    printf("\nWould you like to play again? 'y' or 'n':\n");
    do{
        again = getchar();
    } while (again!='y' && again!='n');
   
    if (again == 'y')
    {
        printf("\nOK, let's go again!\n\n");
        main();
    }
  
    return 0;
}

int game(void)
{
    int i;
    int psum=0;
    int bsum=0;
    int pcards[5]={0};
    int bcards[5]={0};
    int cards[MAX_CARD];
    char start;
    char d;
    
    //enter to begin the game
    printf("Press Enter To Play!\n");

    do{
        start = getchar();
    } while (start != '\n');
    printf("\n");
    
    //shuff the cards
    shuff(cards);

    //give the cards
    pcards[0]=cards[0];
    pcards[1]=cards[1];
    bcards[0]=cards[2];
    bcards[1]=cards[3];
    
    //the 2 cards player get
    printf("One of Computer's card:\n");
    card(bcards[0]);
    printf("\n");
    printf("Your Card:\n");
    card(pcards[0]);
    card(pcards[1]);
    printf("\n");
    
    i=0;
    for (i=0; i<2; i++)
    {
        if (pcards[i]%100 == 1)
        {
            printf("Choose Ace value of the card no: %d,\n 'y' for 11 or 'n' for 1 :\n", i+1);
            do{
                d = getchar();
            } while (d!='y' && d!='n');
            
            if (d == 'y')
            {
                printf("You've chosen value 11 for your Ace.\n");
                psum = psum + 11;
            }
            else if(d == 'n')
            {
                printf("You've chosen value 1 for card Ace.\n");
                psum = psum +1;
            }
        }
        else if (convert_jkq(pcards[i]) %100 ==10) psum = psum + 10;
        else psum = psum + pcards[i]%100;
        
        if (psum > 21)
        {
            printf("Sum of your cards: %d\n\n",psum);
            printf("Computer win!\n");
            return 1;
        }
        else if (psum == 21)
        {
            printf("Sum of your cards: %d\n\n",psum);
            printf("You win!\n");
            return 0;
        }
    }
    printf("Sum of your card: %d\n\n",psum);
    
    //whether player get another cards
    i=0;
    for (i=0; i<3; i++)
    {
        char j = 'n';
        
        printf("Would you like to have more cards? y or n?:\n");
        do{
            j = getchar();
        } while (j!='y' &&j!='n');
        
        if (j=='y')
        {
            printf("You've got another card\n");
            pcards[i+2]=cards[i+4];
            printf("and your card %d is:\n", i+3);
            card(pcards[i+2]);
            
            if (pcards[i+2]%100 == 1)
            {
                printf("Choose Ace value of the card %d, input 'y' for 11 or 'n' for 1:\n", i+3);
                do{
                    d = getchar();
                } while (d!='y' && d!='n');
                if (d == 'y')
                {
                    printf("You've chosen value 11 for card Ace.\n");
                    psum = psum + 11;
                }
                else if(d == 'n')
                {
                    printf("You've chosen value 1 for card Ace.\n");
                    psum = psum +1;
                }
            }
            else if (convert_jkq(pcards[i+2]) %100 ==10) psum = psum + 10;
            else psum = psum + pcards[i+2]%100;
            
            if (psum > 21)
            {
                printf("Sum of player's cards: %d\n\n",psum);
                printf("Computer win!\n");
                return 1;
            }
            else if (psum == 21)
            {
                printf("Sum of your cards: %d\n\n",psum);
                printf("You win!\n");
                return 0;
            }
            else printf("Sum of your cards: %d\n\n",psum);
        }
        else
        {
            printf("Sum of your cards: %d\n\n",psum);
            break;
        }
    }
    if (i == 3)
    {
        printf("You win!\n");
        return 0;
    }
    
    //the 2 cards of computer
    printf("Computer's cards:\n");
    card(bcards[0]);
    card(bcards[1]);

    if (bcards[0]%100 + bcards[1]%100 == 2)
    {
        bsum=12; //two A cards
        printf("Sum of computer's cards now:%d\n\n", bsum);
    }
    else if ((convert_jkq(bcards[0]))%100 + (convert_jkq(bcards[1]))%100 ==1)
    {
        bsum=21;
        printf("Sum of computer's cards: %d\n\n", bsum);
        printf("Computer win!\n");
        return 1;
    }
    else if (bcards[0]%100==1 || bcards[1]%100==1)
    {
        bsum=(bcards[0]+bcards[1])%100+(rand()%2)*10;
        printf("Sum of computer's cards: %d\n\n", bsum);
    }
    else
    {
        bsum = (convert_jkq(bcards[0]))%100 + (convert_jkq(bcards[1]))%100;
        printf("Sum of computer's cards: %d\n\n", bsum);
    }
    
    //whether computer get another cards until bsum>16
    //i=0;
    for (i=0; i<3 && bsum<17; i++)
    {
        bcards[i+2]=cards[i+7];
        printf("Computer's card %d is:\n", i+3);
        card(bcards[i+2]);
        
        if (bcards[i+2]%100 == 1)
        {
            if (bsum+11 <= 21)
            {
                printf("Computer has chosen Ace as 11\n");
                bsum = bsum+11;
                printf("Sum of computer's cards now: %d\n\n", bsum);
            }
            else
            {
                printf("Computer has chosen Ace as 1\n");
                bsum = bsum+1;
                printf("Sum of computer's cards now: %d\n\n", bsum);
            }
        }
        else
        {
            bsum = bsum + convert_jkq(bcards[i+2])%100;
            printf("Sum of computer's cards now: %d\n\n", bsum);
        }
    }
    if (i == 3)
    {
        printf("Computer win!\n");
        return 1;
    }
    
    //the last step
    if (bsum>21 || psum>bsum)
    {
        printf("Player win!\n");
        return 0;
    }
    else if (psum == bsum)
    {
        printf("Draw\n");
        return 3;
    }
    else if (psum < bsum)
    {
        printf("Computer win!\n");
        return 1;
    }
        
    return 3;
}
int convert_jkq(int a)
{
    if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
    else return a;
}

void card(int num)
{
    char fl;
    int po_num;
    
    fl = num / 100;
    po_num = num % 100;
    switch (po_num)
    {
        case 1:
        {
            printf("%c\n", fl);
            printf("Ace\n");

            break;
        }
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        {
            printf("%c\n", fl);
            printf("%2d\n", po_num);

            break;
        }
        case 11:
        {
            printf("%c\n", fl);
            printf("Jack\n");
            break;
        }
        case 12:
        {
            printf("%c\n", fl);
            printf("Queen\n");
            break;
        }
        case 13:
        {
            printf("%c\n", fl);
            printf("King\n");
            break;
        }

    }
}
int shuff(int cards[])
{
    
    int t;
    int i;
    int desk[52];
    for (i=0;i<52;i++)
        desk[i] = (i/13+3)*100 + i%13 + 1;

    srand((unsigned)time(NULL));
    for (i = 0; i < 52; i++)
    {
        do
        {
            t = rand() % 52;
        } while (desk[t] == 0);
        cards[i] = desk[t];
        desk[t] = 0;
    }
    
    return 0;
}
