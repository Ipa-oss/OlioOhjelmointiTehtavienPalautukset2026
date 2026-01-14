cmake_minimum_required(VERSION 3.16)

project(OlioOhjelmointiLuento2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OlioOhjelmointiLuento2 main.cpp
    random.h random.cpp
    dht.h dht.cpp
    lcd.h lcd.cpp
    mittari.h mittari.cpp)

include(GNUInstallDirs)
install(TARGETS OlioOhjelmointiLuento2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
