/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup MagState MagState
 * @brief The filtered magnet vector.
 *
 * Autogenerated files and functions for MagState Object
 * @{ 
 *
 * @file       magstate.c
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the MagState object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: magstate.xml. 
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

#include <openpilot.h>
#include "magstate.h"

// Private variables
#if (defined(__MACH__) && defined(__APPLE__))
static UAVObjHandle handle __attribute__((section("__DATA,_uavo_handles")));
#else
static UAVObjHandle handle __attribute__((section("_uavo_handles")));
#endif

/**
 * Initialize object.
 * \return 0 Success
 * \return -1 Failure to initialize or -2 for already initialized
 */
int32_t MagStateInitialize(void)
{
    // Compile time assertion that the MagStateDataPacked and MagStateData structs
    // have the same size (though instances of MagStateData
    // should be placed in memory by the linker/compiler on a 4 byte alignment).
    PIOS_STATIC_ASSERT(sizeof(MagStateDataPacked) == sizeof(MagStateData));
    
    // Don't set the handle to null if already registered
    if (UAVObjGetByID(MAGSTATE_OBJID)) {
        return -2;
    }

    // Register object with the object manager
    handle = UAVObjRegister(MAGSTATE_OBJID,
        MAGSTATE_ISSINGLEINST, MAGSTATE_ISSETTINGS, MAGSTATE_ISPRIORITY, MAGSTATE_NUMBYTES, &MagStateSetDefaults);

    // Done
    return handle ? 0 : -1;
}

/**
 * Initialize object fields and metadata with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void MagStateSetDefaults(UAVObjHandle obj, uint16_t instId)
{
    MagStateData data;

    // Initialize object fields to their default values
    UAVObjGetInstanceData(obj, instId, &data);
    memset(&data, 0, sizeof(MagStateData));
    data.Source = 0;

    UAVObjSetInstanceData(obj, instId, &data);

    // Initialize object metadata to their default values
    if ( instId == 0 ) {
        UAVObjMetadata metadata;
        metadata.flags =
            ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
            ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
            0 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
            0 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
            UPDATEMODE_PERIODIC << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_MANUAL << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
        metadata.telemetryUpdatePeriod = 1000;
        metadata.gcsTelemetryUpdatePeriod = 0;
        metadata.loggingUpdatePeriod = 0;
        UAVObjSetMetadata(obj, &metadata);
    }
}

/**
 * Get object handle
 */
UAVObjHandle MagStateHandle()
{
    return handle;
}

/**
 * Get/Set object Functions
 */
void MagStatexSet(float *Newx)
{
    UAVObjSetDataField(MagStateHandle(), (void *)Newx, offsetof(MagStateData, x), sizeof(float));
}
void MagStatexGet(float *Newx)
{
    UAVObjGetDataField(MagStateHandle(), (void *)Newx, offsetof(MagStateData, x), sizeof(float));
}
void MagStateySet(float *Newy)
{
    UAVObjSetDataField(MagStateHandle(), (void *)Newy, offsetof(MagStateData, y), sizeof(float));
}
void MagStateyGet(float *Newy)
{
    UAVObjGetDataField(MagStateHandle(), (void *)Newy, offsetof(MagStateData, y), sizeof(float));
}
void MagStatezSet(float *Newz)
{
    UAVObjSetDataField(MagStateHandle(), (void *)Newz, offsetof(MagStateData, z), sizeof(float));
}
void MagStatezGet(float *Newz)
{
    UAVObjGetDataField(MagStateHandle(), (void *)Newz, offsetof(MagStateData, z), sizeof(float));
}
void MagStateSourceSet(uint8_t *NewSource)
{
    UAVObjSetDataField(MagStateHandle(), (void *)NewSource, offsetof(MagStateData, Source), sizeof(uint8_t));
}
void MagStateSourceGet(uint8_t *NewSource)
{
    UAVObjGetDataField(MagStateHandle(), (void *)NewSource, offsetof(MagStateData, Source), sizeof(uint8_t));
}


/**
 * @}
 */