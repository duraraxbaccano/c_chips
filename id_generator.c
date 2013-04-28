#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
  char init;
  int digits[9];
} ID;

int head(char);
const int headnum[] ={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,30,31,33};

int main (){
 const char filename[]="id_table.txt";
 char init='A';
 int counter=10000000,temp,i,hdigit[3];
 ID id;
 FILE *fp;
// printf("\nA=%d ; headnum[A]=%d\n",'A',head('A'));
// printf("\n%c\n",init+1);
// 3~8 free digit
 if((fp=fopen(filename,"w"))==NULL)
 {
  printf("\ncan't open file %s\n",filename);
  exit(0);
 }
 fprintf(fp,"\nopen %s:\n",filename);
 fprintf(fp,"-------------------------------------------\n");
 
 while(init!='[')
 {
  	hdigit[0]=head(init);
  	hdigit[1]=hdigit[0]/10;
  	hdigit[2]=hdigit[0]%10;
  	id.init =init;
  	temp=counter;
  if(temp%10==0)
  {
	fprintf(fp,"\n");
  }
  for(i=7;i>=0;i--)
  {
    //printf("%d\n",temp);
    id.digits[i]=temp%10;
    temp/=10;
  }
  //printf("\ndigits[7]=%d ; temp%10=%d\n",id.digits[7],counter%10);
  id.digits[8]=(hdigit[1]*1+hdigit[2]*9+id.digits[0]*8+id.digits[1]*7+id.digits[2]*6+id.digits[3]*5+id.digits[4]*4+id.digits[5]*3+id.digits[6]*2+id.digits[7]*1)%10;
  id.digits[8]=id.digits[8]==0?0:10-id.digits[8];
  fprintf(fp,"%c%d%d%d%d%d%d%d%d%d  ",id.init,id.digits[0],id.digits[1],id.digits[2],id.digits[3],id.digits[4],id.digits[5],id.digits[6],id.digits[7],id.digits[8]);
  if(counter==29999999)
   { 
    init++;
    counter=10000000;
   }
  else
   {
    counter++;
   }
  }
fprintf(fp,"\n-------------------------------\nfile is finished.\n");
if(fclose(fp)!=0){
 printf("\ncan't close file %s\n",filename);
 exit(0);
}

 return 0;
}
int head(char c)
{
 return headnum[c-65];
}
/*
char[] id(cahr c,int pos,int value)
{
 if(pos!=)
} 
*/
