#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mm, yy, dd = 31, c[31];
char menu[10], event_name[50][32][32];
//สร้างปฏิทิน
int calendar()
{
    printf("----------------------------------------------------------------");
    printf("\n|");
    for (int day = 1; day <= dd; day++)
    {
        printf("%02d      |", day);
        if (day % 7 == 0)
        {
            printf("\n|");
            for (int d = 1; d <= 7; d++)
            {
                int event = d + (day - 7);
                printf("%02d event|", c[event]);
            }
            printf("\n----------------------------------------------------------------\n|");
        }
        if (day == dd)
        {
            printf("\n|");
            for (int d = 29; d <= dd; d++)
            {
                printf("%02d event|", c[d]);
            }
            printf("\n-");
            for (int i = 1; i <= dd - 29 + 1; i++)
            {
                printf("---------");
            }
            
        }
        
    }
    printf("\n");
}

int de_day(int show_day)
{
    if (c[show_day] == 0)
    {
        printf("Now have not event on this day\n");
    }
    
    for (int i = 0; i < c[show_day]; i++)
    {
        printf("%s\n", event_name[i][show_day]);
    }
}

int planner()
{
    int edit_day;
    do
    {
        printf("choose day : ");
        scanf("%d", &edit_day);
        if (!(edit_day <= 31 && edit_day >= 1))
        {
            printf("Enter not correct\n");
        }
        
    } while (!(edit_day <= 31 && edit_day >= 1));

    
    de_day(edit_day);
    do
    {
        printf("\nAdd your event (if what back enter stop) :");
        char want_add[50];
        scanf("%s", &want_add);
        if (strcmp(want_add, "back") == 0) break;
        strcpy(event_name[c[edit_day]][edit_day], want_add);
        c[edit_day]++;
        printf("Added\n");
        
    } while (1);
    system("cls");
    
}

int day()
{
    int do_day;
    do
    {
        printf("choose day : ");
        scanf("%d", &do_day);
        if (!(do_day <= 31 && do_day >= 1))
        {
            printf("Enter not correct\n");
        }
        
    } while (!(do_day <= 31 && do_day >= 1));
    de_day(do_day);
}

int main()
{
    int count=0;
    char name[50]="ClickCamp14_Project";
    int length_name = strlen(name);
    for(int i=0;i<3;i++){
            count=0;
        for(int j=0;j<=i;j++){
            printf("*");
            count++;
        }
        if(i==1){
            printf(" %s ",name);
        }
        else for(int k=0;k<length_name-count*2+6;k++){
            printf(" ");
        }
        for(int j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    

    do 
    {
        calendar();
        printf("\np = Planner\nd = Detail in day\nq = Quit\n");
        printf("\nEnter : ");
        scanf("%s", menu);
        system("cls");
        if (strcmp(menu, "p") == 0 || strcmp(menu, "P") == 0) planner();
        else if (strcmp(menu, "d") == 0 || strcmp(menu, "D") == 0) day();
        else if (strcmp(menu, "q") == 0 || strcmp(menu, "Q") == 0) break;
        else printf("Select error\n");
        
    } while (menu != "quit");

    system("cls");
    printf("Click Camp 14\nKritsakon Aeknok (Camp)\nPolrapat Roemraksachaikul (Pun)\nJiravasin Jantavongvaich (Music)");
    printf("\n\n _______   __\n");
    printf("/       \\ /  |\n");
    printf("$$$$$$$  |$$ |  ______   _______   _______    ______    ______\n");
    printf("$$ |__$$ |$$ | /      \\ /       \\ /       \\  /      \\  /      \\\n");
    printf("$$    $$/ $$ | $$$$$$  |$$$$$$$  |$$$$$$$  |/$$$$$$  |/$$$$$$  |\n");
    printf("$$$$$$$/  $$ | /    $$ |$$ |  $$ |$$ |  $$ |$$    $$ |$$ |  $$ | \n");
    printf("$$ |      $$ |/$$$$$$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$/ $$ |      \n");
    printf("$$ |      $$ |$$    $$ |$$ |  $$ |$$ |  $$ |$$       |$$ | \n");
    printf("$$/       $$/  $$$$$$$/ $$/   $$/ $$/   $$/  $$$$$$$/ $$/        Advice by P\'Atom\n");


    return 0;
}