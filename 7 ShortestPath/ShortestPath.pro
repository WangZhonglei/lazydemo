TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    BellmanFord.h \
    DenseGraph.h \
    Dijkstra.h \
    Edge.h \
    IndexMinHeap.h \
    ReadGraph.h \
    SparseGraph.h
