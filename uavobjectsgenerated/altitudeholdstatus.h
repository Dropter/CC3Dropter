/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup AltitudeHoldStatus AltitudeHoldStatus 
 * @brief Status Data from Altitude Hold Control Loops
 *
 * Autogenerated files and functions for AltitudeHoldStatus Object
 *
 * @{ 
 *
 * @file       altitudeholdstatus.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the AltitudeHoldStatus object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: altitudeholdstatus.xml. 
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

#ifndef ALTITUDEHOLDSTATUS_H
#define ALTITUDEHOLDSTATUS_H

/* Object constants */
#define ALTITUDEHOLDSTATUS_OBJID 0x97AFCEC6
#define ALTITUDEHOLDSTATUS_ISSINGLEINST 1
#define ALTITUDEHOLDSTATUS_ISSETTINGS 0
#define ALTITUDEHOLDSTATUS_ISPRIORITY 0
#define ALTITUDEHOLDSTATUS_NUMBYTES sizeof(AltitudeHoldStatusData)

/* Generic interface functions */
int32_t AltitudeHoldStatusInitialize();
UAVObjHandle AltitudeHoldStatusHandle();
void AltitudeHoldStatusSetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    float VelocityDesired;
} __attribute__((packed)) AltitudeHoldStatusDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef AltitudeHoldStatusDataPacked __attribute__((aligned(4))) AltitudeHoldStatusData;
    
/* Typesafe Object access functions */
static inline int32_t AltitudeHoldStatusGet(AltitudeHoldStatusData *dataOut) { return UAVObjGetData(AltitudeHoldStatusHandle(), dataOut); }
static inline int32_t AltitudeHoldStatusSet(const AltitudeHoldStatusData *dataIn) { return UAVObjSetData(AltitudeHoldStatusHandle(), dataIn); }
static inline int32_t AltitudeHoldStatusInstGet(uint16_t instId, AltitudeHoldStatusData *dataOut) { return UAVObjGetInstanceData(AltitudeHoldStatusHandle(), instId, dataOut); }
static inline int32_t AltitudeHoldStatusInstSet(uint16_t instId, const AltitudeHoldStatusData *dataIn) { return UAVObjSetInstanceData(AltitudeHoldStatusHandle(), instId, dataIn); }
static inline int32_t AltitudeHoldStatusConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(AltitudeHoldStatusHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t AltitudeHoldStatusConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(AltitudeHoldStatusHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t AltitudeHoldStatusCreateInstance() { return UAVObjCreateInstance(AltitudeHoldStatusHandle(), &AltitudeHoldStatusSetDefaults); }
static inline void AltitudeHoldStatusRequestUpdate() { UAVObjRequestUpdate(AltitudeHoldStatusHandle()); }
static inline void AltitudeHoldStatusRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(AltitudeHoldStatusHandle(), instId); }
static inline void AltitudeHoldStatusUpdated() { UAVObjUpdated(AltitudeHoldStatusHandle()); }
static inline void AltitudeHoldStatusInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(AltitudeHoldStatusHandle(), instId); }
static inline void AltitudeHoldStatusLogging() { UAVObjLogging(AltitudeHoldStatusHandle()); }
static inline void AltitudeHoldStatusInstLogging(uint16_t instId) { UAVObjInstanceLogging(AltitudeHoldStatusHandle(), instId); }
static inline int32_t AltitudeHoldStatusGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(AltitudeHoldStatusHandle(), dataOut); }
static inline int32_t AltitudeHoldStatusSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(AltitudeHoldStatusHandle(), dataIn); }
static inline int8_t AltitudeHoldStatusReadOnly() { return UAVObjReadOnly(AltitudeHoldStatusHandle()); }

/* Field VelocityDesired information */



/* Set/Get functions */
extern void AltitudeHoldStatusVelocityDesiredSet(float *NewVelocityDesired);
extern void AltitudeHoldStatusVelocityDesiredGet(float *NewVelocityDesired);


#endif // ALTITUDEHOLDSTATUS_H

/**
 * @}
 * @}
 */
