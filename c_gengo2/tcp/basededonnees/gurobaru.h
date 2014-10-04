 /* in this file , their are 3 tables  */
#ifndef INCLUDED_DATE
#define INCLUDED_DATE
 
 /* table1*/
struct cordonnees{
  int id;
  char name[10];
  };

 struct cordonnees table1[2]={
  {1,"ji"},
  {2,"hi"}};

 struct cordonnees *p1;
 int fd,i,j=0,k=0,choice,count=0,cuserid; /* file descriptor to userdata.c, , , k for keep current user id , choice variable for switch syntax, to limit tray to login (count variable) , cuserid for memorise current user */
 
 /* table2*/
 struct score{
  int math;
  int eng;
  };

 struct score table2[2]={
  {1,2},
  {3,4}};
 /* table3*/
 struct kojin{
  char address[50];
  int  age;
  };

 struct kojin table3[2]={
  {"kobe",1},
  {"osaka",2}}; 
#endif



