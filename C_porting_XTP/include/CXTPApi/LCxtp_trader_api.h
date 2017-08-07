#ifndef LCXTP_TRADER_API_H
#define LCXTP_TRADER_API_H

#include "common_macro.h"


#include "lcdefine.h"

#ifdef __cplusplus
extern "C" {
#endif



//define extern functions
typedef void (* fn_trader_apiOnDisconnected)(uint64_t session_id, int reason);
typedef void (* fn_trader_apiOnError)(XTPRI *error_info);
typedef void (* fn_trader_apiOnOrderEvent)(XTPOrderInfo_ *order_info, XTPRI *error_info);
typedef void (* fn_trader_apiOnTradeEvent)(XTPTradeReport_ *trade_info);
typedef void (* fn_trader_apiOnCancelOrderError)(XTPOrderCancelInfo_ *cancel_info, XTPRI *error_info);
typedef void (* fn_trader_apiOnQueryOrder)(XTPOrderInfo_ *order_info, XTPRI *error_info, int request_id, bool is_last);
typedef void (* fn_trader_apiOnQueryTrade)(XTPTradeReport_ *trade_info, XTPRI *error_info, int request_id, bool is_last);
typedef void (* fn_trader_apiOnQueryPosition)(XTPQueryStkPositionRsp_ *position, XTPRI *error_info, int request_id, bool is_last);
typedef void (* fn_trader_apiOnQueryAsset)(XTPQueryAssetRsp_ *asset, XTPRI *error_info, int request_id, bool is_last);

extern void Go_trader_apiOnOrderEvent(unsigned long long int spiPtr, XTPOrderInfo_ *order_info, XTPRI *error_info);
extern void Go_trader_apiOnTradeEvent(unsigned long long int spiPtr, XTPTradeReport_ *trade_info);

//register callbacks
LC_XTP_API void * CreateLCTraderSpi();
LC_XTP_API void ReleaseLCTraderSpi(void * * pLC_Spi);
LC_XTP_API void Register_trader_apiOnDisconnectedCallback(void * pLC_Spi, fn_trader_apiOnDisconnected pCallback);
LC_XTP_API void Register_trader_apiOnErrorCallback(void * pLC_Spi, fn_trader_apiOnError pCallback);
LC_XTP_API void Register_trader_apiOnOrderEventCallback(void * pLC_Spi, fn_trader_apiOnOrderEvent pCallback);
LC_XTP_API void Register_trader_apiOnTradeEventCallback(void * pLC_Spi, fn_trader_apiOnTradeEvent pCallback);
LC_XTP_API void Register_trader_apiOnCancelOrderErrorCallback(void * pLC_Spi, fn_trader_apiOnCancelOrderError pCallback);
LC_XTP_API void Register_trader_apiOnQueryOrderCallback(void * pLC_Spi, fn_trader_apiOnQueryOrder pCallback);
LC_XTP_API void Register_trader_apiOnQueryTradeCallback(void * pLC_Spi, fn_trader_apiOnQueryTrade pCallback);
LC_XTP_API void Register_trader_apiOnQueryPositionCallback(void * pLC_Spi, fn_trader_apiOnQueryPosition pCallback);
LC_XTP_API void Register_trader_apiOnQueryAssetCallback(void * pLC_Spi, fn_trader_apiOnQueryAsset pCallback);

//api method porting
LC_XTP_API void * CreateLCTraderApi(uint8_t client_id, const char * save_file_path, XTP_LOG_LEVEL_ log_level);
LC_XTP_API void ReleaseLCTraderApi(void * * pLC_Api);
LC_XTP_API void _trader_apiRelease(void * pLC_Api);
LC_XTP_API void _trader_apiRegisterSpi(void * pLC_Api, void * pLC_Spi);
LC_XTP_API uint8_t _trader_apiGetClientIDByXTPID(void * pLC_Api, uint64_t order_xtp_id);
LC_XTP_API void _trader_apiSubscribePublicTopic(void * pLC_Api, XTP_TE_RESUME_TYPE_ resume_type);
LC_XTP_API void _trader_apiSetSoftwareVersion(void * pLC_Api, const char* version);
LC_XTP_API void _trader_apiSetSoftwareKey(void * pLC_Api, const char* key);
LC_XTP_API uint64_t _trader_apiLogin(void * pLC_Api, const char* ip, int port, const char* user, const char* password, XTP_PROTOCOL_TYPE_ sock_type);
LC_XTP_API int _trader_apiLogout(void * pLC_Api, uint64_t session_id);
LC_XTP_API uint64_t _trader_apiInsertOrder(void * pLC_Api, XTPOrderInsertInfo_ *order, uint64_t session_id);
LC_XTP_API uint64_t _trader_apiCancelOrder(void * pLC_Api, const uint64_t order_xtp_id, uint64_t session_id);
LC_XTP_API int _trader_apiQueryOrderByXTPID(void * pLC_Api, const uint64_t order_xtp_id, uint64_t session_id, int request_id);
LC_XTP_API int _trader_apiQueryOrders(void * pLC_Api, const XTPQueryOrderReq_ *query_param, uint64_t session_id, int request_id);
LC_XTP_API int _trader_apiQueryTradesByXTPID(void * pLC_Api, const uint64_t order_xtp_id, uint64_t session_id, int request_id);
LC_XTP_API int _trader_apiQueryTrades(void * pLC_Api, XTPQueryTraderReq_ *query_param, uint64_t session_id, int request_id);
LC_XTP_API int _trader_apiQueryPosition(void * pLC_Api, const char *ticker, uint64_t session_id, int request_id);
LC_XTP_API int _trader_apiQueryAsset(void * pLC_Api, uint64_t session_id, int request_id);

#ifdef __cplusplus
}
#endif
#endif
