#include "simpletools.h"
#include "serial.h"
#include "fdserial.h"

serial *msgOut;
serial *msgIn;

char s[10];

volatile int val;

int c;

void sendVals();
void receiveVals();

int main()
{
  cog_run(sendVals, 256);
  cog_run(receiveVals, 256);
  val = 0;
  while(1)
  {
    print("val = %d\r", val);
    pause(500);
  }    
}

void receiveVals()
{
  msgIn = serial_open(3, 2, 0, 9600);
  pause(100);
  while(1)
  {
    //dscan(msgIn, "%d", &val);
    val = readDec(msgIn);
    pause(10);
  }
}  

void sendVals()
{
  msgOut = serial_open(4, 3, 0, 9600);
  int t = CNT;
  int dt = CLKFREQ/10;
  int n = 0;
  while(1)
  {
    waitcnt(t += dt);
    writeDec(msgOut, n);
    writeChar(msgOut, '\r');
    n++;
    //writeChar(msgOut, '\n');
    //writeChar(msgOut, ' ');
  }
}      