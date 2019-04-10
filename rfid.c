#include<wiringPi.h>
#include <wiringSerial.h>
#include<stdio.h>
#include <string.h>
  int sp ;
  int count1=0,count2=0,count3=0;
  char ch;
  char rfid[13] ;
  int i=0;

  char temp[5];

void serialbegin(int baud)
  {
    if ((sp = serialOpen ("/dev/ttyS0",baud)) < 0)
   	{
     		printf("Unable to open serial port\n");
   	}
  }

void setup()
{
   if (wiringPiSetup () == -1)
   {
     printf("Unable to start"); 
     printf("wiringPi\n");
   }
  serialbegin(9600); 
}

void get_card()
{
   rfid[i]=' ';
   i=0;
   while(i<12)
   {
       while(serialDataAvail (sp))
       {
        ch= serialGetchar(sp);
        rfid[i]=ch;
	//printf("%s",rfid);
        fflush (stdout) ;
        i++;
       }
   }
   rfid[i]='\0';
	//printf("%s\n",rfid);
   return;
}
int main()
{
   setup();
   printf("rfidreading");
   printf("using RPI \n");
   delay(2000);
   while(1)
  {
        printf("Place Your Card:\n");
        get_card();
        printf("%s \n",rfid);
        delay(500);
}

}
