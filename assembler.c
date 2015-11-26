#assembler-machine
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
  //pass 1 initial
    FILE *f1,*f2,*f3,*f4,*f5;
    int lc,sa,l,op1,o,lan,n=0;
    char opnd[20],la[20],op[20],otp[20];
  
  //pass 1 start

  f1=fopen("INPUT.DAT","r");
  f3=fopen("SYMTABLE.DAT","w");
  f5=fopen("INTERMED.DAT","w");
  fscanf(f1,"%s %s %d",la,opnd,&op1);
   printf(" INPUT PROGRAM INTO OBJECT CODE\n");
   printf("----------------------------------------\n");
     if(strcmp(opnd,"START")==0)
     {
         sa=op1;
         lc=sa;

         printf("address\tlabel\topcode\toperand\n\n");
         printf("\t%s\t%s\t%d\n",la,opnd,op1);
         fprintf(f5,"\t%s\t%s\t%d\n",la,opnd,op1);
      }
    else
         lc=0;
  fscanf(f1,"%s %s",la,opnd);
 while(!feof(f1))
  {
       fscanf(f1,"%s",op);
       printf("\n%d\t%s\t%s\t%s\n",lc,la,opnd,op);
       fprintf(f5,"\n%d\t%s\t%s\t%s\n",lc,la,opnd,op);
       if(strcmp(la,"**")!=0)
         {
                  fprintf(f3,"\n%d\t%s\n",lc,la);
         }


    if(strcmp(opnd,"WORD")==0)
      {
           lc=lc+3;
      }
    else if(strcmp(opnd,"RESW")==0)
      {
       op1=atoi(op);
       lc=lc+(3*op1);
      }
    else if(strcmp(opnd,"BYTE")==0)
      {
          if(op[0]=='X')
                lc=lc+1;
          else
             {
                   lan=strlen(op)-2;
                   lc=lc+lan;
             }
      }
    else if(strcmp(opnd,"RESB")==0)
     {
         op1=atoi(op);
          lc=lc+op1;
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
        printf("TOTAL LENGTH =%d\n",lc-sa);
      }
    fclose(f1);
    fclose(f3);
    fclose(f5);
