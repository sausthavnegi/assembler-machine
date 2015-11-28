#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
//pass 2 initial
    char a[10],ad[10],label[10],opcode[10],operand[10],symbol[10],ch,mnemonics[10],m_code[10],add[10];
    int i,len,length,lgth=0;
    FILE *f6,*f7;
f3=fopen("SYMTABLE.DAT","r");
  f5=fopen("INTERMED.DAT","r");
  f6=fopen("ASSMLIST.DAT","w");
  f7=fopen("OBJCODE.DAT","w");
  fscanf(f5,"%s%s%s",label,opcode,operand);

  if(strcmp(opcode,"START")==0)
  {
     fprintf(f7,"H^%s^00%s^00%X\n",label,operand,(lc-sa+1));
     fprintf(f7,"T^00%X^00%d",sa,(t*3));
      fprintf(f6,"\t%s\t%s\t%s\n",label,opcode,operand);
  }
  fscanf(f5,"%s%s%s%s",adress,label,opcode,operand);

    while(strcmp(opcode,"END")!=0)
         {
          if(strcmp(opcode,"WORD")==0)
            {
                len=strlen(operand);
                itoa(atoi(operand),a,10);
                fprintf(f6,"%s\t%s\t%s\t%s\t00000%s\n",adress,label,opcode,operand,a);
                fprintf(f7,"^00000%s",a);

            }

          else if(strcmp(opcode,"BYTE")==0)
           {
               fprintf(f6,"%s\t%s\t%s\t%s\t",adress,label,opcode,operand);

                if(operand[0]=='C')
                {
                len=strlen(operand);
                length=len-3;
                fprintf(f7,"^");
                for(i=2;i<(length+2);i++)
                  {
                    itoa(operand[i],ad,16);
                    fprintf(f6,"%s",ad);
                    fprintf(f7,"%s",ad);
                  }
                }
                else
                {
                       fprintf(f6,"00%s",operand);
                       fprintf(f7,"^");
                       fprintf(f7,"00%s",operand);

                }
                fprintf(f6,"\n");
              }
       else if((strcmp(opcode,"RESB")==0)||(strcmp(opcode,"RESW")==0))
          {
                   fprintf(f6,"%s\t%s\t%s\t%s\n",adress,label,opcode,operand);
          }

         else
            {
               f2=fopen("OPTAB.DAT","r");
               fscanf(f2,"%s%s",mnemonics,m_code);
               while(strcmp(opcode,mnemonics)!=0)
                 {
                     fscanf(f2,"%s%s",mnemonics,m_code);
                 }
               if(strcmp(operand,"COPY")==0)
                   fprintf(f6,"%s\t%s\t%s\t%s\t%s0000\n",adress,label,opcode,operand,m_code);
               else
                 {
                   rewind(f3);
                   fscanf(f3,"%s%s",symbol,&add);
                   while(strcmp(operand,symbol)!=0)
                    {
                       fscanf(f3,"%s%s",symbol,&add);
                    }

                   fprintf(f6,"%s\t%s\t%s\t%s\t%s%s\n",adress,label,opcode,operand,m_code,add);
                   fprintf(f7,"^%s%s",m_code,add);
                 }
            }
   fclose(f2);
   fscanf(f5,"%s%s%s%s",adress,label,opcode,operand);
  }
  fprintf(f6,"%s\t%s\t%s\t%s\n",adress,label,opcode,operand);
   fprintf(f7,"\nE^00%X\n",sa);
  printf(" \n\nINPUT PROGRAM INTO OBJECT CODE\n");
   printf("----------------------------------------\n");

  printf("\nSYMBOL TABLE :-\n");
    f3=fopen("SYMTABLE.DAT","r");
    ch=fgetc(f3);
    while(ch!=EOF)
      {
          printf("%c",ch);
          ch=fgetc(f3);
      }
  fclose(f6);
 printf("\nASSEMBLED PROGRAM :-\n");
   f6=fopen("ASSMLIST.DAT","r");
   ch=fgetc(f6);
   while(ch!=EOF)
     {
         printf("%c",ch);
         ch=fgetc(f6);
     }
  fclose(f7);
  printf("\nOBJECT CODE :-\n");
  f7=fopen("OBJCODE.DAT","r");
  ch=fgetc(f7);
  while(ch!=EOF)
     {
       printf("%c",ch);
      ch=fgetc(f7);
     }
   fclose(f7);

}
