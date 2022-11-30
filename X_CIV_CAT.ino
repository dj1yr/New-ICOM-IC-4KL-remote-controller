

#define DEBUG 1
//#define MIRRORCAT 1

#define BROADCAST_ADDRESS    0x00 //Broadcast address
#define CONTROLLER_ADDRESS   0xE0 //Controller address

#define START_BYTE       0xFE //Start byte
#define STOP_BYTE       0xFD //Stop byte

#define CMD_READ_FREQ       0x03 //Read operating frequency data

const uint32_t decMulti[]    = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

#define BAUD_RATES_SIZE 7
const uint16_t baudRates[BAUD_RATES_SIZE]       = {115200, 57600 ,38400 ,19200, 9600, 4800, 1200};

uint8_t  radio_address;     //Transiever address
uint16_t  baud_rate;        //Current baud speed
uint32_t  readtimeout;      //Serial port read timeout
uint8_t  read_buffer[12];   //Read buffer
uint32_t  frequency;        //Current frequency in Hz

void CIV(){



}


