#ifndef _XOMS_API_STRUCT_H_
#define _XOMS_API_STRUCT_H_

#include "xtp_api_data_type.h"


//=====================�ͻ��˽ӿڶ���=================================
///�¶�������
typedef struct XTPOrderInsertInfo
{
    ///XTPϵͳ����ID�������û���д����XTPϵͳ��Ψһ
    uint64_t                order_xtp_id;
    ///�������ã��ɿͻ��Զ���
    uint32_t	            order_client_id;
    ///��Լ���� �ͻ������󲻴��ո���'\0'��β
    char                    ticker[XTP_TICKER_LEN];
    ///�����г�
    XTP_MARKET_TYPE_         market;
    ///�۸�
    double                  price;
    ///ֹ��ۣ������ֶΣ�
    double                  stop_price;
    ///����(��Ʊ��λΪ�ɣ���ع���λΪ��)
    int64_t                 quantity;
    ///�����۸�
    XTP_PRICE_TYPE_          price_type;
    ///��������
    XTP_SIDE_TYPE_           side;
	///ҵ������
	XTP_BUSINESS_TYPE_       business_type;
    
 } XTPOrderInsertInfo_;


///����ʧ����Ӧ��Ϣ
typedef struct XTPOrderCancelInfo
{
    ///����XTPID
    uint64_t                 order_cancel_xtp_id;
    ///ԭʼ����XTPID
    uint64_t                 order_xtp_id;
} XTPOrderCancelInfo_;


///������Ӧ�ṹ��
typedef struct XTPOrderInfo
{
    ///XTPϵͳ����ID����XTPϵͳ��Ψһ
	uint64_t                order_xtp_id;
	///�������ã��û��Զ���
	uint32_t	            order_client_id;
    ///�����������ã��û��Զ��壨��δʹ�ã�
    uint32_t                order_cancel_client_id;
    ///������XTPϵͳ�е�id����XTPϵͳ��Ψһ
    uint64_t                order_cancel_xtp_id;
	///��Լ����
	char                    ticker[XTP_TICKER_LEN];
	///�����г�
	XTP_MARKET_TYPE_         market;
	///�۸�
	double                  price;
	///�������˶����ı�������
	int64_t                 quantity;
	///�����۸�����
	XTP_PRICE_TYPE_          price_type;
	///��������
	XTP_SIDE_TYPE_           side;
	///ҵ������
	XTP_BUSINESS_TYPE_       business_type;
	///��ɽ�������Ϊ�˶����ۼƳɽ�����
	int64_t                 qty_traded;
	///ʣ���������������ɹ�ʱ����ʾ��������
	int64_t                 qty_left;
	///ί��ʱ�䣬��ʽΪYYYYMMDDHHMMSSsss
	int64_t                 insert_time;
	///����޸�ʱ�䣬��ʽΪYYYYMMDDHHMMSSsss
	int64_t                 update_time;
	///����ʱ�䣬��ʽΪYYYYMMDDHHMMSSsss
	int64_t                 cancel_time;
	///�ɽ���Ϊ�˶����ĳɽ��ܽ��
	double                  trade_amount;
	///���ر������ OMS���ɵĵ��ţ�����ͬ��order_xtp_id��Ϊ�������������̵ĵ���
	char                    order_local_id[XTP_LOCAL_ORDER_LEN];
	///����״̬��������Ӧ��û�в��ֳɽ�״̬�����ͣ��ڲ�ѯ��������У����в��ֳɽ�״̬
	XTP_ORDER_STATUS_TYPE_   order_status;
	///�����ύ״̬��OMS�ڲ�ʹ�ã��û��������
	XTP_ORDER_SUBMIT_STATUS_TYPE_   order_submit_status;
	///��������
	TXTPOrderTypeType       order_type;
    
} XTPOrderInfo_;



///�����ɽ��ṹ��
typedef struct XTPTradeReport
{
    ///XTPϵͳ����ID���˳ɽ��ر���صĶ���ID����XTPϵͳ��Ψһ
    uint64_t                 order_xtp_id;
    ///��������
    uint32_t                 order_client_id;
    ///��Լ����
    char                     ticker[XTP_TICKER_LEN];
    ///�����г�
    XTP_MARKET_TYPE_          market;
    ///�����ţ�����XTPID�󣬸��ֶ�ʵ�ʺ�order_xtp_id�ظ����ӿ�����ʱ������
    uint64_t                 local_order_id;
    ///�ɽ���ţ����Ψһ���Ͻ���ÿ�ʽ���Ψһ��������2�ʳɽ��ر�ӵ����ͬ��exec_id���������Ϊ�˱ʽ����Գɽ�
    char                    exec_id[XTP_EXEC_ID_LEN];
    ///�۸񣬴˴γɽ��ļ۸�
    double                   price;
    ///�������˴γɽ��������������ۼ�����
    int64_t                  quantity;
    ///�ɽ�ʱ�䣬��ʽΪYYYYMMDDHHMMSSsss
    int64_t                  trade_time;
    ///�ɽ����˴γɽ����ܽ�� = price*quantity
    double                   trade_amount;
    ///�ɽ���� --�ر���¼�ţ�ÿ��������Ψһ,report_index+market�ֶο������Ψһ��ʶ��ʾ�ɽ��ر�
    uint64_t                 report_index;
    ///������� --���������ţ��Ͻ���Ϊ�գ�����д��ֶ�
    char                     order_exch_id[XTP_ORDER_EXCH_LEN];
    ///�ɽ�����  --�ɽ��ر��е�ִ������
    TXTPTradeTypeType        trade_type;
    ///��������
    XTP_SIDE_TYPE_            side;
	///ҵ������
	XTP_BUSINESS_TYPE_        business_type;
    ///����������Ա���� 
    char                     branch_pbu[XTP_BRANCH_PBU_LEN];
    
} XTPTradeReport_;


//////////////////////////////////////////////////////////////////////////
///������ѯ
//////////////////////////////////////////////////////////////////////////
///������ѯ����-������ѯ
typedef struct XTPQueryOrderReq
{
    ///֤ȯ���룬����Ϊ�գ����Ϊ�գ���Ĭ�ϲ�ѯʱ����ڵ����гɽ��ر�
    char      ticker[XTP_TICKER_LEN];
    ///��ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰ������0��
    int64_t   begin_time;
    ///��ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰʱ��
    int64_t   end_time;  
} XTPQueryOrderReq_;

///������ѯ��Ӧ�ṹ��
//typedef struct XTPOrderInfo XTPQueryOrderRsp;


//////////////////////////////////////////////////////////////////////////
///�ɽ��ر���ѯ
//////////////////////////////////////////////////////////////////////////
///��ѯ�ɽ���������-����ִ�б�Ų�ѯ�������ֶΣ�
typedef struct XTPQueryReportByExecIdReq
{
    ///XTP����ϵͳID
    uint64_t  order_xtp_id;  
    ///�ɽ�ִ�б��
    char  exec_id[XTP_EXEC_ID_LEN];
} XTPQueryReportByExecIdReq_;

///��ѯ�ɽ��ر�����-��ѯ����
typedef struct XTPQueryTraderReq
{
    ///֤ȯ���룬����Ϊ�գ����Ϊ�գ���Ĭ�ϲ�ѯʱ����ڵ����гɽ��ر�
    char      ticker[XTP_TICKER_LEN];
    ///��ʼʱ�䣬��ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰ������0��
    int64_t   begin_time; 
    ///����ʱ�䣬��ʽΪYYYYMMDDHHMMSSsss��Ϊ0��Ĭ�ϵ�ǰʱ��
    int64_t   end_time;  
} XTPQueryTraderReq_;

///�ɽ��ر���ѯ��Ӧ�ṹ��
//typedef struct XTPTradeReport  XTPQueryTradeRsp;



//////////////////////////////////////////////////////////////////////////
///�˻��ʽ��ѯ��Ӧ�ṹ��
//////////////////////////////////////////////////////////////////////////
typedef struct XTPQueryAssetRsp
{
	///���ʲ�(=�����ʽ� + ֤ȯ�ʲ���ĿǰΪ0��+ Ԥ�۵��ʽ�)
	double total_asset;
    ///�����ʽ�
    double buying_power;
	///֤ȯ�ʲ��������ֶΣ�ĿǰΪ0��
	double security_asset;
    ///�ۼ�����ɽ�֤ȯռ���ʽ�
    double fund_buy_amount;
    ///�ۼ�����ɽ����׷���
    double fund_buy_fee;
    ///�ۼ������ɽ�֤ȯ�����ʽ�
    double fund_sell_amount;
    ///�ۼ������ɽ����׷���
    double fund_sell_fee;
	///XTPϵͳԤ�۵��ʽ𣨰�����������ƱʱԤ�۵Ľ����ʽ�+Ԥ�������ѣ�
	double withholding_amount;
} XTPQueryAssetRsp_;



//////////////////////////////////////////////////////////////////////////
///��ѯ��Ʊ�ֲ����
//////////////////////////////////////////////////////////////////////////
typedef struct XTPQueryStkPositionRsp
{
    ///֤ȯ����
    char                ticker[XTP_TICKER_LEN]; 
    ///֤ȯ����
    char                ticker_name[XTP_TICKER_NAME_LEN]; 
    ///�����г�
    XTP_MARKET_TYPE_     market;
    ///��ǰ�ֲ�
    int64_t             total_qty; 
    ///���ùɷ���
    int64_t             sellable_qty; 
    ///����ɱ���
    double              avg_price;           
    ///����ӯ���������ֶΣ�
    double              unrealized_pnl;        
} XTPQueryStkPositionRsp_;



/////////////////////////////////////////////////////////////////////////
///�ʽ���ת��ˮ֪ͨ
/////////////////////////////////////////////////////////////////////////
typedef struct XTPFundTransferNotice
{
    ///�ʽ���ת���
    uint64_t	            serial_id;
    ///��ת����
    XTP_FUND_TRANSFER_TYPE_	transfer_type;
    ///���
    double	                amount;
    ///������� 
    XTP_FUND_OPER_STATUS_    oper_status;
    ///����ʱ��
    uint64_t	            transfer_time;
} XTPFundTransferNotice_;





/////////////////////////////////////////////////////////////////////////
///�ʽ���ת��ˮ��ѯ��������Ӧ
/////////////////////////////////////////////////////////////////////////
typedef struct XTPQueryFundTransferLogReq {
    ///�ʽ���ת���
    uint64_t	serial_id;

} XTPQueryFundTransferLogReq_;

/////////////////////////////////////////////////////////////////////////
///�ʽ���ת��ˮ��¼�ṹ��
/////////////////////////////////////////////////////////////////////////
//typedef struct XTPFundTransferNotice XTPFundTransferLog;








#endif //_XOMS_API_STRUCT_H_

