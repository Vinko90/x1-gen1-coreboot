/*
 *****************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ***************************************************************************
 *
 */

#include "SBPLATFORM.h"
#include "cbtypes.h"


VOID
ReadIO (
  IN       UINT16 Address,
  IN       UINT8 OpFlag,
  IN       VOID* Value
  )
{
  OpFlag = OpFlag & 0x7f;
  switch ( OpFlag ) {
  case AccWidthUint8:
    *(UINT8*)Value = ReadIo8 (Address);
    break;
  case AccWidthUint16:
    *(UINT16*)Value = ReadIo16 (Address);
    break;
  case AccWidthUint32:
    *(UINT32*)Value = ReadIo32 (Address);
    break;
  }
}

VOID
WriteIO (
  IN       UINT16 Address,
  IN       UINT8 OpFlag,
  IN       VOID* Value
  )
{
  OpFlag = OpFlag & 0x7f;
  switch ( OpFlag ) {
  case AccWidthUint8:
    WriteIo8 (Address, *(UINT8*)Value);
    break;
  case AccWidthUint16:
    WriteIo16 (Address, *(UINT16*)Value);
    break;
  case AccWidthUint32:
    WriteIo32 (Address, *(UINT32*)Value);
    break;
  }
}

VOID
RWIO (
  IN       UINT16 Address,
  IN       UINT8 OpFlag,
  IN       UINT32 Mask,
  IN       UINT32 Data
  )
{
  UINT32 Result;
  ReadIO (Address, OpFlag, &Result);
  Result = (Result & Mask) | Data;
  WriteIO (Address, OpFlag, &Result);
}
