#include <UTFT.h>
UTFT myGLCD(SSD1963_480,38,39,40,41); //myGLCD(RS,WR,CS,RST,ALE,mode);
// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
byte rgbtable[34][3]{
  {0,0,255},
  {0,32,255},
  {0,64,255},
  {0,96,255},
  {0,128,255},
  {0,160,255},
  {0,192,255},
  {0,224,255},
  {0,255,255},
  {0,255,224},
  {0,255,192},
  {0,255,160},
  {0,255,128},
  {0,255,96},
  {0,255,64},
  {0,255,32},
  {0,255,0},
  {32,255,0},
  {64,255,0},
  {96,255,0},
  {128,255,0},
  {160,255,0},
  {192,255,0},
  {224,255,0},
  {255,255,0},
  {255,224,0},
  {255,192,0},
  {255,160,0},
  {255,128,0},
  {255,96,0},
  {255,64,0},
  {255,32,0},
  {255,0,0}
  };
void setup()
{
  myGLCD.InitLCD();
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(VGA_BLACK);
 
}
//END OF SETUP
//drawColorBar(value 0-32, x coordinate of left of graph, y coordinate of top left corner of graph, size);
void drawColorBar(int value,int spotx, int spoty, int pix){
  for(int i=0;i<33;i++){
    if(i<=value){
    myGLCD.setColor(rgbtable[i][0],rgbtable[i][1],rgbtable[i][2]);
    } else {myGLCD.setColor(VGA_GRAY);}
    myGLCD.fillRect(spotx+(i*pix),spoty,spotx+(i*pix)+pix/2,spoty+18);
  }
 myGLCD.setColor(VGA_BLACK);
 myGLCD.fillRect(spotx+(32*pix)+58,spoty,spotx+(32*pix)+90,spoty+17);
 myGLCD.setColor(rgbtable[value][0],rgbtable[value][1],rgbtable[value][2]);
 myGLCD.print("V: "+String(value)+"",spotx+(32*pix)+10,spoty+4);
}

//LOOP
void loop(){
  //LOOP DO
  myGLCD.setFont(BigFont);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.print("ARDUINO COLOR BAR COLD-HOT",0,0);
      myGLCD.setColor(VGA_YELLOW);
      myGLCD.print("FREE CODE AVAILABLE!",0,16);
  for(int i=0; i<33; i++){
      drawColorBar(i,0,35,3);
      drawColorBar(i,0,65,4);
      drawColorBar(i,0,95,5);

      drawColorBar(i,0,125,6);
      drawColorBar(i,0,155,7);
      drawColorBar(i,0,185,8);
      drawColorBar(i,0,215,9);
      drawColorBar(i,0,245,10);
      delay(1);
}
myGLCD.setColor(VGA_RED);
myGLCD.print("SUBSCRIBE FOR MORE! ",0,16);
for(int i=32; i>=0; i--){
      drawColorBar(i,0,35,3);
      drawColorBar(i,0,65,4);
      drawColorBar(i,0,95,5);

      drawColorBar(i,0,125,6);
      drawColorBar(i,0,155,7);
      drawColorBar(i,0,185,8);
      drawColorBar(i,0,215,9);
      drawColorBar(i,0,245,10);
      delay(1);
}
}
