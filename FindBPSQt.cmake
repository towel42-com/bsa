SET(BPS_QT_FOUND FALSE)
find_package(Qt4 REQUIRED)
IF( IS_DIRECTORY ${QT_DOC_DIR} )
        STRING(REGEX REPLACE "/doc" "" QTDIR_TMP ${QT_DOC_DIR})
        SET(QTDIR ${QTDIR_TMP} CACHE STRING "The QT Directory")
        message(STATUS "Looking in ${QTDIR} for QT shared library files.")
        SET(BPS_QT_FOUND TRUE)

        MACRO(BPS_Install_Qt_lib  isSet libName )
            IF(${ARGN}) #negative logic
                IF( ${isSet} )
                    SET( INSTALL_IT FALSE )
                ELSE()
                    SET( INSTALL_IT TRUE )
                ENDIF()
            ELSE()
                SET( INSTALL_IT ${isSet} )
            ENDIF()
            IF( ${INSTALL_IT} )
                IF(WIN32)
                        message( STATUS "Installing Qt library ${libName}" )
                        install(PROGRAMS ${QTDIR}/bin/${libName}d${QT_VERSION_MAJOR}.dll DESTINATION . CONFIGURATIONS Debug )
                        install(PROGRAMS ${QTDIR}/lib/${libName}d${QT_VERSION_MAJOR}.pdb DESTINATION . CONFIGURATIONS Debug )

                        install(PROGRAMS ${QTDIR}/bin/${libName}${QT_VERSION_MAJOR}.dll DESTINATION . CONFIGURATIONS RelWithDebInfo )
                ELSE()
                        install(PROGRAMS ${QTDIR}/lib/lib${libName}.so.${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH} DESTINATION lib )
                        install(PROGRAMS ${QTDIR}/lib/lib${libName}.so.${QT_VERSION_MAJOR}.${QT_VERSION_MINOR} DESTINATION lib )
                        install(PROGRAMS ${QTDIR}/lib/lib${libName}.so.${QT_VERSION_MAJOR} DESTINATION lib )
                ENDIF()
            ELSE()
                #message( STATUS "Skipping Installation of Qt library ${libName}" )
            ENDIF()
        ENDMACRO()

        MACRO(BPS_Install_Qt)
                        BPS_Install_Qt_lib( QT_DONT_USE_QTCORE QtCore TRUE )
                        BPS_Install_Qt_lib( QT_DONT_USE_QTGUI QtGui TRUE )
                        BPS_Install_Qt_lib( QT_USE_XML_PATTERNS QtXmlPatterns )
                        BPS_Install_Qt_lib( QT_USE_XML QtXml )
                        #BPS_Install_Qt_lib( QT_USE_QT3SUPPORT Qt3Support )
                        #BPS_Install_Qt_lib( QT_USE_QTDESIGNER QtDesigner )
                        #BPS_Install_Qt_lib( QT_USE_QTDESIGNER QtDesignerComponents )
                        #BPS_Install_Qt_lib( QT_USE_QTMOTIF NotSupported )
                        BPS_Install_Qt_lib( QT_USE_QTMULTIMEDIA Multimedia )
                        BPS_Install_Qt_lib( QT_USE_QTNETWORK Network )
                        # BPS_Install_Qt_lib( QT_USE_QTNSPLUGIN NotSupported )
                        BPS_Install_Qt_lib( QT_USE_QTOPENGL OpenGL )
                        BPS_Install_Qt_lib( QT_USE_QTSQL Sql )
                        BPS_Install_Qt_lib( QT_USE_QTSVG Svg )
                        BPS_Install_Qt_lib( QT_USE_QTTEST Test )
                        #BPS_Install_Qt_lib( QT_USE_QTUITOOLS NotSupported )
                        #BPS_Install_Qt_lib( QT_USE_QTDBUS NotSupported )
                        BPS_Install_Qt_lib( QT_USE_QTSCRIPT Script )
                        #BPS_Install_Qt_lib( QT_USE_QTASSISTANTCLIENT NotSupported )
                        BPS_Install_Qt_lib( QT_USE_QTHELP Help )
                        BPS_Install_Qt_lib( QT_USE_QTWEBKIT WebKit )
                        BPS_Install_Qt_lib( QT_USE_PHONON phonon )
                        BPS_Install_Qt_lib( QT_USE_QTSCRIPTTOOLS ScriptTools )
                        BPS_Install_Qt_lib( QT_USE_QTDECLARATIVE Declarative )
        ENDMACRO()
ELSE()
    message( FATAL_ERROR "Could not find directory QT_DOC_DIR=${QT_DOC_DIR}" )
ENDIF()
