#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,n,type)\
{\
p=(type*)malloc(n*sizeof(type));\
if(p==NULL)\
{\
printf("Insufficient Memory\n");\
exit(0);\
}\
}
typedef struct{
char *dayName;
char *date;
char *activity;
}Day;
void create(Day *calendar) {
int i;
for (i = 0; i < 7; i++) {
MALLOC(calendar[i].dayName,20,char);
MALLOC(calendar[i].date,20,char);
MALLOC(calendar[i].activity,100,char);
}
}
void read(Day *calendar) {
int i;
for (i = 0; i < 7; i++) {
printf("Enter the name of the day for day %d: ", i + 1);
scanf("%s", calendar[i].dayName);
printf("Enter the date for day %d: ", i + 1);
scanf("%s", calendar[i].date);
printf("Enter the activity description for day %d: ", i + 1);
scanf(" %[^\n]s", calendar[i].activity);
}
}
void display(Day *calendar) {
int i;
printf("Weekly Activity Report:\n");
for (i = 0; i < 7; i++) {
printf("Day %d:\n", i + 1);
printf("Day Name: %s\n", calendar[i].dayName);
printf("Date: %s\n", calendar[i].date);
printf("Activity: %s\n", calendar[i].activity);
printf("\n");
}
}
int main() {
Day *calendar;
int i;
MALLOC(calendar,7,Day);
create(calendar);
read(calendar);
display(calendar);
for (i = 0; i < 7; i++) {
free(calendar[i].dayName);
free(calendar[i].activity);
free(calendar[i].date);
}
return 0;
}