#include <MicroView.h>

String name;

void setup()
{
	uView.begin();		// init and start MicroView
	uView.clear(PAGE);	// erase the memory buffer, when next uView.display() is called, the OLED will be cleared.
	Serial.begin(9600);
	uView.setFontType(1); 		// set font type 1
	uView.setCursor(11,0);		// points cursor to x=11 y=0
	uView.print("_");
}

void loop()
{
	

	
	if (Serial.available()) {
    	// read the most recent byte (which will be from 0 to 255):
    	char c = Serial.read();
 		if (c == '0') {
      		uView.clear(PAGE);
      		
      		//print the name
      		uView.setCursor(11,0);		// points cursor to x=11 y=0
			uView.print("Hello");	
			uView.setCursor(11,16);		// points cursor to x=11 y=16
			uView.print(name);
			

			Serial.print(name);
			
      		name = "";  // clear the name string
      		
    	} 
    	else { 
      		name += c; // append the read char from Serial to the name string
    	}

  	}
  	uView.display();
	delay(100);
}
