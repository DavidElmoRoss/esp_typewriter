/**********************************************************************
* Filename    : Typewriter
* Description : Take characters from keyboard and sends them to the screen.
*               You can use ANSI ESCAPE SEQUENCES to clear the screen,
*               position the cursor, and change text and background
*               colouts 
* Auther      : David Elmo Ross
* Modification: 2025/01/11
**********************************************************************/
// INCLUDE SECTION
#include "Arduino.h"                          // include the ARDUINO Library

                                              // platformio.ini must be modified for ANSI

                                              // lib_deps = robtillaart/ANSI@^0.3.2
                                              // monitor_filters = direct

// Function Prototype Section
void clear(void);                             // This function clears the screen and positions
                                              // the cursor at (1,1) top left of screen

// the setup function runs once when you press reset or power the board
void setup() 
{
  // Set baud rate to 9600
   Serial.begin(115200);                      // platformio.ini has monitor_speed = 115200
                                              // make sure both are set to same value
}

// the loop function runs over and over again forever
void loop() 
{
  char input;                                 // make input a char variable
  
  clear();                                    // clear the screen and cursot to top left

  for(;;)                                     // endless loop
   {
      if (Serial.available() > 0)             // if char available then enter if statement
      {
         input = (char)Serial.read();         // input variable gets char of what is read from keyboard
         (char)Serial.write(input);           // write the char value of variable input to screen
      }
  }
}

void clear(void)
{
   printf("\e[2J");                          // escape sequence <ESC> [ 2 J clears the screen
   fflush(stdout);                           // flush the screen output buffer to clear screen
   printf("\e[1;1H");                        // escape sequence to set cursor to top left of screen
   fflush(stdout);                           // flush stdout buffer contents to screen

}