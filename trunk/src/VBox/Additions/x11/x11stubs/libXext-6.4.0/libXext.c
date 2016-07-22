/* $Id$ */

/** @file
 * X.Org libXext.so linker stub
 */

/*
 * Copyright (C) 2010-2016 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#include <iprt/cdefs.h>
#include <iprt/types.h>

#define DECLXSTUB(func) \
    DECLEXPORT(void) func(void); \
    void func(void) {}

DECLXSTUB(XSyncAwait)
DECLXSTUB(XagCreateEmbeddedApplicationGroup)
DECLXSTUB(XeviGetVisualInfo)
DECLXSTUB(XSyncValueGreaterOrEqual)
DECLXSTUB(XSyncIntToValue)
DECLXSTUB(DPMSDisable)
DECLXSTUB(XSyncValueSubtract)
DECLXSTUB(DPMSEnable)
DECLXSTUB(XShmQueryExtension)
DECLXSTUB(DPMSGetVersion)
DECLXSTUB(XTestFakeInput)
DECLXSTUB(XdbeAllocateBackBufferName)
DECLXSTUB(DPMSInfo)
DECLXSTUB(XTestGetInput)
DECLXSTUB(XmbufGetWindowAttributes)
DECLXSTUB(XMITMiscGetBugMode)
DECLXSTUB(XTestReset)
DECLXSTUB(XSyncChangeAlarm)
DECLXSTUB(XdbeDeallocateBackBufferName)
DECLXSTUB(XSyncValueIsNegative)
DECLXSTUB(XTestQueryInputSize)
DECLXSTUB(XLbxQueryExtension)
DECLXSTUB(XeviQueryVersion)
DECLXSTUB(XShapeQueryExtension)
DECLXSTUB(XmbufGetScreenInfo)
DECLXSTUB(XSyncValueLow32)
DECLXSTUB(XSyncIntsToValue)
DECLXSTUB(XSyncValueAdd)
DECLXSTUB(XSecurityGenerateAuthorization)
DECLXSTUB(DPMSSetTimeouts)
DECLXSTUB(XShapeQueryVersion)
DECLXSTUB(XShmCreatePixmap)
DECLXSTUB(XmbufDisplayBuffers)
DECLXSTUB(XShapeCombineShape)
DECLXSTUB(XMITMiscSetBugMode)
DECLXSTUB(XmbufCreateBuffers)
DECLXSTUB(XagGetApplicationGroupAttributes)
DECLXSTUB(XSecurityQueryExtension)
DECLXSTUB(DPMSGetTimeouts)
DECLXSTUB(XSyncQueryCounter)
DECLXSTUB(XextAddDisplay)
DECLXSTUB(XSyncChangeCounter)
DECLXSTUB(XSyncDestroyAlarm)
DECLXSTUB(XeviQueryExtension)
DECLXSTUB(XMissingExtension)
DECLXSTUB(XmbufChangeWindowAttributes)
DECLXSTUB(XSyncQueryAlarm)
DECLXSTUB(XdbeGetVisualInfo)
DECLXSTUB(XShmGetEventBase)
DECLXSTUB(XSyncValueLessOrEqual)
DECLXSTUB(XextFindDisplay)
DECLXSTUB(XShapeQueryExtents)
DECLXSTUB(XdbeQueryExtension)
DECLXSTUB(XShapeOffsetShape)
DECLXSTUB(XdbeFreeVisualInfo)
DECLXSTUB(XShapeSelectInput)
DECLXSTUB(XGEQueryVersion)
DECLXSTUB(XagDestroyApplicationGroup)
DECLXSTUB(XShmQueryVersion)
DECLXSTUB(XSyncCreateAlarm)
DECLXSTUB(XSyncValueEqual)
DECLXSTUB(XSyncSetPriority)
DECLXSTUB(xgeExtRegister)
DECLXSTUB(DPMSQueryExtension)
DECLXSTUB(XagCreateAssociation)
DECLXSTUB(XSyncValueIsPositive)
DECLXSTUB(XagQueryApplicationGroup)
DECLXSTUB(XSetExtensionErrorHandler)
DECLXSTUB(XmbufGetBufferAttributes)
DECLXSTUB(XdbeBeginIdiom)
DECLXSTUB(XSyncMinValue)
DECLXSTUB(XagDestroyAssociation)
DECLXSTUB(XTestFlush)
DECLXSTUB(XSyncGetPriority)
DECLXSTUB(XagCreateNonembeddedApplicationGroup)
DECLXSTUB(XShmPutImage)
DECLXSTUB(XagQueryVersion)
DECLXSTUB(XSecurityAllocXauth)
DECLXSTUB(XSyncDestroyCounter)
DECLXSTUB(XShapeGetRectangles)
DECLXSTUB(XShmDetach)
DECLXSTUB(XSyncSetCounter)
DECLXSTUB(XTestPressButton)
DECLXSTUB(XSyncValueLessThan)
DECLXSTUB(XTestMovePointer)
DECLXSTUB(XSyncValueGreaterThan)
DECLXSTUB(XLbxQueryVersion)
DECLXSTUB(XShapeCombineRegion)
DECLXSTUB(XextCreateExtension)
DECLXSTUB(XShapeCombineRectangles)
DECLXSTUB(XcupStoreColors)
DECLXSTUB(XSecurityRevokeAuthorization)
DECLXSTUB(XdbeGetBackBufferAttributes)
DECLXSTUB(XmbufClearBufferArea)
DECLXSTUB(XLbxGetEventBase)
DECLXSTUB(XShmGetImage)
DECLXSTUB(XTestStopInput)
DECLXSTUB(XShmAttach)
DECLXSTUB(XdbeEndIdiom)
DECLXSTUB(XdbeSwapBuffers)
DECLXSTUB(XmbufGetVersion)
DECLXSTUB(XmbufCreateStereoWindow)
DECLXSTUB(XmbufDestroyBuffers)
DECLXSTUB(XGEQueryExtension)
DECLXSTUB(XSyncValueIsZero)
DECLXSTUB(XShapeCombineMask)
DECLXSTUB(XSyncListSystemCounters)
DECLXSTUB(XSyncCreateCounter)
DECLXSTUB(DPMSCapable)
DECLXSTUB(XcupGetReservedColormapEntries)
DECLXSTUB(XmbufChangeBufferAttributes)
DECLXSTUB(XSyncQueryExtension)
DECLXSTUB(XmbufQueryExtension)
DECLXSTUB(XShapeInputSelected)
DECLXSTUB(XMITMiscQueryExtension)
DECLXSTUB(XShmCreateImage)
DECLXSTUB(XSecurityFreeXauth)
DECLXSTUB(DPMSForceLevel)
DECLXSTUB(XSyncValueHigh32)
DECLXSTUB(XTestPressKey)
DECLXSTUB(XSyncInitialize)
DECLXSTUB(XShmPixmapFormat)
DECLXSTUB(XextRemoveDisplay)
DECLXSTUB(XSyncMaxValue)
DECLXSTUB(XSyncFreeSystemCounterList)
DECLXSTUB(XcupQueryVersion)
DECLXSTUB(XextDestroyExtension)
