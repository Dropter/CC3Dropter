#ifndef UAVTALK_H
#define UAVTALK_H

#include "Config.h"
#include <Arduino.h>

#define HEADER_LEN 10
#define RESPOND_OBJ_LEN HEADER_LEN
#define GCSTELEMETRYSTATS_SEND_PERIOD 1000
#define FLIGHTTELEMETRYSTATS_CONNECT_TIMEOUT 10000

#define UAVTALK_TYPE_VER 0x20
#define UAVTALK_MODE_PASSIVE 0x01
#define UAVTALK_SYNC_VAL 0x3C
#define UAVTALK_TYPE_OBJ_ACK (UAVTALK_TYPE_VER | 0x02)
#define UAVTALK_TYPE_ACK (UAVTALK_TYPE_VER | 0x03)

#define ATTITUDESTATE_OBJ_ID 0xD7E0D964
#define ATTITUDESTATE_ROLL 16
#define ATTITUDESTATE_PITCH 20
#define ATTITUDESTATE_YAW 24

#define	FLIGHTTELEMETRYSTATS_OBJ_ID 0x6737BB5A
#define FLIGHTTELEMETRYSTATS_OBJ_LEN 37
#define	FLIGHTTELEMETRYSTATS_OBJ_STATUS		36

#define GCSTELEMETRYSTATS_OBJ_ID 0xCAD1DC0A
#define GCSTELEMETRYSTATS_OBJ_LEN 37
#define GCSTELEMETRYSTATS_OBJ_STATUS 36

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
int uavtalk_state(void);
void uavtalk_send_gcstelemetrystats(void);
void uavtalk_respond_object(uavtalk_message_t *msg_to_respond, uint8_t type);
void uavtalk_send_msg(uavtalk_message_t *msg);

#endif
