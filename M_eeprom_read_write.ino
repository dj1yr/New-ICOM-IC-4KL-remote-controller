void r_w_eeprom (){
    const word address = 0;
    const byte count = 94;
    // Declare byte arrays.
    byte inputBytes[count] = { 0 };
    byte outputBytes[count] = { 0 };
    
    for (byte i = 0; i < count; i++)
    {    
        inputBytes[i] = i + 33;
    }

    // Write input array to EEPROM memory.
    Serial.println("Write bytes to EEPROM memory...");
    eeprom.writeBytes(address, count, inputBytes);

    // Read array with bytes read from EEPROM memory.
    Serial.println("Read bytes from EEPROM memory...");
    eeprom.readBytes(address, count, outputBytes);
    
    // Print read bytes.
    Serial.println("Read bytes:");
    for (byte i = 0; i < count; i++)
    {
        Serial.write(outputBytes[i]);
        Serial.print(" ");
    }
    Serial.println("");

}
