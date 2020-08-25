#ifndef __CANIF_H__
#define __CANIF_H__
#include "CanIf_Types.h"
#include "Can_GenralTypes.h"
#include <stdint.h>
/////////////////////////////////////////////////////////////////////
//implement CanIf_NotifStatusType
typedef uint8_t CanIf_NotifStatusType;
#define CANIF_TX_RX_NOTIFICATION  ((CanIf_NotifStatusType)0x01)
#define CANIF_NO_NOTIFICATION     ((CanIf_NotifStatusType)0x00)
////////////////////////////////////////////////////////////////////
//API
CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId);
////////////////////////////////////////////////////////////////////
//ApiId
typedef uint8_t API;
#define CanIf_ReadTxNotifStatus_Api   ((API)0x07)
#define CanIf_ReadRxNotifStatus_Api   ((API)0x08)
///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//modulid
#define modulid 0x060
//////////////////////////////////////////////////////////////////
//InstanceId
#define instanceId 0
#endif
