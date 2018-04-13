SET(TWSAPIDIR ${CMAKE_SOURCE_DIR}/external/twsapi/client)
SET(TWSAPIALLLINK   ${TWSAPIDIR}/bar.h
                    ${TWSAPIDIR}/CommissionReport.h
                    ${TWSAPIDIR}/CommonDefs.h
                    ${TWSAPIDIR}/Contract.h
                    ${TWSAPIDIR}/ContractCondition.cpp
                    ${TWSAPIDIR}/ContractCondition.h
                    ${TWSAPIDIR}/DefaultEWrapper.cpp
                    ${TWSAPIDIR}/DefaultEWrapper.h
                    ${TWSAPIDIR}/DepthMktDataDescription.h
                    ${TWSAPIDIR}/EClient.cpp
                    ${TWSAPIDIR}/EClient.h
                    ${TWSAPIDIR}/EClientMsgSink.h
                    ${TWSAPIDIR}/EClientSocket.cpp
                    ${TWSAPIDIR}/EClientSocket.h
                    ${TWSAPIDIR}/EDecoder.cpp
                    ${TWSAPIDIR}/EDecoder.h
                    ${TWSAPIDIR}/EMessage.cpp
                    ${TWSAPIDIR}/EMessage.h
                    ${TWSAPIDIR}/EMutex.cpp
                    ${TWSAPIDIR}/EMutex.h
                    ${TWSAPIDIR}/EPosixClientSocketPlatform.h
                    ${TWSAPIDIR}/EReader.cpp
                    ${TWSAPIDIR}/EReader.h
                    ${TWSAPIDIR}/EReaderOSSignal.cpp
                    ${TWSAPIDIR}/EReaderOSSignal.h
                    ${TWSAPIDIR}/EReaderSignal.h
                    ${TWSAPIDIR}/EReaderWMSignal.cpp
                    ${TWSAPIDIR}/EReaderWMSignal.h
                    ${TWSAPIDIR}/ESocket.cpp
                    ${TWSAPIDIR}/ESocket.h
                    ${TWSAPIDIR}/ETransport.h
                    ${TWSAPIDIR}/EWrapper.h
                    ${TWSAPIDIR}/Execution.h
                    ${TWSAPIDIR}/executioncondition.cpp
                    ${TWSAPIDIR}/executioncondition.h
                    ${TWSAPIDIR}/FamilyCode.h
                    ${TWSAPIDIR}/HistogramEntry.h
                    ${TWSAPIDIR}/HistoricalTick.h
                    ${TWSAPIDIR}/HistoricalTickBidAsk.h
                    ${TWSAPIDIR}/HistoricalTickLast.h
                    ${TWSAPIDIR}/IExternalizable.h
                    ${TWSAPIDIR}/MarginCondition.cpp
                    ${TWSAPIDIR}/MarginCondition.h
                    ${TWSAPIDIR}/NewsProvider.h
                    ${TWSAPIDIR}/OperatorCondition.cpp
                    ${TWSAPIDIR}/OperatorCondition.h
                    ${TWSAPIDIR}/Order.h
                    ${TWSAPIDIR}/OrderCondition.cpp
                    ${TWSAPIDIR}/OrderCondition.h
                    ${TWSAPIDIR}/OrderState.h
                    ${TWSAPIDIR}/PercentChangeCondition.cpp
                    ${TWSAPIDIR}/PercentChangeCondition.h
                    ${TWSAPIDIR}/PriceCondition.cpp
                    ${TWSAPIDIR}/PriceCondition.h
                    ${TWSAPIDIR}/PriceIncrement.h
                    ${TWSAPIDIR}/Resource.h
                    ${TWSAPIDIR}/ScannerSubscription.h
                    ${TWSAPIDIR}/shared_ptr.h
                    ${TWSAPIDIR}/SoftDollarTier.cpp
                    ${TWSAPIDIR}/SoftDollarTier.h
                    ${TWSAPIDIR}/StdAfx.cpp
                    ${TWSAPIDIR}/StdAfx.h
                    ${TWSAPIDIR}/TagValue.h
                    ${TWSAPIDIR}/TickAttrib.h
                    ${TWSAPIDIR}/TimeCondition.cpp
                    ${TWSAPIDIR}/TimeCondition.h
                    ${TWSAPIDIR}/TwsSocketClientErrors.h
                    ${TWSAPIDIR}/VolumeCondition.cpp
                    ${TWSAPIDIR}/VolumeCondition.h)

find_package(Threads REQUIRED)


add_executable(Unittest_IbHandle 
				${CMAKE_SOURCE_DIR}/source/IbHandle/unittest.cpp
                                ${TWSAPIALLLINK}
                                ${CMAKE_SOURCE_DIR}/include/IbHandle/Client.h
				${CMAKE_SOURCE_DIR}/source/IbHandle/Client.cpp)

target_link_libraries(Unittest_IbHandle Threads::Threads)
				
