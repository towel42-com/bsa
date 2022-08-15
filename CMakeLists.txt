project(t162) 
cmake_minimum_required(VERSION 2.8)
find_package(Qt4 REQUIRED)

include( include.cmake )

include( Project.cmake )
include( UI.cmake )


add_executable(t162 WIN32 ${project_SRCS} ${project_H}  
	${qtproject_SRCS} 
	${qtproject_QRC_SRCS} 
	${qtproject_UIS_H} 
	${qtproject_MOC_SRCS} 
	${qtproject_H} 
)
target_link_libraries( t162 
	${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES} 
)

