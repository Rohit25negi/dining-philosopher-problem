#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
//process queue
struct philo
 {int num;
 struct philo *next;
 };

struct philo *head=NULL;
int ph[]={1,1,1,1,1};

int stick[]={1,1,1,1,1},queued=0; // used as semaphore.variable

int wait(char x)         // insert the process to the queue if nedeed
{ struct philo *p,*pp;
if(stick[(x-48-1)%5]==0||stick[(x-48)%5]==0)
     {
     p=( struct philo *)malloc(sizeof(struct philo));
       p->num=(x-48-1)%5;
       p->next=NULL;

       if(!head) head=p;
       else
       {pp=head;
       while(pp->next)
       pp=pp->next;
       pp->next=p;
       }
 return 1; }
return 0;
}

char signal(char x)                      // pop 1 process from the queue
{struct philo *pp=head,*p=NULL;
ph[(x-48-1)%5]=stick[(x-48-1)%5]=stick[(x-48)%5]=1;
while(pp)
{ if(stick[pp->num]==1&&stick[((pp->num)+1)%5]==1)
   {if(!p)head=head->next;
   else p->next=pp->next;
   return (pp->num)+49;
   }
   if(p==NULL){p=pp;}
   else p->next=pp;
   pp=pp->next;
   }
return ' ';
}

void entry()                                // big bang
{ int i;
gotoxy(35,20);

 delay(10);
 textcolor(15);
 cprintf("System Loading\n");
 gotoxy(5,22);
 textcolor(8);
 for(i=0;i<71;i++)
  cprintf("%c",219);
  printf("\r");
  gotoxy(5,22);
  textcolor(WHITE);
  for(i=0;i<71;i++)
  {cprintf("%c",219); delay(35);}
  textcolor(7);
  }
  void print()          // print the number of process  in the queue
  {struct philo *p;
 p=head;
// printf("hello %d",(head->num)+1);
 while(p)
 {printf("    %d",(p->num)+1);p=p->next;}
 }
  void drawtable(const int *stick)          //dinning table
  { setcolor(GREEN);
  setlinestyle(SOLID_LINE,1,1);
  setfillstyle(SOLID_FILL,GREEN);
  fillellipse(450,250,100,100);
  setfillstyle(SOLID_FILL,BLUE);
  fillellipse(450,250,35,35);

  setcolor(YELLOW);
  setfillstyle(SOLID_FILL,YELLOW);
  fillellipse(450,120,30,30);
   fillellipse(570,200,30,30);
    fillellipse(330,200,30,30);
     fillellipse(380,360,30,30);
      fillellipse(520,360,30,30);


  setlinestyle(SOLID_LINE,1,1+(!stick[0])*2);
setcolor(RED);  line(400,165,435,215);
   setlinestyle(SOLID_LINE,1,1+(!stick[1])*2);
setcolor(RED);  line(510,170,472,218);
  setlinestyle(SOLID_LINE,1,1+(!stick[2])*2);
setcolor(RED);  line(540,300,490,260);
  setlinestyle(SOLID_LINE,1,1+(!stick[4])*2);
setcolor(RED);  line(361,295,415,265);
  setlinestyle(SOLID_LINE,1,1+(!stick[3])*2);
setcolor(RED);  line(450,290,450,350);

  }
 void main()
{int gd=DETECT,gm,i,p=0,d=0;
  char ch;

  clrscr();
  entry();
  clrscr();

  initgraph(&gd,&gm,"C:\\turboc3\\BGI");
   drawtable(stick);
gotoxy(54,6);
printf("1");
gotoxy(38,12);
printf("5");
gotoxy(76,12);
printf("2");
gotoxy(68,25);
printf("3");
gotoxy(45,25);
printf("4");
gotoxy(1,1);
  printf("     process 1 process 2 process 3 process 4 process 5\n");
  do
  { drawtable(stick);printf("       ");
   for(i=0;i<5;i++)
       if(ph[i]==1)printf("    off   ");
       else printf("    on   ");

       printf("\n\nQUEUE: ");
  if(p==0||d==1)
  {fflush(stdin); ch=getch();}
   if(ch>='1'&&ch<='5')
   {if(ph[(ch-48-1)%5]==1)
    {queued=wait(ch);
	    d=1;
     if(!queued)
     { ph[(ch-48-1)%5]=stick[(ch-48-1)%5]=stick[(ch-48)%5]=0;   }

     }
     else
     {ch=signal(ch);
      if(ch!=' '){p=1;d=0;}
      else {p=0;d=1;}
     }


   }

  print();
  printf("         ");
   gotoxy(1,2);
   }while(ch>='1'&&ch<='5'||ch==' ');

  getch();
  }
