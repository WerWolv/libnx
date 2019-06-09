/**
 * @file hiddbg.h
 * @brief hid:dbg service IPC wrapper.
 * @author yellows8
 */
#pragma once
#include "../types.h"
#include "../services/hid.h"
#include "../services/sm.h"

/// HdlsDeviceInfo
typedef struct {
    u32 type;                 ///< See \ref HidControllerType, only one bit can be set.
    u32 singleColorBody;      ///< RGBA Single Body Color
    u32 singleColorButtons;   ///< RGBA Single Buttons Color
    u8 unk_xc;                ///< Unknown
    u8 pad[0x3];              ///< Padding
} HiddbgHdlsDeviceInfo;

/// HdlsState
typedef struct {
    u8 unk_x0[0x8];                                       ///< Unknown
    u32 batteryCharge;                                    ///< batteryCharge for the main PowerInfo, see \ref HidPowerInfo.
    u32 buttons;                                          ///< See \ref HidControllerKeys.
    JoystickPosition joysticks[JOYSTICK_NUM_STICKS];      ///< \ref JoystickPosition
    u32 unused;                                           ///< Unused
} HiddbgHdlsState;

/// HdlsNpadAssignment
typedef struct {
    u8 unk_x0[0x208];         ///< Unknown
} HiddbgHdlsNpadAssignment;

/// HdlsStateListEntry
typedef struct {
    u64 HdlsHandle;                             ///< HdlsHandle
    HiddbgHdlsDeviceInfo device;                ///< \ref HiddbgHdlsDeviceInfo. With \ref hiddbgApplyHdlsStateList this is only used when creating new devices.
    HiddbgHdlsState state;                      ///< \ref HiddbgHdlsState
} HiddbgHdlsStateListEntry;

/// HdlsStateList. This contains a list of all controllers, including non-virtual controllers.
typedef struct {
    s32 total_entries;                          ///< Total entries for the below entries.
    u32 pad;                                    ///< Padding
    HiddbgHdlsStateListEntry entries[0x10];     ///< \ref HiddbgHdlsStateListEntry
} HiddbgHdlsStateList;

Result hiddbgInitialize(void);
void hiddbgExit(void);

/// Initialize Hdls. Hdls is for virtual HID controllers. Only available with [7.0.0+].
Result hiddbgAttachHdlsWorkBuffer(void);

/// Exit Hdls, must be called at some point prior to hiddbgExit. Only available with [7.0.0+].
Result hiddbgReleaseHdlsWorkBuffer(void);

/// Gets state for \ref HiddbgHdlsNpadAssignment. Only available with [7.0.0+].
Result hiddbgDumpHdlsNpadAssignmentState(HiddbgHdlsNpadAssignment *state);

/// Gets state for \ref HiddbgHdlsStateList. Only available with [7.0.0+].
Result hiddbgDumpHdlsStates(HiddbgHdlsStateList *state);

/// Sets state for \ref HiddbgHdlsNpadAssignment. Only available with [7.0.0+].
Result hiddbgApplyHdlsNpadAssignmentState(const HiddbgHdlsNpadAssignment *state, bool flag);

/// Sets state for \ref HiddbgHdlsStateList. Only available with [7.0.0+].
/// The HiddbgHdlsState will be applied for each HdlsHandle. If a HdlsHandle is not found, code similar to \ref hiddbgAttachHdlsVirtualDevice will run with the \ref HiddbgHdlsDeviceInfo, then it will continue with applying state with the new device.
Result hiddbgApplyHdlsStateList(const HiddbgHdlsStateList *state);

/// Attach a device with the input info, where the output handle is written to HdlsHandle. Only available with [7.0.0+].
Result hiddbgAttachHdlsVirtualDevice(u64 *HdlsHandle, const HiddbgHdlsDeviceInfo *info);

/// Detach the specified device. Only available with [7.0.0+].
Result hiddbgDetachHdlsVirtualDevice(u64 HdlsHandle);

/// Sets state for the specified device. Only available with [7.0.0+].
Result hiddbgSetHdlsState(u64 HdlsHandle, const HiddbgHdlsState *state);
