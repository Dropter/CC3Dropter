#ifndef UAVTALK_H
#define UAVTALK_H

#include "Config.h"
#include <Arduino.h>

#define ATTITUDESTATE_OBJ_ID 0xD7E0D964

#define ATTITUDESTATE_ROLL 16
#define ATTITUDESTATE_PITCH 20
#define ATTITUDESTATE_YAW 24

typedef enum {
  UAVTALK_PARSE_STATE_WAIT_SYNC = 0,
  UAVTALK_PARSE_STATE_GOT_SYNC,
  UAVTALK_PARSE_STATE_GOT_MSG_TYPE,
  UAVTALK_PARSE_STATE_GOT_LENGTH,
  UAVTALK_PARSE_STATE_GOT_OBJID,
  UAVTALK_PARSE_STATE_GOT_INSTID,
  UAVTALK_PARSE_STATE_GOT_DATA,
  UAVTALK_PARSE_STATE_GOT_CRC
} uavtalk_parse_state_t;

typedef enum {
  TELEMETRYSTATS_STATE_DISCONNECTED = 0,
  TELEMETRYSTATS_STATE_HANDSHAKEREQ,
  TELEMETRYSTATS_STATE_HANDSHAKEACK,
  TELEMETRYSTATS_STATE_CONNECTED
} telemetrystats_state_t;

typedef struct __uavtalk_message {
  uint8_t Sync;
  uint8_t MsgType;
  uint16_t Length;
  uint32_t ObjID;
  uint16_t InstID;
  uint8_t Data[255];
  uint8_t Crc;
} uavtalk_message_t;

int uavtalk_read(void);

#endif
