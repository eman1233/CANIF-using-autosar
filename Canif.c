#include "canif.h"
#include <stdint.h>
#include "Det.h"
#include "Dem.h"
#include "MemMap.h"
#include "CanIf_Cbk.h"
//////////////////////////////////////////////////////////////
//parmeter
#define valid 1
#define invalid 0
#define initilize 1
#define not_initilize 0
#define PduIdmax 255
 PduIdType CanL_SDUId;
/**************************************************************************************/
//implement           :CanIf_ReadTxNotifStatus
//service             :SWS_CANIF_00202
//description         :This service returns the confirmation status 
//                    :(confirmation occurred or
//                    :not) of a specific static or dynamic CAN Tx L-PDU, requested by the
//                    :CanIfTxSduId
//parameter in        :CanIfTxSduId
//parameter out       :non
//parameter inout     :non
//return value        :CanIf_NotifStatusType
//Reentrancy          :Non Reentrant
/**************************************************************************************/
	/*[SWS_CANIF_00335] d Configuration of CanIf_ReadTxNotifyStatus(): This API
    can be enabled or disabled at pre-compile time configuration globally by the parameter
    CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API*/
 
	/*[SWS_CANIF_00393] d If configuration parameters
   CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API (ECUC_CanIf_00609) and
   CANIF_TXPDU_READ_NOTIFYSTATUS (ECUC_CanIf_00589) for the transmitted
   L-SDU are set to TRUE, and if CanIf_ReadTxNotifStatus() is called, the CanIf
   shall reset the notification status for the transmitted L-SDU.*/
	 
#if((CanIfPublicReadTxPduNotifyStatusApi==STD_ON)&&(CanIfTxPduReadNotifyStatus==STD_ON))
CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId){
	CanIf_NotifStatusType Status;
	
	#if(CanIfDevErrorDetect==STD_ON)
	
	/*[SWS_CANIF_00331] d If parameter CanIfTxSduId of
    CanIf_ReadTxNotifStatus() is out of range or if no status information was
    configured for this CAN Tx L-SDU, CanIf shall report development error code
    CANIF_E_INVALID_TXPDUID to the Det_ReportError service of the DET
    when CanIf_ReadTxNotifStatus() is called.*/
	
	if(CanIfTxSduId>PduIdmax)
		Det_ReportError(modulid,instanceId,CanIf_ReadTxNotifStatus_Api,CANIF_E_INVALID_TXPDUID);
	#endif
	if(CanIfTxSduId==CanL_SDUId)
		Status=CANIF_TX_RX_NOTIFICATION;
	else
		Status=CANIF_NO_NOTIFICATION;
	return Status;
}
#endif

/**************************************************************************************/
//implement           :CanIf_ReadRxNotifStatus
//service             :SWS_CANIF_00230
//description         :This service returns the indication 
//                    :status (indication occurred or not) of a
//                    :specific CAN Rx L-PDU, requested by the CanIfRxSduId.
//                    :CanIfTxSduId
//parameter in        :CanIfRxSduId
//parameter out       :none
//parameter inout     :none
//return value        :CanIf_NotifStatusType
//Reentrancy          :Non Reentrant
/**************************************************************************************/
	/*[SWS_CANIF_00394] d If configuration parameters
  CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API (ECUC_CanIf_00608) and
  CANIF_RXPDU_READ_NOTIFYSTATUS (ECUC_CanIf_00595) are set to TRUE, and
  if CanIf_ReadRxNotifStatus() is called, then CanIf shall reset the notification
  status for the received L-SDU.*/

/*[SWS_CANIF_00340] d Configuration of CanIf_ReadRxNotifStatus(): This API
can be enabled or disabled at pre-compile time configuration globally by the parameter
CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API (see ECUC_CanIf_00608).*/

#if((CanIfPublicReadRxPduNotifyStatusApi==STD_ON)&&(CanIfRxPduReadNotifyStatus==STD_ON))
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId){
	CanIf_NotifStatusType Status;
	#if(CanIfDevErrorDetect==STD_ON)
  /*If parameter CanIfRxSduId of
    CanIf_ReadRxNotifStatus() is out of range or if status for CanRxPduId
    was requested whereas CANIF_READRXPDU_DATA_API is disabled or if no status
    information was configured for this CAN Rx L-SDU, CanIf shall report development
    error code CANIF_E_INVALID_RXPDUID to the Det_ReportError service of
    the DET, when CanIf_ReadRxNotifStatus() is called.*/
	if(CanIfRxSduId>PduIdmax)
		Det_ReportError(modulid,instanceId,CanIf_ReadRxNotifStatus_Api,CANIF_E_INVALID_RXPDUID);
	#endif
		if(CanIfRxSduId==CanL_SDUId)
		Status=CANIF_TX_RX_NOTIFICATION;
	else
		Status=CANIF_NO_NOTIFICATION;
	return Status;
}
#endif
