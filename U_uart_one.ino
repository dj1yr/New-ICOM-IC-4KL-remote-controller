//serielle Ausgabe
void uart_one(){
  Serial.print("");

          Serial.print("refresh_tune_disp: ");
  Serial.println(refresh_tune_disp);
      Serial.print("");
           Serial.print("tune_state: ");
  Serial.println(tune_state);
      Serial.print(""); 
                 Serial.print("tune_state_old: ");
  Serial.println(tune_state_old);
      Serial.print(""); 
                Serial.print("refresh_tx_disp: ");
  Serial.println(refresh_tx_disp);
      Serial.print("");
           Serial.print("tx_state: ");
  Serial.println(tx_state);
      Serial.print(""); 
                 Serial.print("tx_state_old: ");
  Serial.println(tx_state_old);
      Serial.print("");
delay(500);
}
