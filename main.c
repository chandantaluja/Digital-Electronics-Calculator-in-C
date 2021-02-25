#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/**********************************Defining the global variables*************************************/
int input_number;
/***********************************Defining global variables end here ******************************/


/**********************************Defining the functions*************************************/
    void menu_display();

    //case 1
    void BinToDec();
    void OctalToDec();
    void HexaToDec();
    void DecToBin();
    void DecToOctal();
    void DecToHex();

    //case 2
    void onescomplement();
    void twoscomplement();

    //case 3
    void BinToGray();
    void GrayToBin();
    int bintogray(int);

    //case 4
    void printANDtable();
    void printORtable();
    void printNOTtable();




/***********************************Defining the functions end here ******************************/




int main ()

{
    /**********************************Defining the local variables*************************************/
    int ch , choice, choic;
    char next_action = ' ';

    /***********************************Defining local variables end here ******************************/

    menu_display();
    scanf("%d", &ch);

    switch (ch)
    {

    case 1:
        system("cls");
        printf("\n\n/****************************Base Conversion*********************************/\n");
        printf("Enter 1 for Binary to Decimal Conversion\nEnter 2 for Octal to Decimal Conversion\nEnter 3 for Hexadecimal to Decimal Conversion\n");
        printf("Enter 4 for Decimal to Binary Conversion\nEnter 5 for Decimal to Octal Conversion\nEnter 6 for Decimal to Hexadecimal Conversion\n");
        printf("Enter your choice  ");scanf("%d", &choice);
        if (choice == 1) BinToDec();
            else if (choice == 2) OctalToDec();
            else if (choice == 3) HexaToDec();
            else if (choice == 4) DecToBin();
            else if (choice == 5) DecToOctal();
            else if (choice == 6) DecToHex();
        printf("\n\nPress c to continue, q to Quit   ");
        scanf("%s", &next_action);
        if (next_action == 'c'|| next_action == 'C') main ();
        else exit(0);

    case 2:
        system("cls");
        int choice;
        printf("/****************************Complement calculation*********************************\n");
        printf("\n \nEnter which complement you wish to find \nEnter 1 for One's Complement\nEnter 2 for Two's Complement ");
        scanf("%d", &choice);
        if (choice == 1) onescomplement ();
            else if (choice == 2) twoscomplement();
        printf("\n\nPress c to continue, q to Quit   ");
        scanf("%s", &next_action);
        if (next_action == 'c'|| next_action == 'C') main ();
        else exit(0);

    case 3:
        system("cls");
        printf("/****************************Number Manipulation*********************************/\n");
        printf("\n \nEnter 1 for Binary to Gray Conversion\nEnter 2 for Gray to Binary Conversion\n");
        printf("Enter your choice  ");
        scanf("%d", &choice);
            if (choice ==1) BinToGray();
            else if (choice ==2) GrayToBin();
            else printf("Wrong Choice\n");
        printf("\n\nPress c to continue, q to Quit   ");
        scanf("%s", &next_action);
        if (next_action == 'c'|| next_action == 'C') main ();
        else exit(0);




    case 4:
        system("cls");
        printf("/****************************Printing Truth Tables*********************************/\n");
        printf("\n \nEnter 1 to print the truth table of AND Gate\nEnter 2 to print truth table of OR Gate\nEnter 3 to print truth table of NOT\n");
        printf("Enter your choice  ");
        scanf("%d", &choic);
        if (choic==1) printANDtable();
        else if (choic==2) printORtable();
        else if (choic==3) printNOTtable();
        else printf("Wrong Choice");
        printf("\n\nPress c to continue, q to Quit   ");
        scanf("%s", &next_action);
        if (next_action == 'c'|| next_action == 'C') main ();
        else exit(0);

    case 5:
        exit(0);
    }
    return 0;
}

void menu_display()
{
    system("cls");
    printf("***************************************Digital Electronics Calculator***************************\n");
    printf("\t\t\t\t\tCreated by Er. Chandan Taluja\t\t\t\t\t\n");
    printf("\t\t\t\t\temail: chandan.taluja@gmail.com\t\t\t\t\t\n");
    printf("Enter 1 for Base Conversion\n");
    printf("Enter 2 for Complement Calculation\n");
    printf("Enter 3 for Number manipulation \n");
    printf("Enter 4 for Printing Truth tables of Logic Gates\n");
    printf("Enter 5 to exit\n");
    printf("Enter your selection  ");
}

void BinToDec()  //Binary to Decimal
{
    int input_number;
    printf("Enter the Binary number to be converted to Decimal  " );
    scanf("%d", &input_number);
    int dec=0, i=0, rem;
    while(input_number!=0)
    {
       rem = input_number%10;
       input_number=input_number/10;
       dec=dec + rem*pow(2,i);
       ++i;
    }
    printf("The number converted to Decimal is = %d", dec);
}

void OctalToDec() //Octal to Decimal
{
  int input_number,output=0,i,a;
  int b;
  printf("Enter the Octal number "); scanf("%d", &input_number);
  int len =0; int n = input_number;
  while(n>0)
  {
      b=n%10;
      len++;
      n=n/10;
  }
  for(i=0;i<len;i++)
  {
      a=input_number %10;
      output = output + (pow(8,i)*a);
      input_number = input_number/10;
  }
  printf("The number converted into Decimal is = %d\n", output);

}

void HexaToDec() //Hexadecimal to Decimal
{
    char hex[17];
    int decimal;
    int i = 0, val, len;
    decimal = 0;
    printf("Enter the Hexadecimal number  ");
    scanf("%s", &hex);
    len = strlen(hex);
    len--;
    for(i=0; hex[i]!='\0'; i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
    }
    printf("Decimal number = %d", decimal);
}

void DecToBin()
{
    int n,i;int a[10];
    printf("Enter the Decimal number to convert to Binary ");
    scanf("%d",&n);
    for(i=0;n>0;i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    printf("\nBinary of Given Number is=");
    for(i=i-1;i>=0;i--)
        {
        printf("%d",a[i]);
        }
    printf("\n");
}

void DecToOctal()
{

    int decimalNumber;
    printf("Enter the Decimal number to be converted to Octal"); scanf("%d",&decimalNumber);
    int octalNumber = 0, i = 1;
    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    printf("The Octal number is %d",octalNumber);
}

void DecToHex()
{
    int num;
    int i = 0, rem;
    char hex_arr[50];

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while(num != 0)
    {
        rem = num % 16;  // get the right most digit

        if (rem < 10)
        {
            hex_arr[i++] = 48 + rem;
        }
        else
        {
            hex_arr[i++] = 55 + rem;
        }

        num /= 16;  // get the quotient
    }

    printf("0x");

    for(int j = i - 1; j >= 0 ; j--)  // print the hex_arr in reverse order
    {
        printf("%c", hex_arr[j]);
    }
}


void onescomplement()
{
    int n;
    printf("Enter the number of bits do you want to enter : ");
    scanf("%d",&n);
    char binary[n+1];
    char onescomplement[n+1];
    printf("\nEnter the binary number : ");
    scanf("%s", binary);
    printf("%s", binary);
    printf("\nThe ones complement of the binary number is : ");
    for(int i=0;i<n;i++)
    {
       if(binary[i]=='0')
       onescomplement[i]='1';
       else if(binary[i]=='1')
       onescomplement[i]='0';
    }
    onescomplement[n]='\0';
    printf("%s",onescomplement);
}
void twoscomplement()
{
    int n;
   printf("Enter the number of bits do you want to enter :");
   scanf("%d",&n);
   char binary[n+1];
   char onescomplement[n+1];
   char twoscomplement[n+1];
   int carry=1;
   printf("\nEnter the binary number : ");
   scanf("%s", binary);
   printf("%s", binary);
    for(int i=0;i<n;i++)
    {
       if(binary[i]=='0')
       onescomplement[i]='1';
       else if(binary[i]=='1')
       onescomplement[i]='0';
    }
    onescomplement[n]='\0';
    printf("\nThe twos complement of a binary number is : ");
    for(int i=n-1; i>=0; i--)
    {
        if(onescomplement[i] == '1' && carry == 1)
        {
            twoscomplement[i] = '0';
        }
        else if(onescomplement[i] == '0' && carry == 1)
        {
            twoscomplement[i] = '1';
            carry = 0;
        }
        else
        {
            twoscomplement[i] = onescomplement[i];
        }
    }
    twoscomplement[n]='\0';
    printf("%s",twoscomplement);
}


void BinToGray()
{
    printf("Enter the Binary number to convert to Gray ");scanf("%d", &input_number);

    int a, b, result=0, i=0;
    while(input_number!=0)
    {
        a= input_number%10;
        input_number=input_number/10;
        b=input_number%10;
        if ((a&&!b)||(!a&&b))
        {
            result = result + pow(10,i);
        }
        i++;
    }
    printf("The result in Gray code is %d", result);
}
void GrayToBin()
{
    int bin, gray;

    printf("Enter the  Gray number to be converted into Binary: "); scanf("%d", &bin);
    gray = bintogray(bin);
    printf("The gray code of %d is %d\n", bin, gray);
}

int bintogray(int bin)
{
    int a, b, result = 0, i = 0;
    while (bin != 0)
    {
        a = bin % 10;
        bin = bin / 10;
        b = bin % 10;
        if ((a && !b) || (!a && b))
            {
            result = result + pow(10, i);
        }
        i++;
    }
    return result;
    }

int AND(int a, int b )
{
    if (a==1 && b ==1)
        return 1;
    else
        return 0;
}

int OR(int a, int b)
{
    if (a==1 || b==1)
        return 1;
    else
        return 0;
}

int NOT(int a)
{
    if (a==0) return 1;
    else return 0;
}

void printANDtable()
{
    printf("\n\n");
    printf("***********Truth Table of AND Gate Starts**********\n");
    printf("\t\t0\t0\t%d\n", AND(0,0));
    printf("\t\t0\t1\t%d\n", AND(0,1));
    printf("\t\t1\t0\t%d\n", AND(1,0));
    printf("\t\t1\t1\t%d\n", AND(1,1));
    printf("***********Truth Table of AND Gate Ends here*******");
}

void printORtable()
{
    printf("\n\n");
    printf("***********Truth Table of OR Gate Starts**********\n");
    printf("\t\t0\t0\t%d\n", OR(0,0));
    printf("\t\t0\t1\t%d\n", OR(0,1));
    printf("\t\t1\t0\t%d\n", OR(1,0));
    printf("\t\t1\t1\t%d\n", OR(1,1));
    printf("***********Truth Table of OR Gate Ends here*******");

}

void printNOTtable()
{
    printf("\n\n");
    printf("***********Truth Table of NOT Gate Starts**********\n");
    printf("\t\t0\t%d\n", NOT(0));
    printf("\t\t0\t%d\n", NOT(1));
    printf("***********Truth Table of NOT Gate Ends here*******");
}
