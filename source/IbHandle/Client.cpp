#include "Client.h"
#include <iostream>
#include <cstdio>

Client::Client() :
    m_osSignal(2000),
    m_clientSocket(new EClientSocket(this, &m_osSignal)),
    m_reader(0)
{}

//------------------------------------------------------------------------------

Client::~Client()
{
    if(m_reader)
    {
        delete m_reader;
    }

    delete m_clientSocket;
}

//------------------------------------------------------------------------------

bool Client::connect(const char *host, unsigned int port, int clientId)
{
    // trying to connect
    printf( "Connecting to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

    //! [connect]
    bool bRes = m_clientSocket->eConnect( host, port, clientId);
    //! [connect]

    if (bRes) {
        printf( "Connected to %s:%d clientId:%d\n",
                m_clientSocket->host().c_str(),
                m_clientSocket->port(),
                clientId);
        //! [ereader]
        m_reader = new EReader(m_clientSocket, &m_osSignal);
        m_reader->start();
        //! [ereader]
    }
    else
        printf( "Cannot connect to %s:%d clientId:%d\n",
                m_clientSocket->host().c_str(),
                m_clientSocket->port(),
                clientId);

    return bRes;
}

//------------------------------------------------------------------------------

void Client::disconnect() const
{
    m_clientSocket->eDisconnect();

    printf ( "Disconnected\n");
}

//------------------------------------------------------------------------------

void Client::tickPrice(TickerId tickerId, TickType field, double price, const TickAttrib &attrib)
{

}

//------------------------------------------------------------------------------

void Client::tickSize(TickerId tickerId, TickType field, int size)
{

}

//------------------------------------------------------------------------------

void Client::tickOptionComputation(TickerId tickerId, TickType tickType, double impliedVol, double delta, double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice)
{

}

//------------------------------------------------------------------------------

void Client::tickGeneric(TickerId tickerId, TickType tickType, double value)
{

}

//------------------------------------------------------------------------------

void Client::tickString(TickerId tickerId, TickType tickType, const std::string &value)
{

}

//------------------------------------------------------------------------------

void Client::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const std::string &formattedBasisPoints, double totalDividends, int holdDays, const std::string &futureLastTradeDate, double dividendImpact, double dividendsToLastTradeDate)
{

}

//------------------------------------------------------------------------------

void Client::orderStatus(OrderId orderId, const std::string &status, double filled, double remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, const std::string &whyHeld, double mktCapPrice)
{

}

//------------------------------------------------------------------------------

void Client::openOrder(OrderId orderId, const Contract &, const Order &, const OrderState &)
{

}

//------------------------------------------------------------------------------

void Client::openOrderEnd()
{

}

//------------------------------------------------------------------------------

void Client::winError(const std::string &str, int lastError)
{

}

//------------------------------------------------------------------------------

void Client::connectionClosed()
{

}

//------------------------------------------------------------------------------

void Client::updateAccountValue(const std::string &key, const std::string &val, const std::string &currency, const std::string &accountName)
{

}

//------------------------------------------------------------------------------

void Client::updatePortfolio(const Contract &contract, double position, double marketPrice, double marketValue, double averageCost, double unrealizedPNL, double realizedPNL, const std::string &accountName)
{

}

//------------------------------------------------------------------------------

void Client::updateAccountTime(const std::string &timeStamp)
{

}

//------------------------------------------------------------------------------

void Client::accountDownloadEnd(const std::string &accountName)
{

}

//------------------------------------------------------------------------------

void Client::nextValidId(OrderId orderId)
{

}

//------------------------------------------------------------------------------

void Client::contractDetails(int reqId, const ContractDetails &contractDetails)
{

}

//------------------------------------------------------------------------------

void Client::bondContractDetails(int reqId, const ContractDetails &contractDetails)
{

}

//------------------------------------------------------------------------------

void Client::contractDetailsEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::execDetails(int reqId, const Contract &contract, const Execution &execution)
{

}

//------------------------------------------------------------------------------

void Client::execDetailsEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::error(const int id, const int errorCode, const std::string errorString)
{

}

//------------------------------------------------------------------------------

void Client::updateMktDepth(TickerId id, int position, int operation, int side, double price, int size)
{

}

//------------------------------------------------------------------------------

void Client::updateMktDepthL2(TickerId id, int position, std::string marketMaker, int operation, int side, double price, int size)
{

}

//------------------------------------------------------------------------------

void Client::updateNewsBulletin(int msgId, int msgType, const std::string &newsMessage, const std::string &originExch)
{

}

//------------------------------------------------------------------------------

void Client::managedAccounts(const std::string &accountsList)
{

}

//------------------------------------------------------------------------------

void Client::receiveFA(faDataType pFaDataType, const std::string &cxml)
{

}

//------------------------------------------------------------------------------

void Client::historicalData(TickerId reqId, Bar bar)
{

}

//------------------------------------------------------------------------------

void Client::historicalDataEnd(int reqId, std::string startDateStr, std::string endDateStr)
{

}

//------------------------------------------------------------------------------

void Client::scannerParameters(const std::string &xml)
{

}

//------------------------------------------------------------------------------

void Client::scannerData(int reqId, int rank, const ContractDetails &contractDetails, const std::string &distance, const std::string &benchmark, const std::string &projection, const std::string &legsStr)
{

}

//------------------------------------------------------------------------------

void Client::scannerDataEnd(int reqId)
{

}

//------------------------------------------------------------------------------


void Client::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close, long volume, double wap, int count)
{

}

//------------------------------------------------------------------------------

void Client::currentTime(long time)
{

}

//------------------------------------------------------------------------------

void Client::fundamentalData(TickerId reqId, const std::string &data)
{

}

//------------------------------------------------------------------------------

void Client::deltaNeutralValidation(int reqId, const UnderComp &underComp)
{

}

//------------------------------------------------------------------------------

void Client::tickSnapshotEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::marketDataType(TickerId reqId, int marketDataType)
{

}

//------------------------------------------------------------------------------

void Client::commissionReport(const CommissionReport &commissionReport)
{

}

//------------------------------------------------------------------------------

void Client::position(const std::string &account, const Contract &contract, double position, double avgCost)
{

}

//------------------------------------------------------------------------------

void Client::positionEnd()
{

}

//------------------------------------------------------------------------------

void Client::accountSummary(int reqId, const std::string &account, const std::string &tag, const std::string &value, const std::string &curency)
{

}

//------------------------------------------------------------------------------

void Client::accountSummaryEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::verifyMessageAPI(const std::string &apiData)
{

}

//------------------------------------------------------------------------------

void Client::verifyCompleted(bool isSuccessful, const std::string &errorText)
{

}

//------------------------------------------------------------------------------

void Client::displayGroupList(int reqId, const std::string &groups)
{

}

//------------------------------------------------------------------------------

void Client::displayGroupUpdated(int reqId, const std::string &contractInfo)
{

}

//------------------------------------------------------------------------------

void Client::verifyAndAuthMessageAPI(const std::string &apiData, const std::string &xyzChallange)
{

}

//------------------------------------------------------------------------------

void Client::verifyAndAuthCompleted(bool isSuccessful, const std::string &errorText)
{

}

//------------------------------------------------------------------------------

void Client::connectAck()
{

}

//------------------------------------------------------------------------------

void Client::positionMulti(int reqId, const std::string &account, const std::string &modelCode, const Contract &contract, double pos, double avgCost)
{

}

//------------------------------------------------------------------------------

void Client::positionMultiEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::accountUpdateMulti(int reqId, const std::string &account, const std::string &modelCode, const std::string &key, const std::string &value, const std::string &currency)
{

}

//------------------------------------------------------------------------------

void Client::accountUpdateMultiEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::securityDefinitionOptionalParameter(int reqId, const std::string &exchange, int underlyingConId, const std::string &tradingClass, const std::string &multiplier, std::set<std::string> expirations, std::set<double> strikes)
{

}

//------------------------------------------------------------------------------

void Client::securityDefinitionOptionalParameterEnd(int reqId)
{

}

//------------------------------------------------------------------------------

void Client::softDollarTiers(int reqId, const std::vector<SoftDollarTier> &tiers)
{

}

//------------------------------------------------------------------------------

void Client::familyCodes(const std::vector<FamilyCode> &familyCodes)
{

}

//------------------------------------------------------------------------------

void Client::symbolSamples(int reqId, const std::vector<ContractDescription> &contractDescriptions)
{

}

//------------------------------------------------------------------------------

void Client::mktDepthExchanges(const std::vector<DepthMktDataDescription> &depthMktDataDescriptions)
{

}

//------------------------------------------------------------------------------

void Client::tickNews(int tickerId, time_t timeStamp, const std::string &providerCode, const std::string &articleId, const std::string &headline, const std::string &extraData)
{

}

//------------------------------------------------------------------------------

void Client::smartComponents(int reqId, SmartComponentsMap theMap)
{

}

//------------------------------------------------------------------------------

void Client::tickReqParams(int tickerId, double minTick, std::string bboExchange, int snapshotPermissions)
{

}

//------------------------------------------------------------------------------

void Client::newsProviders(const std::vector<NewsProvider> &newsProviders)
{

}

//------------------------------------------------------------------------------

void Client::newsArticle(int requestId, int articleType, const std::string &articleText)
{

}

//------------------------------------------------------------------------------

void Client::historicalNews(int requestId, const std::string &time, const std::string &providerCode, const std::string &articleId, const std::string &headline)
{

}

//------------------------------------------------------------------------------

void Client::historicalNewsEnd(int requestId, bool hasMore)
{

}

//------------------------------------------------------------------------------

void Client::headTimestamp(int reqId, const std::string &headTimestamp)
{

}

//------------------------------------------------------------------------------

void Client::histogramData(int reqId, HistogramDataVector data)
{

}

//------------------------------------------------------------------------------

void Client::historicalDataUpdate(TickerId reqId, Bar bar)
{

}

//------------------------------------------------------------------------------

void Client::rerouteMktDataReq(int reqId, int conid, const std::string &exchange)
{

}

//------------------------------------------------------------------------------

void Client::rerouteMktDepthReq(int reqId, int conid, const std::string &exchange)
{

}

//------------------------------------------------------------------------------

void Client::marketRule(int marketRuleId, const std::vector<PriceIncrement> &priceIncrements)
{

}

//------------------------------------------------------------------------------

void Client::pnl(int reqId, double dailyPnL, double unrealizedPnL, double realizedPnL)
{

}

//------------------------------------------------------------------------------

void Client::pnlSingle(int reqId, int pos, double dailyPnL, double unrealizedPnL, double realizedPnL, double value)
{

}

//------------------------------------------------------------------------------

void Client::historicalTicks(int reqId, const std::vector<HistoricalTick> &ticks, bool done)
{

}

//------------------------------------------------------------------------------

void Client::historicalTicksBidAsk(int reqId, const std::vector<HistoricalTickBidAsk> &ticks, bool done)
{

}

//------------------------------------------------------------------------------

void Client::historicalTicksLast(int reqId, const std::vector<HistoricalTickLast> &ticks, bool done)
{

}

//------------------------------------------------------------------------------

void Client::tickByTickAllLast(int reqId, int tickType, time_t time, double price, int size, const TickAttrib &attribs, const std::string &exchange, const std::string &specialConditions)
{

}

//------------------------------------------------------------------------------

void Client::tickByTickBidAsk(int reqId, time_t time, double bidPrice, double askPrice, int bidSize, int askSize, const TickAttrib &attribs)
{

}

//------------------------------------------------------------------------------

void Client::tickByTickMidPoint(int reqId, time_t time, double midPoint)
{

}

//------------------------------------------------------------------------------


