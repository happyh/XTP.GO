#ifndef LCXTP_QUOTE_API_H
#define LCXTP_QUOTE_API_H

#include "common_macro.h"


#include "lcdefine.h"

#ifdef __cplusplus
extern "C" {
#endif



//define extern functions
typedef void (* fn_quote_apiOnDisconnected)(int reason);
typedef void (* fn_quote_apiOnError)(XTPRI *error_info);
typedef void (* fn_quote_apiOnSubMarketData)(XTPST *ticker, XTPRI *error_info, bool is_last);
typedef void (* fn_quote_apiOnUnSubMarketData)(XTPST *ticker, XTPRI *error_info, bool is_last);
typedef void (* fn_quote_apiOnMarketData)(XTPMD *market_data);
typedef void (* fn_quote_apiOnSubOrderBook)(XTPST *ticker, XTPRI *error_info, bool is_last);
typedef void (* fn_quote_apiOnUnSubOrderBook)(XTPST *ticker, XTPRI *error_info, bool is_last);
typedef void (* fn_quote_apiOnOrderBook)(XTPOB *order_book);
typedef void (* fn_quote_apiOnQueryAllTickers)(XTPQSI* ticker_info, XTPRI *error_info, bool is_last);

extern void Go_quote_apiOnSubMarketData(unsigned long long int spiPtr, XTPST *ticker, XTPRI *error_info, bool is_last);
extern void Go_quote_apiOnMarketData(unsigned long long int spiPtr, XTPMD *market_data);

//register callbacks
LC_XTP_API void * CreateLCQuoteSpi();
LC_XTP_API void ReleaseLCQuoteSpi(void * * pLC_Spi);
LC_XTP_API void Register_quote_apiOnDisconnectedCallback(void * pLC_Spi, fn_quote_apiOnDisconnected pCallback);
LC_XTP_API void Register_quote_apiOnErrorCallback(void * pLC_Spi, fn_quote_apiOnError pCallback);
LC_XTP_API void Register_quote_apiOnSubMarketDataCallback(void * pLC_Spi, fn_quote_apiOnSubMarketData pCallback);
LC_XTP_API void Register_quote_apiOnUnSubMarketDataCallback(void * pLC_Spi, fn_quote_apiOnUnSubMarketData pCallback);
LC_XTP_API void Register_quote_apiOnMarketDataCallback(void * pLC_Spi, fn_quote_apiOnMarketData pCallback);
LC_XTP_API void Register_quote_apiOnSubOrderBookCallback(void * pLC_Spi, fn_quote_apiOnSubOrderBook pCallback);
LC_XTP_API void Register_quote_apiOnUnSubOrderBookCallback(void * pLC_Spi, fn_quote_apiOnUnSubOrderBook pCallback);
LC_XTP_API void Register_quote_apiOnOrderBookCallback(void * pLC_Spi, fn_quote_apiOnOrderBook pCallback);
LC_XTP_API void Register_quote_apiOnQueryAllTickersCallback(void * pLC_Spi, fn_quote_apiOnQueryAllTickers pCallback);

//api method porting
LC_XTP_API void * CreateLCQuoteApi(uint8_t client_id, const char * save_file_path, XTP_LOG_LEVEL_ log_level);
LC_XTP_API void ReleaseLCQuoteApi(void * * pLC_Api);
LC_XTP_API void _quote_apiRelease(void * pLC_Api);
LC_XTP_API void _quote_apiRegisterSpi(void * pLC_Api, void * pLC_Spi);
LC_XTP_API int _quote_apiSubscribeMarketData(void * pLC_Api, char *ticker[], int count, XTP_EXCHANGE_TYPE_ exchage_id);
LC_XTP_API int _quote_apiUnSubscribeMarketData(void * pLC_Api, char *ticker[], int count, XTP_EXCHANGE_TYPE_ exchage_id);
LC_XTP_API int _quote_apiSubscribeOrderBook(void * pLC_Api, char *ticker[], int count, XTP_EXCHANGE_TYPE_ exchage_id);
LC_XTP_API int _quote_apiUnSubscribeOrderBook(void * pLC_Api, char *ticker[], int count, XTP_EXCHANGE_TYPE_ exchage_id);
LC_XTP_API int _quote_apiLogin(void * pLC_Api, const char* ip, int port, const char* user, const char* password, XTP_PROTOCOL_TYPE_ sock_type);
LC_XTP_API int _quote_apiLogout(void * pLC_Api);
LC_XTP_API int _quote_apiQueryAllTickers(void * pLC_Api, XTP_EXCHANGE_TYPE_ exchage_id);

#ifdef __cplusplus
}
#endif
#endif
