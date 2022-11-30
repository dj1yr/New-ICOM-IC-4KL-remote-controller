void Meter (){

  //**********Meter 1**************
      if (MS1==0){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,0,46,28);digitalWrite(po_sw,LOW);me1_multi=1;}//P-Out
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,0,46,28);digitalWrite(po_sw,HIGH);}//P-Out
      if (MS1==1){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,32,46,60);digitalWrite(temp_sw,HIGH);me1_multi=2;}//Temp
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,32,46,60);digitalWrite(temp_sw,LOW);}//Temp
      if (MS1==2){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,64,46,92);digitalWrite(prol_sw,HIGH);me1_multi=1;}//Prol
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,64,46,92);digitalWrite(prol_sw,LOW);}//Prol    

  //**********Meter 2**************
      if (MS2==0){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,128,46,156);digitalWrite(swr_sw,HIGH);me2_multi=2;}//SWR
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,128,46,156);digitalWrite(swr_sw,LOW);}//SWR
      if (MS2==1){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,160,46,188);digitalWrite(vc_sw,HIGH);me2_multi=1;}//Vc
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,160,46,188);digitalWrite(vc_sw,LOW);}//Vc
      if (MS2==2){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,96,46,124);digitalWrite(swr_sw,LOW);digitalWrite(vc_sw,LOW);me2_multi=1;}//Ic
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,96,46,124);}//Ic
     
    myGLCD.setColor(VGA_WHITE);
    myGLCD.print("Po",17, 8);
    myGLCD.print("Temp",8,40);
    myGLCD.print("Prol",8,73);

    myGLCD.print("Ic",17, 105);
    myGLCD.print("SWR",12, 136);
    myGLCD.print("Vc",17, 169); 
    myGLCD.setColor(VGA_GRAY); 

    //schwarzes Rechteck ME1/ME2 für Anzeigenwechsel
  if (Meter_old = 1){
    myGLCD.setColor(VGA_BLACK);
    myGLCD.fillRect (55,27,480,50);
    myGLCD.fillRect (55,151,480,170);
    myGLCD.setColor(VGA_GRAY);
    myGLCD.setFont(SmallFont);

//----------rf power---------------    
  if (MS1 == 0){
    myGLCD.drawLine(60,31,442,31); //Linie unter Bargraph
    myGLCD.drawLine(60,27,60,30); //1-0
    myGLCD.drawLine(124,27,124,30); //2-100
    myGLCD.drawLine(166,29,166,30); //3
    myGLCD.drawLine(196,29,196,30); //4
    myGLCD.drawLine(226,29,226,30); //5
    myGLCD.drawLine(256,27,256,30); //6-500 
    myGLCD.drawLine(280,29,280,30); //7
    myGLCD.drawLine(302,29,302,30); //8
    myGLCD.drawLine(322,29,322,30); //9
    myGLCD.drawLine(340,29,340,30); //10     
    myGLCD.drawLine(352,27,352,30); //11-1K 
    myGLCD.drawLine(370,29,370,30); //12
    myGLCD.drawLine(390,29,390,30); //13
    myGLCD.drawLine(406,29,406,30); //14
    myGLCD.drawLine(422,29,422,30); //15  
    myGLCD.drawLine(442,27,442,30); //16-1,5KW    
    myGLCD.print("0W",55,35);
    myGLCD.print("100W",110,35);    
    myGLCD.print("500W",242,35);
    myGLCD.print("1KW",341,35);
    myGLCD.print("1.5KW",422,35);}
//-----------------------------------    

//-------------temp------------------    
  if (MS1 == 1){
    myGLCD.setColor(VGA_BLUE);
    myGLCD.drawLine(60,27,304,27); //Linie unter Bargraph
    myGLCD.drawLine(60,31,304,31); //Linie unter Bargraph
    myGLCD.drawLine(60,27,60,30); //1 
    myGLCD.drawLine(304,27,304,30); //2 
    myGLCD.print("COLD",165,35);
    
    myGLCD.setColor(VGA_RED);
    myGLCD.drawLine(309,27,442,27); //Linie unter Bargraph
    myGLCD.drawLine(309,31,442,31); //Linie unter Bargraph
    myGLCD.drawLine(309,27,309,30); //4  
    myGLCD.drawLine(442,27,442,30); //5 
    myGLCD.print("HOT",360,35);}
    myGLCD.setColor(VGA_GRAY);
//-------------------------------------    

//---------protection level------------ 
  if (MS1 == 2){
    myGLCD.drawLine(60,27,290,27); //Linie unter Bargraph
    myGLCD.drawLine(60,31,290,31); //Linie unter Bargraph
    myGLCD.drawLine(60,27,60,30); //1 
    myGLCD.drawLine(290,27,290,30); //2 
    myGLCD.print("SAFE",157,35);

    myGLCD.setColor(255,112,0); //Orange 
    myGLCD.drawLine(295,27,304,27); //Linie unter Bargraph
    myGLCD.drawLine(295,31,304,31); //Linie unter Bargraph
    myGLCD.drawLine(295,27,295,30); //1 
    myGLCD.drawLine(304,27,304,30); //2 
    myGLCD.print("WARNING",272,35);
 
    myGLCD.setColor(VGA_RED);
    myGLCD.drawLine(309,27,442,27); //Linie unter Bargraph
    myGLCD.drawLine(309,31,442,31); //Linie unter Bargraph
    myGLCD.drawLine(309,27,309,30); //4  
    myGLCD.drawLine(442,27,442,30); //5
    myGLCD.print("PROT",365,35);}
    myGLCD.setColor(VGA_GRAY);  

    
    //Beschriftung ME2 Bargraph
   //--------------SWR------------- 
  if (MS2 == 0){
    myGLCD.drawLine(60,151,442,151); //Linie unter Bargraph
    myGLCD.drawLine(60,147,60,150); //erste Teilstrich
    myGLCD.drawLine(113,147,113,150); //zweiter Teilstrich
    myGLCD.drawLine(173,147,173,150); //dritter Teilstrich
    myGLCD.drawLine(243,147,243,150); //vierter Teilstrich      
    myGLCD.drawLine(322,147,322,150); //fünfter Teilstrich    
    myGLCD.drawLine(442,147,442,150); //letzte Teilstrich
    myGLCD.print("1.0",55,155);
    myGLCD.print("1.5",104,155);
    myGLCD.print("2.0",164,155);    
    myGLCD.print("3.0",233,155);    
    myGLCD.print("4.0",312,155);
    myGLCD.print(">10",432,155);}
//------------------------------------

//-------------voltage----------------
  if (MS2 == 1){
    myGLCD.drawLine(60,151,442,151); //Linie unter Bargraph
    myGLCD.drawLine(60,147,60,150); //erste Teilstrich
    myGLCD.drawLine(113,147,113,150); //zweiter Teilstrich
    myGLCD.drawLine(173,147,173,150); //dritter Teilstrich
    myGLCD.drawLine(243,147,243,150); //vierter Teilstrich      
    myGLCD.drawLine(322,147,322,150); //fünfter Teilstrich    
    myGLCD.drawLine(442,147,442,150); //letzte Teilstrich
    myGLCD.print("0V",55,155);
    myGLCD.print("10V",104,155);
    myGLCD.print("20V",164,155);    
    myGLCD.print("30V",233,155);    
    myGLCD.print("40V",312,155);
    myGLCD.print("50V",432,155);}
//------------------------------------

//-----------current------------------
  if (MS2 == 2){
    myGLCD.drawLine(60,151,442,151); //Linie unter Bargraph
    myGLCD.drawLine(60,147,60,150); //erste Teilstrich
    myGLCD.drawLine(113,147,113,150); //zweiter Teilstrich
    myGLCD.drawLine(173,147,173,150); //dritter Teilstrich
    myGLCD.drawLine(243,147,243,150); //vierter Teilstrich      
    myGLCD.drawLine(322,147,322,150); //fünfter Teilstrich    
    myGLCD.drawLine(442,147,442,150); //letzte Teilstrich
    myGLCD.print("0A",55,155);
    myGLCD.print("10A",104,155);
    myGLCD.print("20A",164,155);    
    myGLCD.print("30A",233,155);    
    myGLCD.print("40A",312,155);
    myGLCD.print("60A",432,155);}

    Meter_old=0;
    }
        
}
