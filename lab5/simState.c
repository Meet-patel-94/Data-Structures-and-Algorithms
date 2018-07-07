#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STATES 8

typedef struct state_machine{
char name[1];
struct state_machine *next0;
struct state_machine *next1;

}state;
typedef struct tree 
{
    char tree_name [20];
    struct tree* next;
}tree;

char garbage[MAX_STATES];
char deleted[]={"00000000"};
int i;
state fsm[MAX_STATES];

void initialize_states(state a[]){//#########################################################################   INITIALIZER
strcpy (a[0].name, "A");
strcpy (a[1].name, "B");
strcpy (a[2].name, "C");
strcpy (a[3].name, "D");
strcpy (a[4].name, "E");
strcpy (a[5].name, "F");
strcpy (a[6].name, "G");
strcpy (a[7].name, "H");
a[0].next0=&a[7];
a[0].next1=&a[1];
a[1].next0=&a[6];
a[1].next1=&a[3];
a[2].next0=&a[4];
a[2].next1=&a[6];
a[3].next0=&a[0];
a[3].next1=&a[2];
a[4].next0=&a[4];
a[4].next1=&a[5];
a[5].next0=&a[3];
a[5].next1=&a[0];
a[6].next0=&a[2];
a[6].next1=&a[7];
a[7].next0=&a[1];
a[7].next1=&a[4];};

void print_states(state s[]){//#########################################################################   STATE PRINTER
int i=0;
char end[]="x";
state *start,*p0,*p1;
while(i<8){
start = &s[i];
p0=&s[i];
p1=&s[i];  
if((strcmp(p0->name,end))){
printf("%s  ", p0 -> name);
p0= p0 -> next0;
printf("%s  ", p0 -> name);
p1= p1 -> next1;
printf("%s\n", p1 -> name);}
i++;}
}


void change_states (state *current, char in[],state s[]){//#########################################################################  STATE CHANGER
state temp,*p0;
int i=0,j=0,x;
if((strcmp(s[0].name,&in[4])==0)||(strcmp(s[1].name,&in[4])==0)||(strcmp(s[2].name,&in[4])==0)||(strcmp(s[3].name,&in[4])==0)||(strcmp(s[4].name,&in[4])==0)||(strcmp(s[5].name,&in[4])==0)||(strcmp(s[6].name,&in[4])==0)||(strcmp(s[7].name,&in[4])==0)||(strcmp(s[8].name,&in[4])==0)){
for(j=0;j<8;j++){
if((strcmp(current->name,s[j].name)==0))
{x=j;
j=10;}}
for(i=0;i<8;i++){
if((strcmp(&in[4],s[i].name)==0)&&(atoi(&in[2])==1))
{s[x].next1=&s[i];
}else if((strcmp(&in[4],s[i].name)==0)&&(atoi(&in[2])==0)){
s[x].next0=&s[i];}}
}else{
printf("INVALID STATE\n");
}

}


void delete(char in[],state g[],state s[]){//#########################################################################    STATE DELETER
int i=0,j=0,k=5,y=0,t=0,r=1,d=0,z=0;
char end[]="x";
state a[8];
strcpy (a[0].name, "A");
strcpy (a[1].name, "B");
strcpy (a[2].name, "C");
strcpy (a[3].name, "D");
strcpy (a[4].name, "E");
strcpy (a[5].name, "F");
strcpy (a[6].name, "G");
strcpy (a[7].name, "H");

if((strcmp(s[0].name,&in[2])==0)||(strcmp(s[1].name,&in[2])==0)||(strcmp(s[2].name,&in[2])==0)||(strcmp(s[3].name,&in[2])==0)||(strcmp(s[4].name,&in[2])==0)||(strcmp(s[5].name,&in[2])==0)||(strcmp(s[6].name,&in[2])==0)||(strcmp(s[7].name,&in[2])==0)||(strcmp(s[8].name,&in[2])==0))
{


for(i=0;i<8;i++){
if(strcmp(g[i].name,&in[2])==0){
t=5;
z=2;
y=i;}}
if(t==5){
printf("Deleted.\n",s[y].name);
strcpy (s[y].name, "x");
r=0;}
if(z==0){
printf("Not deleted.\n");
r=0;}


}else if((strcmp(a[0].name,&in[2])==0)||(strcmp(a[1].name,&in[2])==0)||(strcmp(a[2].name,&in[2])==0)||(strcmp(a[3].name,&in[2])==0)||(strcmp(a[4].name,&in[2])==0)||(strcmp(a[5].name,&in[2])==0)||(strcmp(a[6].name,&in[2])==0)||(strcmp(a[7].name,&in[2])==0)||(strcmp(a[8].name,&in[2])==0))
{
printf("Not deleted\n");
}
else{
printf("");

if(r==1){
for(i=0;i<8;i++){
for(j=0;j<8;j++){
if(strcmp(g[i].name,s[j].name)==0){
strcpy (s[j].name, "x");
k=0;}}}
if(k==5)
{printf("no States deleted\n");}else{
printf("Deleted:<");
for(j=0;j<8;j++){
if(strcmp(g[j].name,end)){
printf("%s ",g[j]);}
}
printf(">\n");
}
}

}}



void g0(state t[],state g[],state s[]){//#########################################################################        HELPING FUNCTION
char end[]="x";
char *use[100];
int i=0,j=0,k=0,x=0;
state p[8];
for(i=0;i<8;i++){
p[i]=s[i];

}

for(i=0;i<100;i++){
if((strcmp(t[i].name,s[0].name)==0))
	strcpy (p[0].name,"x");
if((strcmp(t[i].name,s[1].name)==0))
	strcpy (p[1].name,"x");
if((strcmp(t[i].name,s[2].name)==0))
	strcpy (p[2].name,"x");
if((strcmp(t[i].name,s[3].name)==0))
	strcpy (p[3].name,"x");
if((strcmp(t[i].name,s[4].name)==0))
	strcpy (p[4].name,"x");
if((strcmp(t[i].name,s[5].name)==0))
	strcpy (p[5].name,"x");
if((strcmp(t[i].name,s[6].name)==0))
	strcpy (p[6].name,"x");
if((strcmp(t[i].name,s[7].name)==0))
	strcpy (p[7].name,"x");
}
for(i=0;i<8;i++){
if(strcmp(p[i].name,end)){
k++;}}
if(k>0){
printf("");
for(i=0;i<8;i++){
if(strcmp(p[i].name,end))
printf("",p[i].name);
g[x]=p[i];
x++;
}

printf("");} else
printf("");}




void garbage_identify (state *current,state TEST[]){//#########################################################################        GARBAGE IDENTIFYER
char end[]="x";
state *p1,*p0;
int i=0,a=0,o=10,l=10,j=0,k=0,s=0,t=0,f=0,g=0;
p1=current;
p0=current;
while(i<100){
if(strcmp(TEST[a].name,end)==0){
strcpy (TEST[a].name,current->name);
t=a;
i=200;
}
a++;
i++;}
while(j<=t){
if(strcmp(TEST[j].name,p0->next0->name)==0){
o=5;
j=101;}
j++;
}

while(k<=t){
if(strcmp(TEST[k].name,p1->next1->name)==0){
l=5;
k=101;}
k++;}

if(o==10){
p0=p0->next0;
garbage_identify(p0,TEST);}
if(l==10){
p1=p1->next1;
garbage_identify(p1,TEST);}}

void gprint(state t[],state g[],state s[]){//#########################################################################        GARBAGE PRINTER
char end[]="x";
char *use[100];
int i=0,j=0,k=0,x=0;
state p[8];
for(i=0;i<8;i++){
p[i]=s[i];

}

for(i=0;i<100;i++){
if((strcmp(t[i].name,s[0].name)==0))
	strcpy (p[0].name,"x");
if((strcmp(t[i].name,s[1].name)==0))
	strcpy (p[1].name,"x");
if((strcmp(t[i].name,s[2].name)==0))
	strcpy (p[2].name,"x");
if((strcmp(t[i].name,s[3].name)==0))
	strcpy (p[3].name,"x");
if((strcmp(t[i].name,s[4].name)==0))
	strcpy (p[4].name,"x");
if((strcmp(t[i].name,s[5].name)==0))
	strcpy (p[5].name,"x");
if((strcmp(t[i].name,s[6].name)==0))
	strcpy (p[6].name,"x");
if((strcmp(t[i].name,s[7].name)==0))
	strcpy (p[7].name,"x");
}
for(i=0;i<8;i++){
if(strcmp(p[i].name,end)){
k++;}}

if(k>0){
printf("\nGarbage: <");
for(i=0;i<8;i++){
if(strcmp(p[i].name,end))
printf("%s ",p[i].name);
g[x]=p[i];
x++;
}

printf(">\n");} else
printf("No Garbage\n");
}

















int main(int argc, char * argv[])//#########################################################################        MAIN 
{
  char input[10];
  state *current =fsm+1;
  state *start,*p0,*p1;
  int i=0,j=0,g=0,o=0;  
  state TEST[100],Gar[8];
  char end[]="x";
  char space[]=" ";

state s[8];
initialize_states(s);
current=&s[0];
printf("%s\n", s[0].name);
while (i< argc) {
char input[10];
gets(input);
switch (input[0]){
case 'c'://######################################################################### CHANGE STATE
change_states(current,input,s);
break;
case 'p'://######################################################################### PRINT STATE
printf("\n");
print_states(s);
printf("\n\t");
break;
case '0'://######################################################################### STATE 0
p0=current;
p0= p0 -> next0;
printf("%s\n\t", p0 -> name);
current=p0;
break;
case '1'://######################################################################### STATE 1
p1=current;
p1= p1 -> next1;
printf("%s\n\t", p1 -> name);
current=p1;
break;
case 'x'://######################################################################### EXIT PROGRAM
exit(0);
break;
case 'd'://######################################################################### DELETE GARBAGE STATES
 for(j=0;j<100;j++){
  strcpy (TEST[j].name, end);
  }
 garbage_identify(current,TEST);
 g0(TEST,Gar,s);
 delete(input,Gar,s);
 for(j=0;j<10;j++){
  strcpy(&input[j],space);}
 char input[10];
 for(j=0;j<8;j++){
  strcpy (Gar[j].name, space);}
break;
case 'g'://######################################################################### IDENTIFY GARBAGE
   for(j=0;j<100;j++){
  strcpy (TEST[j].name, end);
  }
  garbage_identify(current,TEST);
gprint(TEST,Gar,s);
 break;
 case 'r'://######################################################################### RESET
initialize_states(s);
current=&s[2];
printf("%s\n", s[2].name);
break;
default:
printf("---INVALID ARGUMENT---\n");
}
}
}

