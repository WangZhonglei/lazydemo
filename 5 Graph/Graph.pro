TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    Component.h \
    DenseGraph.h \
    Path.h \
    RandomGraph.h \
    ReadGraph.h \
    ShortestPath.h \
    SparseGraph.h
