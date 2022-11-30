void operate(){
    myGLCD.clrScr();

    myGLCD.setColor(VGA_WHITE);
    myGLCD.drawLine(0,236,479,236);
  
    myGLCD.setFont(SmallFont);      
    myGLCD.setColor(VGA_RED);
    myGLCD.fillRect (433,240,479,272);//Standby/Operate
    myGLCD.setColor(VGA_GRAY);

//**set default start routine**
  pwr_on=0; // PA is in Standby
  tx_state_old=1;
  band=7; //set highest usefull band
  band_old=0;
  MS1=0; //set RF forward Display
  MS2=1; //set VC Display
  automode=1; //for Manual = 0; for ICOM IC-4KL = 1; for BCD code = 2; ICOM CIV = 4;YAESU CAT = 5;KENWOOD CAT = 6
  analogWrite(band_v,0);
  band_mode(); //jump in H_Band routine
  Meter(); //jump in M_Meter routine
  touch_select();
  refresh_tune_disp = 1; 
  refresh_tx_disp = 1;
  refresh_fault_disp = 1;
  operate_mode=1; // set Start defaults
  me1_graph_old=0;
  me2_graph_old=0;
//***********************
}
