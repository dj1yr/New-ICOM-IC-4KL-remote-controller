//Touchabfrage
void touch_select(){
    

      //operate -Standby Button Abfrage
        if (((y>=230) && (y<=272)) && ((x>=420) && (x<=480))){

        if(pwr_on==0){
        pwr_on=1;
        digitalWrite(lin,HIGH);}
        else if (pwr_on==1){  
        pwr_on=0;
        digitalWrite(lin,LOW);}        
        touch_press=true;     
        }

        if(pwr_on==1){
        myGLCD.setColor(VGA_GREEN);
        myGLCD.fillRect (433,240,479,272); 
        myGLCD.setColor(VGA_WHITE);
        myGLCD.print("Oper.",440,250);}
        else if(pwr_on==0){
        myGLCD.setColor(VGA_RED);
        myGLCD.fillRect (433,240,479,272);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.print("Stdb.",440,250);}
        


      //Meterauswahl ME1
//aktiviere Power-Out Anzeige
         if (((y>=0) && (y<=28)) && ((x>=0) && (x<=46))){ //power out         
         MS1=0;
         Meter_old=1;
         Meter();
         touch_press=true; 
        }
//aktiviere Temperaturanzeige 
         if (((y>=32) && (y<=60)) && ((x>=0) && (x<=46))){ //temp
         MS1=1;
         Meter_old=1;
         Meter();
         touch_press=true; 
        }
//aktiviere Protectlevelanzeige
         if (((y>=64) && (y<=92)) && ((x>=0) && (x<=46))){ //prol         
         MS1=2;
         Meter_old=1;
         Meter();
         touch_press=true; 
        }
        

      //Meterauswahl ME2
//aktiviere SWR Anzeige
         if (((y>=128) && (y<=156)) && ((x>=0) && (x<=46))){//SWR      
         MS2=0;
         Meter_old=1;
         Meter();
         touch_press=true; 
        }
//aktiviere Vc Anzeige
         if (((y>=160) && (y<=188)) && ((x>=0) && (x<=46))){  //VC
         MS2=1;
         Meter_old=1;
         Meter();
         touch_press=true; 
        }  
  //aktiviere Ic Anzeige                   
         if (((y>=96) && (y<=124)) && ((x>=0) && (x<=46))){ //IC 
         MS2=2;
         Meter_old=1;
         Meter();
         touch_press=true; 
        }
     
//Tuner ON/OFF
        if(((y>=202) && (y<=232)) && ((x>=0) && (x<=46))){  
        if(tune==0){
        digitalWrite(tun,HIGH);          
        tune=1;}
        else if(tune==1){
        digitalWrite(tun,LOW);
        tune=0;}   
        touch_press=true;    
        }

        if (tune==0){
        myGLCD.setColor(VGA_RED);
        myGLCD.fillRect (0,204,46,232);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.print("Tuner",3, 205);
        myGLCD.print("OFF",12, 218);}
        if(tune==1){
        myGLCD.setColor(VGA_GREEN);
        myGLCD.fillRect (0,204,46,232);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.print("Tuner",3, 205);
        myGLCD.print("ON",16, 218);}        
        myGLCD.setColor(VGA_GRAY);


//------manuelle bandwahl--------------        
   // 160m Band
   if (automode == 0){  
         if (((y>=230) && (y<=272)) && ((x>=0) && (x<=46))){ 
        band=1; 
        analogWrite(band_v,255);       
        band_mode();
        } 
   // 80m Band
      if (((y>=230) && (y<=272)) && ((x>=50) && (x<=96))){
        band=2; 
        analogWrite(band_v,200);       
        band_mode();
        }
   // 60/40m Band 
      if (((y>=230) && (y<=272)) && ((x>=100) && (x<=146))){
        band=3; 
        analogWrite(band_v,160);       
        band_mode();
        }
   // 30m Band  
      if (((y>=230) && (y<=272)) && ((x>=150) && (x<=196))){
        band=4;
        analogWrite(band_v,120);        
        band_mode();
        }
   // 20m Band  
      if (((y>=230) && (y<=272)) && ((x>=200) && (x<=246))){
        band=5;
        analogWrite(band_v,80);        
        band_mode();
        }
   // 17/15m Band  
      if (((y>=230) && (y<=272)) && ((x>=250) && (x<=296))){
        band=6;
        analogWrite(band_v,40);        
        band_mode();
        }
   // 12/10m Band  
      if (((y>=230) && (y<=272)) && ((x>=300) && (x<=346))){
        band=7; 
        analogWrite(band_v,0);      
        band_mode();
        }     
   }
}
