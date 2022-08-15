find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})

QT4_WRAP_UI(qtproject_UIS_H ${qtproject_UIS})
QT4_WRAP_CPP(qtproject_MOC_SRCS ${qtproject_H})

include_directories(${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_BINARY_DIR})

source_group("Generated Files" FILES ${qtproject_UIS_H} ${qtproject_MOC_SRCS} ${qtproject_QRC_SRCS} )
source_group("Resource Files" FILES ${qtproject_QRC} ${qtproject_QRC_SOURCES} )
source_group("Designer Files" FILES ${qtproject_UIS} )
source_group("Header Files" FILES ${qtproject_H} )


