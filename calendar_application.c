#include <stdio.h>
#include <stdlib.h>

int get_the_1st_weekday(int year)
{
  int day;
  day = (((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year)/400)+1) % 7;
  return day;
}

int main()
{
	system("Color F1");
	int year,month,day,date;
	int days_in_month,week_day=0,starting_day,weekday;
	int choice;
	system("cls");
	printf("1. Find Out the Day\n");
	printf("2. Print the year calendar\n");
	printf("3. Exit\n");
	printf("ENTER YOUR CHOICE : \n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("Enter date, month, and year (dd-mm-yyyy): ");
		scanf("%d-%d-%d",&date,&month,&year);
		weekday  = (date+=month<3?year--:year-2,23*month/9+date+4+year/4-year/100+year/400)%7 ;
		switch(weekday)
		{
			case 0:
				printf("Day : Sunday\n");
				break;
			case 1:
				printf("Day : Monday\n");
				break;
			case 2:
				printf("Day : Tuesday\n");
				break;
			case 3:
				printf("Day : Wednesday\n");
				break;
			case 4:
				printf("Day : Thursday\n");
				break;
			case 5:
				printf("Day : Friday\n");
				break;
			case 6:
				printf("Day : Saturday\n");
		}
		break;
	case 2:
		printf("\nEnter a year : ");
		scanf("%d",&year); 
		char *months[]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
		int month_day[]={31,28,31,30,31,30,31,31,30,31,30,31};

		if((year%4==0 && year%100!=0) || year%400==0)
			month_day[1]=29;

		starting_day = get_the_1st_weekday(year);

		for(month = 0;month < 12;month++)
		{
			days_in_month=month_day[month];
			printf("\n\n               %s               \n",months[month]);
			printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

			for(week_day=0;week_day < starting_day;week_day++)
				printf("     ");

			for(day=1;day <= days_in_month;day++)
			{
				printf("%5d",day);

				if(++week_day > 6)
				{
					printf("\n");
					week_day = 0;
				}
				starting_day = week_day;
			}
		}
		break;
	case 3:
		exit(0);
		break;         
	} 
	return 0;
}