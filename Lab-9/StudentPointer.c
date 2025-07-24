#include<stdio.h>
struct Student {
  int roll_no;
  char name[50];
  char branch[20];
  char batch[10];
};
void main() {
  struct Student s1;
  struct Student *ptr;
  ptr = &s1;
  printf("Enter roll_no,name,branch,batch:");
  scanf("%d %s %s %s",&ptr->roll_no,&ptr->name,&ptr->branch,&ptr->batch);
  printf("roll_no=%d\nname=%s\nbranch=%s\nbatch=%s",ptr->roll_no,ptr->name,ptr->branch,ptr->batch);
}