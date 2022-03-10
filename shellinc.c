#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void date()
{
    time_t my_time= time(NULL);
    printf("%s",ctime(&my_time));
}
void cal(int cal_status)
{
    int month, year;
    if(cal_status==0)
    {
        time_t my_time;
        struct tm* current_time;
        my_time= time(NULL);
        current_time= localtime(&my_time);
        month= (current_time->tm_mon+1);
        year= (current_time->tm_year+1900);
    }
    else
    {
        scanf("%d",&month);
        scanf("%d",&year);
    }
    char months[12][10]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDays[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0 && year%100!=0) || ((year%400)==0))
    monthDays[1] = 29;
    int Jan_Day= (((year-1)*365)+((year-1)/4)-((year-1)/100)+(year/400)+1)%7;
    int difference=0;
    for(int i=0; i<(month-1); i++)
    difference+=monthDays[i];
    difference%=7;
    int startingDay= Jan_Day+difference;
    if(startingDay>6) startingDay-=7;
    int weekday=0;
    printf("----------%s %d----------\n",months[month-1],year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");
    for(weekday=0; weekday<startingDay; weekday++)
    printf("     ");
    for(int i=1; i<=monthDays[month-1];i++)
    {
        printf("%5d",i);
        if(++weekday>6)
        {
            printf("\n");
            weekday=0;
        }
    }
    printf("\n\n");
}
void touch()
{
    FILE *filePointer;
    char filename[100];
    scanf("%s", filename);
    filePointer= fopen(filename,"a");
    if(filePointer == NULL)
    printf("\nFile could not be created\n");
    fclose(filePointer);
}
void more()
{
    FILE *filepointer;
    char filename[100];
    scanf("%s",filename);
    filepointer= fopen(filename,"r");
    if(filepointer==NULL)
    printf("more: %s: No such file or directory\n",filename);
    else
    {
        char ch;
        while((ch=fgetc(filepointer))!=EOF)
        printf("%c",ch);
        printf("%s (END)\n",filename);
    }
    fclose(filepointer);
}
void man()
{
    char command_interpret[8];
    scanf("%s",command_interpret);
    if(strcmp(command_interpret,"date")==0)
    {
        printf("\n");
        printf("DATE(1)         BSD General Commands Manual         DATE(1)\n\n");
        printf("NAME\n  date -- display or set date and time\n\nSYNTAX\n  date (no arguments)\n\nDESCRIPTION\n  The command is invoked without arguments to display the \n  current date and time. The date utility displays the date \n  and time from the kernel clock.");
    }
    else if(strcmp(command_interpret,"cal")==0)
    {
        printf("\n");
        printf("CAL(1)          BSD General Commands Manual         CAL(1)\n\n");
        printf("NAME\n  cal -- displays a calendar\n\nSYNTAX\n  cal (no argumnets)\n  cal [month-number] [year(yyyy) format]\n\nDESCRIPTION\n  The cal utility displays a simple calendar in traditional \n  format for the specified month number of the given number.\n\n  If no arguments are passed then the calendar for current \n  month is displayed.");
    }
    else if(strcmp(command_interpret,"touch")==0)
    {
        printf("\n");
        printf("TOUCH(1)          BSD General Commands Manual         TOUCH(1)\n\n");
        printf("NAME\n touch -- creates file with default permissions\n\nSYNTAX\n  touch [filename]\n\nDESCRIPTION\n  The touch utility creates file with default permission. In \n  case the file already exists no changes are made to the \n  contents of the file");
    }
    else if(strcmp(command_interpret,"more")==0)
    {
        printf("\n");
        printf("MORE(1)          BSD General Commands Manual         MORE(1)\n\n");
        printf("NAME\n  more -- reads input from a existing file\n\nSYNTAX\n  more [filename]\n\nDESCRIPTION\n  The more command displays contents of an existing file. If \n  the file doesn't exist an error message is displayed.");
    }
    else if(strcmp(command_interpret,"man")==0)
    {
        printf("\n");
        printf("MAN(1)                                                MAN(1)\n\n");
        printf("NAME\n  man -- displays info about commands used in the terminal\n\nSYNTAX\n  man [command name]\n\nDESCRIPTION\n  The man command displays manual pages to help user understand \n  the syntax and functions of a command used in terminal window.");
    }
    else
    printf("No manual entry for %s",command_interpret);
    printf("\n");
}
int main()
{
    char command[10];
    int status =1;
    int cal_status;
    while(status)
    {
        printf("kishan@zeus$  ");
        scanf("%s", command);
        if(strcmp(command,"date")==0)
        date();
        else if(strcmp(command,"cal")==0)
        {
            char ch=getchar();
            if(ch=='\n')
            cal_status=0;
            else cal_status=1;
            cal(cal_status);
        }
        else if(strcmp(command,"touch")==0)
        touch();
        else if(strcmp(command,"more")==0)
        more();
        else if(strcmp(command,"man")==0)
        man();
        else if(strcmp(command,"exit")==0)
        status=0;
        else
        printf("kishan@zeus$: command not found: %s \n",command);
    }
    printf("Program exited");
    return 0;
}
