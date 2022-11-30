void loop(){
  if (operate_mode==0){
    operate();
    }


//*****************Touchabfrage/Aufruf*********************************
if (myTouch.dataAvailable()){
      if(!touch_press){
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      touch_select();
      x=0;
      y=0;
        }
      }
      else {touch_press=false;}

//**********RX-TX Display***************
     
//**********RX-TX Display***************
      tx_state = digitalRead(tx_in);
    if (((pwr_on==1)&&(tx_state==0)&&tx_state!=tx_state_old)){
      tx_state_old=tx_state;
      refresh_tx_disp=1;}
    else if (((pwr_on==1)&&(tx_state==1)&&(tx_state!=tx_state_old))){
      tx_state_old=tx_state;
      refresh_tx_disp=1;}

    if (refresh_tx_disp==1){
      if (tx_state==1){
      myGLCD.setColor(VGA_GREEN);
      myGLCD.fillRect (400,240,429,272); 
      myGLCD.setColor(VGA_WHITE);
      myGLCD.print("RX",408,250);
      digitalWrite(tx_out,LOW);} 
      else if (tx_state==0){
      myGLCD.setColor(VGA_RED);
      myGLCD.fillRect (400,240,429,272);
      myGLCD.setColor(VGA_WHITE);
      myGLCD.print("TX",408,250);
      digitalWrite(tx_out,HIGH);}
      refresh_tx_disp=0;
      }

//***********************************************Tune Wait und Protection Meldung**************************      
      tune_state = digitalRead(tune_wait_in);
    if ((tune_state==0)&&(tune_state!=tune_state_old)){
      tune_state_old=tune_state;
      refresh_tune_disp=1;}
    else if ((tune_state==1)&&(tune_state!=tune_state_old)){
      tune_state_old=tune_state;
      refresh_tune_disp=1;}
      
    if(refresh_tune_disp==1){        
    if (tune_state==0){    
        myGLCD.setColor(255,112,0); //Orange
        myGLCD.fillRect (50,204,96,232);}
        else if (tune_state==1){
        myGLCD.setColor(50,50,50); //grey
        myGLCD.fillRect (50,204,96,232);}
        myGLCD.setColor(VGA_BLACK);
        myGLCD.print("Tune",58, 205);
        myGLCD.print("Wait",58, 218);
        refresh_tune_disp = 0;}


    fault_state = digitalRead(fault_in);
    if ((fault_state==0)&&(fault_state!=fault_state_old)){
      fault_state_old=fault_state;
      refresh_fault_disp=1;}
    else if ((fault_state==1)&&(fault_state!=fault_state_old)){
      fault_state_old=fault_state;
      refresh_fault_disp=1;}
        
       if (refresh_fault_disp==1){
        if (fault_state==0){    
        myGLCD.setColor(VGA_RED); 
        myGLCD.fillRect (100,204,479,232);
        myGLCD.setColor(VGA_WHITE);
        myGLCD.print("Protected",250, 214);}
       // delay(250);}
        else if (fault_state==1){
        myGLCD.setColor(50,50,50); //grey
        myGLCD.fillRect (100,204,479,232);
        myGLCD.setColor(VGA_BLACK);
        myGLCD.print("Protected",250, 214);}
        refresh_fault_disp=0;}
//*********************************Analogwert**************************
  
    //ME1 
    analogReadResolution(10); //only Arduino Due
    me1 = analogRead(2)/2;
    me1_graph = me1*me1_multi;
//    drawColorBar_ME1(me1_graph,60,0,3);  //zeichne ME1
    if(me1_graph>me1_graph_old){
    me1_graph_old = me1_graph;}
    currentpeakMillis1 = millis();
    if(currentpeakMillis1 - startpeakMillis1 >= peakperiod1){    
    drawColorBar_ME1(me1_graph_old,60,0,3);  //zeichne ME1
    startpeakMillis1 = currentpeakMillis1;}
    if(currentpeakMillis1 - startpeakMillis1 <= peakperiod1){
    me1_graph_old = me1_graph;}
        
        
    //ME2
    analogReadResolution(10); //only Arduino Due
    me2 = analogRead(3)/2;
    me2_graph = me2*me2_multi;
//    drawColorBar_ME2(me2_graph,60,120,3);  //zeichne ME1
    
    if(me2_graph>me2_graph_old){
    me2_graph_old = me2_graph;}
    currentpeakMillis2 = millis();
    if(currentpeakMillis2 - startpeakMillis2 >= peakperiod2){    
    drawColorBar_ME2(me2_graph_old,60,120,3);  //zeichne ME1
    startpeakMillis2 = currentpeakMillis2;}
    if(currentpeakMillis2 - startpeakMillis2 <= peakperiod2){
    me2_graph_old = me2_graph;}
       


  band_mode(); 
//uart_one();
}//<---------------------------------------------------------------------------------------------------------end loop
