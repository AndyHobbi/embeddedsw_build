/******************************************************************************
* Copyright (c) 2020 - 2021 Xilinx, Inc. All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/*****************************************************************************/
/**
* @file xbir_qspi.h
*
* This is the qspi header file which contains definitions for the qspi.
*
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who    Date       Changes
* ----- ---- ---------- -------------------------------------------------------
* 1.00  bsv   07/02/20   First release
*
* </pre>
*
******************************************************************************/

#ifndef XBIR_QSPI_H
#define XBIR_QSPI_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/

/************************** Constant Definitions *****************************/

/**************************** Type Definitions *******************************/

/***************** Macros (Inline Functions) Definitions *********************/

/************************** Function Prototypes ******************************/
int Xbir_QspiInit (void);
int Xbir_QspiRead (u32 SrcAddr, u8 *DestAddr, u32 Length);
int Xbir_QspiWrite(u32 Addr, u8 *WrBuff, u32 Len);
int Xbir_QspiFlashErase(u32 Address, u32 Length);
int Xbir_QspiWrite(u32 Address, u8 *WrBuffer, u32 Length);
void Xbir_QspiGetPageSize(u32 *SectorSize, u16 *PageSize);

#ifdef __cplusplus
}
#endif

#endif  /* XBIR_QSPI_H */
