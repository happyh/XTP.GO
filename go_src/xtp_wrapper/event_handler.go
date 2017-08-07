package xtp_wrapper

/*
#cgo CFLAGS: -I../../C_porting_XTP/include/XTP -I../../C_porting_XTP/include/CXTPApi
#include <string.h>
#include "xtp_cmessage.h"
#include "LCxtp_quote_api.h"
#include "LCxtp_trader_api.h"
*/
import "C"

import (
	"fmt"

	. "leochan007/xtp.go/go_src/defs"
	. "leochan007/xtp.go/go_src/queues"
)

func query_handle() {
	defer close(QueryQueue)
	for {
		select {
		case data, ok := <-QueryQueue:
			if !ok {
				continue
			}
			switch data.Type {
			default:
			}
		}
		if needToClose {
			break
		}
	}
}

func quote_handle() {
	defer close(QuoteQueue)
	for {
		select {
		case data, ok := <-QuoteQueue:
			if !ok {
				continue
			}
			switch data.Type {
			case MD_ONMARKETDATA:
				//ctpLogger.Infof("MD_ONMARKETDATA")
				market_data := (*MarketData)(data.Data)
				ctpLogger.Infof("%v\n", market_data)
			default:
			}
		}
		if needToClose {
			break
		}
	}
}

func trader_handle() {
	defer close(TraderQueue)
	for {
		select {
		case data, ok := <-TraderQueue:
			if !ok {
				continue
			}
			switch data.Type {
			case TRADER_ONORDEREVENT:
				fmt.Println("TRADER_ONORDEREVENT!")
				order_info := (*C.XTPOrderInfo_)(data.Data)
				fmt.Printf("[%v] [%v] [%v] market:%v\n", order_info.order_xtp_id, order_info.order_client_id,
					GetGoString(&order_info.ticker[0]),
					(XTP_EXCHANGE_TYPE)(order_info.market))
			default:
			}
		}
		if needToClose {
			break
		}
	}
}
