#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
  //pass 1 initial
    FILE *f1,*f2,*f3,*f4,*f5;
    int lc,sa,l,o,lan,n=0,f,t=0;
    char opnd[20],la[20],op[20],otp[20],op1[10],adress[10],last_add[10],st_add[10];
    char *hexstr;
    unsigned long locctr=0;
    const int base =16;
    //pass 1 start
   printf("ADDRESS\tLABEL\tOPCODE\tOPERAND\n\n");
  f1=fopen("INPUT.DAT","r");
  f3=fopen("SYMTABLE.DAT","w");
  f5=fopen("INTERMED.DAT","w");
  fscanf(f1,"%s %s %s",la,opnd,op1);

   for(hexstr=op1;*hexstr!='\0';hexstr++)
   {
       lgth++;
   }
    hexstr = op1;
        for (i = 0; *hexstr != '\0' && i < lgth; i++, hexstr++)
        {
        // Compare *hexstr with ASCII values
            if(*hexstr>=48 && *hexstr<=57)   // is *hexstr Between 0-9
                locctr+=(((int)(*hexstr)) -48)*pow(base, lgth - i - 1);
            else if((*hexstr>=65&&*hexstr<=70))   // is *hexstr Between A-F
                locctr += (((int)(*hexstr)) - 55) * pow(base, lgth - i - 1);
            else if (*hexstr >= 97 && *hexstr <= 102)   // is *hexstr Between a-f
                locctr += (((int)(*hexstr)) - 87) * pow(base, lgth - i - 1);
            else
                printf(" Invalid Hexadecimal Number \n");
        }
        lc=locctr;
     if(strcmp(opnd,"START")==0)
     {
          sa=lc;
         printf("\t%s\t%s\t%s\n",la,opnd,op1);
         fprintf(f5,"\t%s\t%s\t%s\n",la,opnd,op1);
      }
    else
         lc=0;
  fscanf(f1,"%s %s",la,opnd);
 while(!feof(f1))
  {
       fscanf(f1,"%s",op);
       printf("\n%X\t%s\t%s\t%s\n",lc,la,opnd,op);
       fprintf(f5,"\n%X\t%s\t%s\t%s\n",lc,la,opnd,op);
       if(strcmp(la,"**")!=0)
         {
                  fprintf(f3,"\n%s\t%X\n",la,lc);
         }
    if(strcmp(opnd,"WORD")==0)
      {
           lc=lc+3;
           t++;
      }
    else if(strcmp(opnd,"RESW")==0)
      {
       f=atoi(op);
       lc=lc+(3*f);
      }
    else if(strcmp(opnd,"BYTE")==0)
      {
          if(op[0]=='X')
          {
                 lc=lc+1;
                 t++;
          }
          else
             {
                   lan=strlen(op)-3;
                   lc=lc+lan;
                    t++;
             }

      }
    else if(strcmp(opnd,"RESB")==0)
     {
         f=atoi(op);
          lc=lc+f;
     }
    else
     {
       f2=fopen("OPTAB.DAT","r");
       fscanf(f2,"%s %d",otp,&o);
       while(!feof(f2))
          {
              if(strcmp(opnd,otp)==0)
                {
                        lc=lc+3;
                        t++;
                        break;
                }
              fscanf(f2,"%s %d",otp,&o);
           }


        fclose(f2);
      }
    fscanf(f1,"%s%s",la,opnd);
  }
    if(strcmp(opnd,"END")==0)
      {
        printf("TOTAL LENGTH =%X\n",lc-sa);
      }
    fclose(f1);
    fclose(f3);
    fclose(f5);
}
