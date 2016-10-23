#include <MicroView.h>

int inPin = 2;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status
int lastVal = 0;
int pushCount = 0;

void setup()
{
	uView.begin();		// init and start MicroView
	uView.clear(PAGE);	// erase the memory buffer, when next uView.display() is called, the OLED will be cleared.
	pinMode(inPin, INPUT);    // declare pushbutton as input
}

void loop()
{
	uView.setFontType(1); 		// set font type 1
	uView.setCursor(11,0);		// points cursor to x=11 y=0
	uView.print("Hello");
	uView.setCursor(11,16);		// points cursor to x=11 y=16
	//uView.print("World");

  	val = digitalRead(inPin);  // read input value
  	if (val != lastVal) {         // check if the input has changed
  		lastVal = val;
  		
  		if (lastVal) {
  			pushCount += 1;
    		uView.print(pushCount);
  		}
  		
  	}

	uView.display();
	//delay(100);
}
