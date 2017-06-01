/*
  Keypad 4x4 Read Multiple Keys.c
  Demonstrates how to read individual key presses 
  with the keypad library.  
*/  

#include "simpletools.h"
#include "keypad.h"

// Always list row connections from top to bottom.
int rows[4] = {7,   6,  5,  4};

// Always list column connections from left to right
int cols[4] = {3,   2,  1,  0};

// List the values you want the keypad library to
// return when a given keyp is pressed.  This should
// match the layout of the keypad.  You could optionally
// substitute 10 for A, 11 for B, etc.
int values[16] = {  1,   2,    3,  'A',
                    4,   5,    6,  'B',
                    7,   8,    9,  'C',
                  '*',   0,  '#',  'D' };

int main()
{
  // Call keypad setup passing these parameters:
  // number of rows, number of columns, pointer to
  // the rows array, pointer to the cols array,
  // pointer to the values array.
  keypad_setup(4, 4, rows, cols, values);
  
  while(1)
  {
    // Call keypad read.  Returns the first key that
    // it finds to be pressed.
    int key = keypad_read();
    // If you have a mixture of values and ASCII,
    // make sure to make the distinction.  If you end up
    // changing 'A' to 10, 'B' to 11, and so on, make sure
    // to change if(key <= 9) to if(key <= 13).
    if(key <= 9)
      print("key = %d\r", key);
    else
      print("key = %c\r", key);
    pause(1500);
  }  
}