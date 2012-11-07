cmake_minimum_required (VERSION 2.8)
project (qc)

include (ExternalProject)

ExternalProject_Add(
	nacl_external
	URL http://hyperelliptic.org/nacl/nacl-20110221.tar.bz2
	CONFIGURE_COMMAND ""
	INSTALL_COMMAND ""
	BUILD_COMMAND ./do
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/nacl
	BUILD_IN_SOURCE 1
)

add_library(nacl STATIC IMPORTED)
set_property(TARGET nacl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/nacl/build/mirkwood/lib/amd64/libnacl.a)
add_dependencies(nacl nacl_external)
include_directories(${CMAKE_SOURCE_DIR}/nacl/build/mirkwood/include/amd64)
SET(nacl_LIBRARIES nacl)

add_executable(qc qc.c )
target_link_libraries(qc ${nacl_LIBRARIES} ${CMAKE_SOURCE_DIR}/nacl/build/mirkwood/lib/amd64/randombytes.o)