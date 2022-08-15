project(t162calc) 
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/Modules ${CMAKE_MODULE_PATH})
find_package(Qt4 REQUIRED)
FIND_PACKAGE(BPSQt REQUIRED)

include( include.cmake )

include( Project.cmake )
include( UI.cmake )

QT4_ADD_RESOURCES( qtproject_QRC_SRCS ${qtproject_QRC} )

add_executable(t162calc WIN32 ${project_SRCS} ${project_H}  
	${qtproject_SRCS} 
	${qtproject_QRC_SRCS} 
	${qtproject_UIS_H} 
	${qtproject_MOC_SRCS} 
	${qtproject_H} 
)
target_link_libraries( t162calc 
	${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES} 
)

SET(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/Install)
SET(QT_DONT_USE_QTGUI FALSE)
SET(QT_USE_QTSQL FALSE )
SET(QT_USE_QTWEBKIT FALSE )
BPS_Install_Qt()
INSTALL(TARGETS t162calc RUNTIME DESTINATION . )

IF(WIN32)
    INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/Debug/t162calc.pdb DESTINATION . CONFIGURATIONS Debug )
ENDIF()

