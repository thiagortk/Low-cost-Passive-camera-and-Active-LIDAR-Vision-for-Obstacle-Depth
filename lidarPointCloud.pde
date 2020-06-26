import processing.serial.*;

float pcolor = 0;  // point color value
float xVal = 0; // x value
float yVal = 0; // y value

Serial myPort;

void setup(){
  size(400, 200);
  
  // List all the available serial ports
  println(Serial.list());
  // 
  //
  //
  myPort = new Serial(this, Serial.list()[0], 57600);
  //
  myPort.bufferUntil('\n');
  background(0);
}

void  draw(){
  //
  stroke(pcolor);
  point(xVal,yVal);
  saveFrame("teste.png");
}

void serialEvent(Serial myPort){
  // get the ASCII string
  String inString = myPort.readStringUntil('\n');
  
  if(inString != null){
    // trim off any whitespace
    inString = trim(inString);
    // split the string on the commas and convert the
    // resulting substrings into an integer array
    float[] colors = float(split(inString, ","));
    // if the array has at least three elements, you know
    // you got the whole thing. Put the numbers in the
    // color variables
    if(colors.length >=3) {
       // map them to the range 0-255
       xVal = colors[0];
       yVal = colors[1];
       pcolor = map(colors[2], 0, 400, 255, 0);
    }
  }
}
