set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick Widgets PrintSupport REQUIRED)

qt5_add_resources(UI_RESOURCES ${CMAKE_SOURCE_DIR}/resources/qml.qrc)

add_executable(${PROJECT_NAME}  ${CMAKE_SOURCE_DIR}/source/App/main.cpp
                                ${CMAKE_SOURCE_DIR}/include/App/App.h
                                ${CMAKE_SOURCE_DIR}/source/App/App.cpp
                                ${CMAKE_SOURCE_DIR}/external/qcustomplot/qcustomplot.h
                                ${CMAKE_SOURCE_DIR}/external/qcustomplot/qcustomplot.cpp
                                ${CMAKE_SOURCE_DIR}/include/View/PlotItem.h
                                ${CMAKE_SOURCE_DIR}/source/View/PlotItem.cpp
                                ${CMAKE_SOURCE_DIR}/include/View/Plottables/PlottableItem.h
                                ${CMAKE_SOURCE_DIR}/source/View/Plottables/PlottableItem.cpp
                                ${CMAKE_SOURCE_DIR}/include/View/Plottables/PlottableChart.h
                                ${CMAKE_SOURCE_DIR}/source/View/Plottables/PlottableChart.cpp
                                ${UI_RESOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Widgets Qt5::PrintSupport)
