#include <LedControl.h>
#include <CapacitiveSensor.h>

// Number of MAX7219 devices connected
const int NUM_DEVICES = 2; 

// Pins connected to the MAX7219 for each device
const int DIN_PIN = 2;  // Data In pin
const int CS_PIN = 3;   // Chip Select pin
const int CLK_PIN = 4;  // Clock pin


LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, NUM_DEVICES);


//Byte Array for Display
byte dash[8]= 
{
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

// Normal X
byte normal[8] = 
{ 
  B11000011,
  B01100110,
  B00111100,
  B00011000,
  B00111100,
  B01100110,
  B11000011,
  B00000000
};

// ^_^
byte happy[8] =
{
  B00000000,
  B00011000,
  B00011000,
  B00111100,
  B00100100,
  B01100110,
  B01000010,
  B11000011
};

// =_=
byte equal[8] =
{
  B00000000,
  B11111111,
  B11111111,
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000000
};

// ?_?
byte question[8] =
{
  B00111100,
  B01111110,
  B01100110,
  B00000110,
  B00011100,
  B00011000,
  B00000000,
  B00011000
};

// !_!
byte exclamation[8] = 
{
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B00011000,
  B00011000
};

// O_O
byte O[8] = 
{
  B00111100,
  B01000010,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B01000010,
  B00111100
};

// ¬_¬
byte negation[8] = 
{
  B00000000,
  B00000000,
  B11111111,
  B11111111,
  B00000011,
  B00000011,
  B00000000,
  B00000000
};

// T_T
byte t[8] =
{
  B11111111,
  B11111111,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

// Z_Z
byte z[8] = 
{
  B11111111,
  B11111111,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01111111,
  B11111111
};

// <3
byte heart[8] =
{
  B00000000,
  B01100110,
  B10011001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
};

byte heart2[8] =
{
  B00000000,
  B01100110,
  B11111111,
  B11011011,
  B11000011,
  B01100110,
  B00111100,
  B00011000
};

byte heart3[8] =
{
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000
};


void setup() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    lc.shutdown(device, false);       
    lc.setIntensity(device, 15);       
    lc.clearDisplay(device);          
  }
}

void loop() {
  //Main Loop.
}

// Function to clear the display 
void clearDisplay() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    lc.clearDisplay(device);
  }
}

// Function for Selecting the Animation
void DisplayPattern(x){
  switch (x)
  {
  case 1:
    displayNormal();
    break;
  case 2:
    displayHappy();
    break;
  case 3:
    displayEqual();
    break;
  case 4:
    displayQuestion();
    break;
  case 5:
    displayExclamation();
    break;
  case 6:
    displayO();
    break;
  case 7:
    displayNegation();
    break;
  case 8:
    displayT();
    break;
  case 9:
    displayZ();
    break;
  case 1:
    displayHeart();
    delay(1000);
    displayHeart2();
    delay(1000);
    displayHeart3();
    delay(1000);
    displayHeart2();
    delay(1000);
    break;
  default:
    break;
  }
}

//Functions to Display Patterns
void displayDash() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, dash[row]);
    }
  }
}

void displayNormal() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, normal[row]);
    }
  }
}

void displayHappy() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, happy[row]);
    }
  }
}

void displayEqual() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, equal[row]);
    }
  }
}

void displayQuestion() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, question[row]);
    }
  }
}

void displayExclamation(){
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, exclamation[row]);
    }
  }
}

void displayO() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, O[row]);
    }
  }
}

void displayNegation() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, negation[row]);
    }
  }
}

void displayT() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, t[row]);
    }
  }
}

void displayZ() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, z[row]);
    }
  }
}

void displayHeart() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, heart[row]);
    }
  }
}

void displayHeart2() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, heart2[row]);
    }
  }
}

void displayHeart3() {
  for (int device = 0; device < NUM_DEVICES; device++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(device, row, heart3[row]);
    }
  }
}
