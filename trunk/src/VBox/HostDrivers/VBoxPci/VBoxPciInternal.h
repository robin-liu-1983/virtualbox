/* $Id$ */
/** @file
 * VBoxPci - PCI driver (Host), Internal Header.
 */

/*
 * Copyright (C) 2011 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef ___VBoPciInternal_h___
#define ___VBoxPciInternal_h___

#include <VBox/sup.h>
#include <VBox/rawpci.h>
#include <iprt/semaphore.h>
#include <iprt/assert.h>


RT_C_DECLS_BEGIN

/* Forward declaration. */
typedef struct VBOXRAWPCIGLOBALS *PVBOXRAWPCIGLOBALS;
typedef struct VBOXRAWPCIINS     *PVBOXRAWPCIINS;

/**
 * The per-instance data of the VBox raw PCI interface.
 *
 * This is data associated with a host PCI card which
 * the filter driver has been or may be attached to. When possible it is
 * attached dynamically, but this may not be possible on all OSes so we have
 * to be flexible about things.
 *
 */
typedef struct VBOXRAWPCIINS
{
    /** Pointer to the globals. */
    PVBOXRAWPCIGLOBALS pGlobals;
    /** The spinlock protecting the state variables and host interface handle. */
    RTSPINLOCK         hSpinlock;
    /** Pointer to the next device in the list. */
    PVBOXRAWPCIINS     pNext;
    /** Reference count. */
    uint32_t volatile cRefs;

    /* Host PCI address of this device. */
    uint32_t           HostPciAddress;

#ifdef RT_OS_LINUX
    struct pci_dev  *  pPciDev;
#endif

    /** The session this interface is associated with. */
    PSUPDRVSESSION     pSession;
    /** The SUPR0 object id. */
    void               *pvObj;

    /** Port, given to the outside world. */
    RAWPCIDEVPORT      DevPort;

    PFNRAWPCIISR       pfnIrqHandler;
    void              *pIrqContext;
} VBOXRAWPCIINS;

/**
 * The global data of the VBox PCI driver.
 *
 * This contains the bit required for communicating with support driver, VBoxDrv
 * (start out as SupDrv).
 */
typedef struct VBOXRAWPCIGLOBALS
{
    /** Mutex protecting the list of instances and state changes. */
    RTSEMFASTMUTEX hFastMtx;

    /** Pointer to a list of instance data. */
    PVBOXRAWPCIINS pInstanceHead;

    /** The raw PCI interface factory. */
    RAWPCIFACTORY RawPciFactory;
    /** The SUPDRV component factory registration. */
    SUPDRVFACTORY SupDrvFactory;
    /** The number of current factory references. */
    int32_t volatile cFactoryRefs;
    /** Whether the IDC connection is open or not.
     * This is only for cleaning up correctly after the separate IDC init on Windows. */
    bool fIDCOpen;
    /** The SUPDRV IDC handle (opaque struct). */
    SUPDRVIDCHANDLE SupDrvIDC;
#ifdef RT_OS_LINUX
    struct module    * pciStubModule;
#endif

} VBOXRAWPCIGLOBALS;

DECLHIDDEN(int)  vboxPciInit(PVBOXRAWPCIGLOBALS pGlobals);
DECLHIDDEN(void) vboxPciShutdown(PVBOXRAWPCIGLOBALS pGlobals);

DECLHIDDEN(int)  vboxPciOsDevInit  (PVBOXRAWPCIINS pIns, uint32_t fFlags);
DECLHIDDEN(int)  vboxPciOsDevDeinit(PVBOXRAWPCIINS pIns, uint32_t fFlags);

DECLHIDDEN(int)  vboxPciOsDevGetRegionInfo(PVBOXRAWPCIINS pIns,
                                           int32_t        iRegion,
                                           RTHCPHYS       *pRegionStart,
                                           uint64_t       *pu64RegionSize,
                                           bool           *pfPresent,
                                           uint32_t       *pfFlags);
DECLHIDDEN(int)  vboxPciOsDevMapRegion(PVBOXRAWPCIINS pIns,
                                       int32_t        iRegion,
                                       RTHCPHYS       pRegionStart,
                                       uint64_t       u64RegionSize,
                                       uint32_t       fFlags,
                                       RTR0PTR        *pRegionBase);
DECLHIDDEN(int)  vboxPciOsDevUnmapRegion(PVBOXRAWPCIINS pIns,
                                         int32_t        iRegion,
                                         RTHCPHYS       RegionStart,
                                         uint64_t       u64RegionSize,
                                         RTR0PTR        RegionBase);

DECLHIDDEN(int)  vboxPciOsDevPciCfgWrite(PVBOXRAWPCIINS pIns, uint32_t Register, PCIRAWMEMLOC *pValue);
DECLHIDDEN(int)  vboxPciOsDevPciCfgRead (PVBOXRAWPCIINS pIns, uint32_t Register, PCIRAWMEMLOC *pValue);

DECLHIDDEN(int)  vboxPciOsDevRegisterIrqHandler  (PVBOXRAWPCIINS pIns, PFNRAWPCIISR pfnHandler, void* pIrqContext, int32_t *piHostIrq);
DECLHIDDEN(int)  vboxPciOsDevUnregisterIrqHandler(PVBOXRAWPCIINS pIns, int32_t iHostIrq);

RT_C_DECLS_END

#endif
