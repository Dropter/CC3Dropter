#include <SoftwareSerial.h>
#include "DataOI.h"
#include "UAVTalk.h"

/*
  Declaration of RX and TX pins for communication with CC3D.
*/
SoftwareSerial CC3Dcomm(10, 11);

void setup() {
  /* Setup of USB connection for debugging purposes.*/
  Serial.begin(115200);
  while(!Serial) {
  }

  CC3Dcomm.begin(57600);
}

void loop() {

  if(CC3Dcomm.available()) {
    softwareSerialEvent();
  }

  Serial.println(dt_roll);
  Serial.println(dt_pitch);
  Serial.println(dt_yaw);
}

static uavtalk_message_t msg;

void softwareSerialEvent(){
  uint8_t c = CC3Dcomm.read();
  if (uavtalk_parse_char(c, &msg)) {
    uavtalk_read(&msg);
  }
}
