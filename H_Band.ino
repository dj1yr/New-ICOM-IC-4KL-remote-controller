void band_mode(){
    myGLCD.setFont(SmallFont);
//***********read IC-4KL Banddata (3bit)*******************************
    if (automode ==1){
    if ((digitalRead(ic_b)==1)&&(digitalRead(ic_c)==1)&&(digitalRead(ic_d)==0)){band=1;}//160m
    if ((digitalRead(ic_b)==1)&&(digitalRead(ic_c)==0)&&(digitalRead(ic_d)==1)){band=2;}//80m
    if ((digitalRead(ic_b)==1)&&(digitalRead(ic_c)==0)&&(digitalRead(ic_d)==0)){band=3;}//60/40m
    if ((digitalRead(ic_b)==0)&&(digitalRead(ic_c)==1)&&(digitalRead(ic_d)==1)){band=4;}//30m
    if ((digitalRead(ic_b)==0)&&(digitalRead(ic_c)==1)&&(digitalRead(ic_d)==0)){band=5;}//20m
    if ((digitalRead(ic_b)==0)&&(digitalRead(ic_c)==0)&&(digitalRead(ic_d)==1)){band=6;}//17/15m
    if ((digitalRead(ic_b)==0)&&(digitalRead(ic_c)==0)&&(digitalRead(ic_d)==0)){band=7;}//12/10m
    if ((digitalRead(ic_b)==1)&&(digitalRead(ic_c)==1)&&(digitalRead(ic_d)==1)){pwr_on=0;}//no bandata -> Standby
    }
//***********************************************************************************************************************  
//*******************Automatische Bandumschaltung Yaesu BCD kodiert******************************************************
    if (automode ==2){
    a=digitalRead(a_y);
    b=digitalRead(b_y);
    c=digitalRead(d_y);
    d=digitalRead(d_y);
    if ((a==0)&&(b==1)&&(c==1)&&(d==1)){band=1;analogWrite(band_v,255);}//160m-HLLL
    if ((a==1)&&(b==0)&&(c==1)&&(d==1)){band=2;analogWrite(band_v,200);}//80m-LHLL
    if ((a==0)&&(b==0)&&(c==1)&&(d==1)){band=3;analogWrite(band_v,160);}//60-40m-HHLL
    if ((a==1)&&(b==1)&&(c==0)&&(d==1)){band=4;analogWrite(band_v,120);}//30-20m-LLHL
    if ((a==0)&&(b==1)&&(c==0)&&(d==1)){band=5;analogWrite(band_v,80);}//30-20m-HLHL
    if ((a==1)&&(b==0)&&(c==0)&&(d==1)){band=6;analogWrite(band_v,40);}//17-15m-LHHL
    if ((a==0)&&(b==0)&&(c==0)&&(d==1)){band=6;analogWrite(band_v,40);}//17-15m-HHHL
    if ((a==1)&&(b==1)&&(c==1)&&(d==0)){band=7;analogWrite(band_v,0);}//12-10m-LLLH
    if ((a==0)&&(b==1)&&(c==1)&&(d==0)){band=7;analogWrite(band_v,0);}//12-10m-HLLH
    if ((a==1)&&(b==0)&&(c==1)&&(d==0)){pwr_on=0;}//6m-LHLH-> Error -> Standby
    if ((a==1)&&(b==1)&&(c==1)&&(d==1)){pwr_on=0;}//6m-LLLL-> Error -> Standby
    if ((a==0)&&(b==0)&&(c==0)&&(d==0)){pwr_on=0;}//6m-HHHH-> Error -> Standby  
    }
    //*********************************************************************************************************************** 
      
//*****Band select***************
if (band!=band_old){
     
      if (band==7){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (300,240,346,272);}//12/10m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (300,240,346,272);}//12/10m

      if (band==6){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (250,240,296,272);}//17/15m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (250,240,296,272);}//17/15m

      if (band==5){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (200,240,246,272);}//20m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (200,240,246,272);}//20m

      if (band==4){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (150,240,196,272);}//30m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (150,240,196,272);}//30m

      if (band==3){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (100,240,146,272);}//60/40m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (100,240,146,272);}//60/40m

      if (band==2){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (50,240,96,272);}//80m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (50,240,96,272);}//80m

      if (band==1){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (0,240,46,272);}//160m
      else {myGLCD.setColor(105,105,105);myGLCD.fillRect (0,240,46,272);}//160m

      band_old=band;
      if(automode==0){myGLCD.setColor(105,105,105);myGLCD.fillRect (350,240,396,272);myGLCD.setColor(VGA_WHITE);myGLCD.print("Man",360,250);}
      if(automode==1){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (350,240,396,272);myGLCD.setColor(VGA_WHITE);myGLCD.print("Auto",358,242);myGLCD.print("IC4KL",354,257);}
      if(automode==2){myGLCD.setColor(VGA_GREEN);myGLCD.fillRect (350,240,396,272);myGLCD.setColor(VGA_WHITE);myGLCD.print("BCD",365,245);myGLCD.print("Auto",358,255);}

     myGLCD.setColor(VGA_WHITE);  
     myGLCD.print("160",12,250);
     myGLCD.print("80",65,250);
     myGLCD.print("60/40",104,250);
     myGLCD.print("30",167,250);
     myGLCD.print("20",217,250);
     myGLCD.print("17/15",254,250);
     myGLCD.print("12/10",304,250); 
     }
}
