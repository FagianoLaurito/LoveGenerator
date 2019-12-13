/****************************************************************
Intruction:

- Connect the LoveGenerator to a usb port
- Select Arduino UNO from Tools/Board menu
- Select the USB port
- Program it!

- Press the reset button for more love

****************************************************************/


#include "SparkFun_LED_8x7.h"
#include "Chaplex.h"

// Global variables
byte led_pins[] = {10, 11, 7, 6, 5, 4, 3, 2}; 

const byte bitmap_1[] = {0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_2[] = {0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_3[] = {0, 0, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_4[] = {0, 1, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_5[] = {0, 1, 1, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_6[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_7[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 0, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_8[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_9[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_10[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 1, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_11[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 1, 0, 0,
                         0, 0, 0, 0, 1, 0, 0, 0,
                         0, 0, 0, 0, 0, 0, 0, 0,
                         };

const byte bitmap_12[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 1, 0, 0,
                         0, 0, 0, 0, 1, 0, 0, 0,
                         0, 0, 0, 1, 0, 0, 0, 0};

const byte bitmap_13[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 1, 0, 0,
                         0, 0, 0, 0, 1, 0, 0, 0,
                         0, 0, 1, 1, 0, 0, 0, 0};

const byte bitmap_14[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 1, 0, 0,
                         0, 0, 0, 0, 1, 0, 0, 0,
                         0, 1, 1, 1, 0, 0, 0, 0};

const byte bitmap_15[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         0, 0, 0, 0, 0, 1, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         0, 1, 1, 1, 0, 0, 0, 0};

const byte bitmap_16[] = {0, 1, 1, 1, 0, 0, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         0, 1, 0, 0, 0, 0, 1, 0,
                         1, 0, 0, 0, 0, 1, 0, 0,
                         1, 0, 0, 0, 1, 0, 0, 0,
                         0, 1, 1, 1, 0, 0, 0, 0};

                                            
void setup() {
  
  // Initialize and clear display
  Plex.init(led_pins);
  Plex.clear();
  Plex.display();
}

#define DELAY 50

void loop() {

  Plex.drawBitmap(bitmap_1);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_2);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_3);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_4);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_5);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_6);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_7);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_8);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_9);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_10);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_11);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_12);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_13);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_14);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_15);
  Plex.display();
  delay(DELAY);
  Plex.drawBitmap(bitmap_16);
  Plex.display();
  delay(DELAY);

  Plex.clear();
  Plex.display();
  delay(DELAY * 5);

  Plex.drawBitmap(bitmap_16);
  Plex.display();
  delay(2000);
  
  Plex.clear();
  Plex.display();
  Plex.display();

  while(1);
}
