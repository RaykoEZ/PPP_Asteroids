# we are going to build an app
TEMPLATE=app
CONFIG+=c++11
# qt 5 wants this may cause errors with 4
isEqual(QT_MAJOR_VERSION, 5) {cache() }
QT += opengl
QT -= corex`
TARGET=Asteroids_PPP
OBJECTS_DIR=$$PWD/obj

HEADERS += \
    include/SDLOpenGL.h \
    include/GameObjects.h \
    include/Mat4.h \
    include/Vec4.h \
    include/Camera.h \
    include/Ship.h \
    include/Asteroids.h \
    include/Projectile.h \
    include/CalcFunctions.h \
    include/CollisionFunctions.h \
    include/Audio.h \
    include/Music.h \
    include/SoundFX.h \
    include/SoundTriggers.h



SOURCES=$$PWD/src/main.cpp \
    src/SDLOpenGL.cpp \
    src/Mat4.cpp \
    src/Vec4.cpp \
    src/Camera.cpp \
    src/GameObjects.cpp \
    src/Ship.cpp \
    src/Projectile.cpp \
    src/CalcFunctions.cpp \
    src/CollisionFunctions.cpp \
    src/Music.cpp \
    src/SoundFX.cpp \
    src/SoundTriggers.cpp


CONFIG-=app_bundle
# add the ngl lib
# this is where to look for includes
INCLUDEPATH +=include
#INCLUDEPATH +=../GLFunctionsLib/include
#LIBS+=-L$$PWD/../GLFunctionsLib/lib -lGLFunctionsLib
macx:QMAKE_CXXFLAGS+= -arch x86_64

!win32 :{
QMAKE_CXXFLAGS += $$system(sdl2-config --cflags)
LIBS+=$$system(sdl2-config --libs)
}

!win32:LIBS+=-L/usr/local/lib
macx: {
  DEFINES+=MAC_OS_X_VERSION_MIN_REQUIRED=1060
  QMAKE_LFLAGS += -F/Library/Frameworks
# LIBS += -framework SDL2
  INCLUDEPATH += /Library/Frameworks/SDL2.framework/Headers
# INCLUDEPATH += /usr/local/include
# QMAKE_CXXFLAGS += $$system(sdl2-config --cflags)
# LIBS+=$$system(sdl2-config --libs)
  LIBS+=-framework OpenGL
  LIBS+=-framework SDL2
  #LIBS+=-framework SDL2_mixer
  INCLUDEPATH+= /usr/local/include/SDL2
  #INCLUDEPATH+= $$PWD/libs/SDL2_mixer_OSX/SDL2_mixer.framework/Versions/A/Headers

#  QMAKE_LFLAGS += -F$$PWD/libs/SDL2_mixer_OSX

}

linux-g++
{
LIBS+=-lSDL2_mixer
message("linux g++")
}

win32 : {
message("windows msvc")
DEFINES+=_USE_MATH_DEFINES
INCLUDEPATH +=c:/SDL2/include
LIBS +="-LC:\SDL2\lib\x64" -lSDL2
LIBS+=-lopengl32
CONFIG+=console

INCLUDEPATH +=$$PWD/libs/SDL2_mixer-2.0.1_win/include
LIBS +="-L$$PWD\libs\SDL2_mixer-2.0.1_win\lib\x64" -lSDL2_mixer
#LIBS +="-LC:\Users\Public\qt_prjs\PPP_Asteriod\PPP_Assteroids_Proj\libs\SDL2_mixer-2.0.1_win\lib\x64" -lSDL2_mixer
}


