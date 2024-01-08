cmake_minimum_required(VERSION 3.14)

project(store_application LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

add_executable(store_application
  main.cpp
  abstractshopfactory.cpp
  abstractshopfactory.h
  book.cpp
  book.h
  filewriter.cpp
  filewriter.h
  magazine.cpp
  magazine.h
  shop.cpp shop.h
  shopfactory.cpp
  shopfactory.h
  shoplist.cpp
  shoplist.h
  shopwindow.cpp
  shopwindow.h
  resources.qrc
  shopmemento.h shopmemento.cpp
  shopgenerator.h shopgenerator.cpp
  shopcaretaker.h shopcaretaker.cpp

)
target_link_libraries(store_application PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS store_application
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
