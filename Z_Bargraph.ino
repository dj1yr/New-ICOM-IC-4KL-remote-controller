void drawColorBar_ME1(int value_ME1,int spotx_ME1, int spoty_ME1, int pix_ME1){
  for(int i_ME1=0;i_ME1<128;i_ME1++){
    if(i_ME1<=value_ME1){
    myGLCD.setColor(rgbtable_big[i_ME1][0],rgbtable_big[i_ME1][1],rgbtable_big[i_ME1][2]);
    } else {myGLCD.setColor(32,32,32);}
    myGLCD.fillRect(spotx_ME1+(i_ME1*pix_ME1),spoty_ME1,spotx_ME1+(i_ME1*pix_ME1)+pix_ME1/2,spoty_ME1+24);
  }
}

void drawColorBar_ME2(int value_ME2,int spotx_ME2, int spoty_ME2, int pix_ME2){
  for(int i_ME2=0;i_ME2<128;i_ME2++){
    if(i_ME2<=value_ME2){
    myGLCD.setColor(rgbtable_big[i_ME2][0],rgbtable_big[i_ME2][1],rgbtable_big[i_ME2][2]);
    } else {myGLCD.setColor(32,32,32);}
    myGLCD.fillRect(spotx_ME2+(i_ME2*pix_ME2),spoty_ME2,spotx_ME2+(i_ME2*pix_ME2)+pix_ME2/2,spoty_ME2+24);
  }
}
