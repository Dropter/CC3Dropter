/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup FlightTelemetryStats FlightTelemetryStats 
 * @brief Maintains the telemetry statistics from the OpenPilot flight computer.
 *
 * Autogenerated files and functions for FlightTelemetryStats Object
 *
 * @{ 
 *
 * @file       flighttelemetrystats.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the FlightTelemetryStats object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: flighttelemetrystats.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef FLIGHTTELEMETRYSTATS_H
#define FLIGHTTELEMETRYSTATS_H

/* Object constants */
#define FLIGHTTELEMETRYSTATS_OBJID 0x6737BB5A
#define FLIGHTTELEMETRYSTATS_ISSINGLEINST 1
#define FLIGHTTELEMETRYSTATS_ISSETTINGS 0
#define FLIGHTTELEMETRYSTATS_ISPRIORITY 1
#define FLIGHTTELEMETRYSTATS_NUMBYTES sizeof(FlightTelemetryStatsData)

/* Generic interface functions */
int32_t FlightTelemetryStatsInitialize();
UAVObjHandle FlightTelemetryStatsHandle();
void FlightTelemetryStatsSetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    float TxDataRate;
    uint32_t TxBytes;
    uint32_t TxFailures;
    uint32_t TxRetries;
    float RxDataRate;
    uint32_t RxBytes;
    uint32_t RxFailures;
    uint32_t RxSyncErrors;
    uint32_t RxCrcErrors;
    uint8_t Status;
} __attribute__((packed)) FlightTelemetryStatsDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef FlightTelemetryStatsDataPacked __attribute__((aligned(4))) FlightTelemetryStatsData;
    
/* Typesafe Object access functions */
static inline int32_t FlightTelemetryStatsGet(FlightTelemetryStatsData *dataOut) { return UAVObjGetData(FlightTelemetryStatsHandle(), dataOut); }
static inline int32_t FlightTelemetryStatsSet(const FlightTelemetryStatsData *dataIn) { return UAVObjSetData(FlightTelemetryStatsHandle(), dataIn); }
static inline int32_t FlightTelemetryStatsInstGet(uint16_t instId, FlightTelemetryStatsData *dataOut) { return UAVObjGetInstanceData(FlightTelemetryStatsHandle(), instId, dataOut); }
static inline int32_t FlightTelemetryStatsInstSet(uint16_t instId, const FlightTelemetryStatsData *dataIn) { return UAVObjSetInstanceData(FlightTelemetryStatsHandle(), instId, dataIn); }
static inline int32_t FlightTelemetryStatsConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(FlightTelemetryStatsHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t FlightTelemetryStatsConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(FlightTelemetryStatsHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t FlightTelemetryStatsCreateInstance() { return UAVObjCreateInstance(FlightTelemetryStatsHandle(), &FlightTelemetryStatsSetDefaults); }
static inline void FlightTelemetryStatsRequestUpdate() { UAVObjRequestUpdate(FlightTelemetryStatsHandle()); }
static inline void FlightTelemetryStatsRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(FlightTelemetryStatsHandle(), instId); }
static inline void FlightTelemetryStatsUpdated() { UAVObjUpdated(FlightTelemetryStatsHandle()); }
static inline void FlightTelemetryStatsInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(FlightTelemetryStatsHandle(), instId); }
static inline void FlightTelemetryStatsLogging() { UAVObjLogging(FlightTelemetryStatsHandle()); }
static inline void FlightTelemetryStatsInstLogging(uint16_t instId) { UAVObjInstanceLogging(FlightTelemetryStatsHandle(), instId); }
static inline int32_t FlightTelemetryStatsGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(FlightTelemetryStatsHandle(), dataOut); }
static inline int32_t FlightTelemetryStatsSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(FlightTelemetryStatsHandle(), dataIn); }
static inline int8_t FlightTelemetryStatsReadOnly() { return UAVObjReadOnly(FlightTelemetryStatsHandle()); }

/* Field TxDataRate information */

/* Field TxBytes information */

/* Field TxFailures information */

/* Field TxRetries information */

/* Field RxDataRate information */

/* Field RxBytes information */

/* Field RxFailures information */

/* Field RxSyncErrors information */

/* Field RxCrcErrors information */

/* Field Status information */

// Enumeration options for field Status
typedef enum {
    FLIGHTTELEMETRYSTATS_STATUS_DISCONNECTED=0,
    FLIGHTTELEMETRYSTATS_STATUS_HANDSHAKEREQ=1,
    FLIGHTTELEMETRYSTATS_STATUS_HANDSHAKEACK=2,
    FLIGHTTELEMETRYSTATS_STATUS_CONNECTED=3
} FlightTelemetryStatsStatusOptions;



/* Set/Get functions */
extern void FlightTelemetryStatsTxDataRateSet(float *NewTxDataRate);
extern void FlightTelemetryStatsTxDataRateGet(float *NewTxDataRate);
extern void FlightTelemetryStatsTxBytesSet(uint32_t *NewTxBytes);
extern void FlightTelemetryStatsTxBytesGet(uint32_t *NewTxBytes);
extern void FlightTelemetryStatsTxFailuresSet(uint32_t *NewTxFailures);
extern void FlightTelemetryStatsTxFailuresGet(uint32_t *NewTxFailures);
extern void FlightTelemetryStatsTxRetriesSet(uint32_t *NewTxRetries);
extern void FlightTelemetryStatsTxRetriesGet(uint32_t *NewTxRetries);
extern void FlightTelemetryStatsRxDataRateSet(float *NewRxDataRate);
extern void FlightTelemetryStatsRxDataRateGet(float *NewRxDataRate);
extern void FlightTelemetryStatsRxBytesSet(uint32_t *NewRxBytes);
extern void FlightTelemetryStatsRxBytesGet(uint32_t *NewRxBytes);
extern void FlightTelemetryStatsRxFailuresSet(uint32_t *NewRxFailures);
extern void FlightTelemetryStatsRxFailuresGet(uint32_t *NewRxFailures);
extern void FlightTelemetryStatsRxSyncErrorsSet(uint32_t *NewRxSyncErrors);
extern void FlightTelemetryStatsRxSyncErrorsGet(uint32_t *NewRxSyncErrors);
extern void FlightTelemetryStatsRxCrcErrorsSet(uint32_t *NewRxCrcErrors);
extern void FlightTelemetryStatsRxCrcErrorsGet(uint32_t *NewRxCrcErrors);
extern void FlightTelemetryStatsStatusSet(uint8_t *NewStatus);
extern void FlightTelemetryStatsStatusGet(uint8_t *NewStatus);


#endif // FLIGHTTELEMETRYSTATS_H

/**
 * @}
 * @}
 */
