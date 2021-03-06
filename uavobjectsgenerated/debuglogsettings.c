/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup DebugLogSettings DebugLogSettings
 * @brief Configure On Board Logging Facilities
 *
 * Autogenerated files and functions for DebugLogSettings Object
 * @{ 
 *
 * @file       debuglogsettings.c
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the DebugLogSettings object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: debuglogsettings.xml. 
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
#include "debuglogsettings.h"

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
int32_t DebugLogSettingsInitialize(void)
{
    // Compile time assertion that the DebugLogSettingsDataPacked and DebugLogSettingsData structs
    // have the same size (though instances of DebugLogSettingsData
    // should be placed in memory by the linker/compiler on a 4 byte alignment).
    PIOS_STATIC_ASSERT(sizeof(DebugLogSettingsDataPacked) == sizeof(DebugLogSettingsData));
    
    // Don't set the handle to null if already registered
    if (UAVObjGetByID(DEBUGLOGSETTINGS_OBJID)) {
        return -2;
    }

    // Register object with the object manager
    handle = UAVObjRegister(DEBUGLOGSETTINGS_OBJID,
        DEBUGLOGSETTINGS_ISSINGLEINST, DEBUGLOGSETTINGS_ISSETTINGS, DEBUGLOGSETTINGS_ISPRIORITY, DEBUGLOGSETTINGS_NUMBYTES, &DebugLogSettingsSetDefaults);

    // Done
    return handle ? 0 : -1;
}

/**
 * Initialize object fields and metadata with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void DebugLogSettingsSetDefaults(UAVObjHandle obj, uint16_t instId)
{
    DebugLogSettingsData data;

    // Initialize object fields to their default values
    UAVObjGetInstanceData(obj, instId, &data);
    memset(&data, 0, sizeof(DebugLogSettingsData));
    data.LoggingEnabled = 0;

    UAVObjSetInstanceData(obj, instId, &data);

    // Initialize object metadata to their default values
    if ( instId == 0 ) {
        UAVObjMetadata metadata;
        metadata.flags =
            ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
            ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
            1 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
            1 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
            UPDATEMODE_ONCHANGE << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_ONCHANGE << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
        metadata.telemetryUpdatePeriod = 0;
        metadata.gcsTelemetryUpdatePeriod = 0;
        metadata.loggingUpdatePeriod = 0;
        UAVObjSetMetadata(obj, &metadata);
    }
}

/**
 * Get object handle
 */
UAVObjHandle DebugLogSettingsHandle()
{
    return handle;
}

/**
 * Get/Set object Functions
 */
void DebugLogSettingsLoggingEnabledSet(uint8_t *NewLoggingEnabled)
{
    UAVObjSetDataField(DebugLogSettingsHandle(), (void *)NewLoggingEnabled, offsetof(DebugLogSettingsData, LoggingEnabled), sizeof(uint8_t));
}
void DebugLogSettingsLoggingEnabledGet(uint8_t *NewLoggingEnabled)
{
    UAVObjGetDataField(DebugLogSettingsHandle(), (void *)NewLoggingEnabled, offsetof(DebugLogSettingsData, LoggingEnabled), sizeof(uint8_t));
}


/**
 * @}
 */
