
add_executable(Unittest_IbHandle    ${CMAKE_SOURCE_DIR}/source/IbHandle/unittest.cpp
                                    ${CMAKE_SOURCE_DIR}/include/IbHandle/Client.h
                                    ${CMAKE_SOURCE_DIR}/source/IbHandle/Client.cpp)

target_link_libraries(Unittest_IbHandle LINK_PUBLIC IbClient)
				
