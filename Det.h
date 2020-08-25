#ifndef __DET_H__
#define __DET_H__
#include <stdint.h>
#include "Std_Types.h"
///////////////////////////////////////////////////////////////////
//error id
typedef uint8_t error;
#define CANIF_E_INVALID_TXPDUID ((error)50)
#define CANIF_E_PARAM_CANID     ((error)10)
#define CANIF_E_INVALID_RXPDUID ((error)60)
//////////////////////////////////////////////////////////////////////
Std_ReturnType Det_ReportError(uint16_t ModuleId,uint8_t InstanceId,uint8_t ApiId,uint8_t ErrorId){
	return E_OK;
}
#endif
