SET (QT_VER 4.8.5)

if (MSVC)
SET(QT_ROOT D:/libs/Qt/${QT_VER})
SET(QT_INCLUDE_DIR ${QT_ROOT}/include)
SET(QT_QMAKE_EXECUTABLE ${QT_ROOT}/bin/qmake.exe)
else (MSVC)
SET(QT_ROOT /usr/lib64/Qt/${QT_VER})
endif()

SET(QT_USE_QTNETWORK ON)

FIND_PACKAGE(Qt4 REQUIRED)
