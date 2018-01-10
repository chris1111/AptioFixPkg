/** @file
  Header file for AMI EfiPointer protocol definitions.

Copyright (c) 2016, CupertinoNet. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#ifndef _AMI_POINTER_H_
#define _AMI_POINTER_H_

#define AMI_EFIPOINTER_PROTOCOL_GUID \
    { 0x15A10CE7, 0xEAB5, 0x43BF, { 0x90, 0x42, 0x74, 0x43, 0x2E, 0x69, 0x63, 0x77 } }

extern EFI_GUID gAmiEfiPointerProtocolGuid;

typedef struct _AMI_EFIPOINTER_PROTOCOL AMI_EFIPOINTER_PROTOCOL;

// Unless Changed == 1, no data is provided
typedef struct {
  UINT8        Absolute;
  UINT8        One;
  UINT8        Changed;
  UINT8        Reserved;  
  INT32        PositionX;
  INT32        PositionY;
  INT32        PositionZ;
} AMI_POINTER_POSITION_STATE_DATA;

VERIFY_SIZE_OF(AMI_POINTER_POSITION_STATE_DATA, 16);

// Unless Changed == 1, no data is provided
typedef struct {
  UINT8        Changed;
  UINT8        LeftButton;
  UINT8        MiddleButton;
  UINT8        RightButton;
} AMI_POINTER_BUTTON_STATE_DATA;

VERIFY_SIZE_OF(AMI_POINTER_BUTTON_STATE_DATA, 4);

typedef VOID (EFIAPI *AMI_EFIPOINTER_RESET) (
  IN AMI_EFIPOINTER_PROTOCOL  *This
);

typedef VOID (EFIAPI *AMI_EFIPOINTER_GET_BUTTON_STATE) (
  IN AMI_EFIPOINTER_PROTOCOL          *This,
  OUT AMI_POINTER_BUTTON_STATE_DATA   *State
);

typedef VOID (EFIAPI *AMI_EFIPOINTER_GET_POSITION_STATE) (
  IN AMI_EFIPOINTER_PROTOCOL           *This,
  OUT AMI_POINTER_POSITION_STATE_DATA  *State
);

typedef struct _AMI_EFIPOINTER_PROTOCOL {
  AMI_EFIPOINTER_RESET              Reset;
  AMI_EFIPOINTER_GET_POSITION_STATE GetPositionState;
  AMI_EFIPOINTER_GET_BUTTON_STATE   GetButtonState;
} AMI_EFIPOINTER_PROTOCOL;

#endif

