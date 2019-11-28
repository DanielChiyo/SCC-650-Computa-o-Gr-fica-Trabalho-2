QT          += core gui opengl

LIBS        += -lopengl32

TARGET      = opengl
TEMPLATE    = app


SOURCES     += main.cpp \
            cube.cpp \
            cubetransformation.cpp

HEADERS     += cube.h \
    cubetransformation.h
