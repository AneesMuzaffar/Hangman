#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void clrscr()
{
    system("@cls||clear") ;
}

void dis(char pword[],int no,int turn,int p)
{
    int j;
    if(p==0)
    {
        clrscr();
    printf("\n\n\t\t\t\t\t\tHANGMAN\n\n");
    printf("\n\n\n\n\t\t\t\t\tTurns left = %d\n\n\n\n\t\t\t\t\t",turn);
    for(j=0;j<no;j++)
    {
        printf(" %c",pword[j]);
    }
    printf("\n\n\n\n\t\t\t\t\tEnter any alphabet:");
    }
    else if(p==1)
    {

    clrscr();
    printf("\n\n\t\t\t\t\t\tHANGMAN\n\n");
    printf("\n\n\n\n\t\t\t\t\tTurns left = %d\n\n\n\n\t\t\t\t\t",turn);
    for(j=0;j<no;j++)
    {
        printf(" %c",pword[j]);
    }
    printf("\n\n\n\t\t\t\t\tAlready entered\n\t\t\t\t\tEnter any alphabet:");
    }

    else
    {
        printf("\n\n\t\t\t\t\t\tHANGMAN\n\n");
    printf("\n\n\n\n\t\t\t\t\tTurns left = %d\n\n\n\n\t\t\t\t\t",turn);
    for(j=0;j<no;j++)
    {
        printf(" %c",pword[j]);
    }
    printf("\n\n\n\n\t\t\t\t\tEnter any alphabet:");
    }


}

int main()
{
    srand(time(NULL));
    FILE *fo;
    fo = fopen("D:\\testhangman.txt","w+");
    fprintf(fo,"wierd\nhandkerchief\nindict\naccommodate\nrhythm\nthursday\nconscience\nembarrass\necstasy\ncharger\nprocessor\nafaan\nmoin\ntechnology\nblanket\nvelocity\naeroplane\nrecommend\ncupboard\nmaintenance");
    fclose(fo);
    FILE *fp;
    fp = fopen("D:\\testhangman.txt","r");
    char list[20][20];
    char word[50] , pword[50],entered[50];
    char c;
    int i=0,no,rem,turn = 10,flag = 0,found = 1,j=0,k=0,p = 3;
    while(fscanf(fp,"%s",list[i++])!=EOF);
    strcpy(word,list[rand()%20]);
    fclose(fp);
    no = strlen(word);
    rem = no;
    for(i=0;i<no;i++)
    {
        pword[i]='_';
    }
    pword[no] = NULL;
    dis(pword,no,turn,p);
    while(1)
    {
        found = 0;
        p = 0;
        if(flag == 1)
        {
            printf("\n\n\t\t\t\t\tHURRAY! YOU SAVED HIM.");
            break;
        }
        c = getch();

        for(j=0;j<k;j++)
        {
            if(c == entered[j])
            {
                p = 1 ;
                found = 1;
                break;
            }
        }
        if(j==k)
        {

            for(i=0;i<no;i++)
            {
                if(word[i] == c)
                {
                    pword[i] = c;
                    rem--;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            turn--;
        }
        dis(pword,no,turn,p);
        if(rem==0)
            flag = 1;
        if(turn == 0)
        {
            printf("\n\n\t\t\t\t\tALAS! YOU COULDNOT SAVE HIM");
            break;
        }
        entered[k++] = c;

    }
    getch();
    printf("%s",word);
    return 0;
}
