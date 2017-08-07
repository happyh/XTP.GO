package xtp_wrapper

/*
#cgo CFLAGS: -I../../C_porting_XTP/include/XTP -I../../C_porting_XTP/include/CXTPApi
#include <string.h>
#include "xtp_cmessage.h"
#include "LCxtp_trader_api.h"
*/
import "C"

import (
	//"os"
	"unsafe"

	. "leochan007/xtp.go/go_src/queues"
)

//export Go_trader_apiOnOrderEvent
func Go_trader_apiOnOrderEvent(spiPtr C.ulonglong, order_info *C.XTPOrderInfo_, error_info *C.XTPRI) {
	Enqueue(&QueryQueue, getIntValOfPtr(spiPtr), TRADER_ONORDEREVENT, unsafe.Pointer(order_info), unsafe.Pointer(error_info))
}