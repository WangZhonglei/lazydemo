TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    DenseGraph.h \
    Edge.h \
    IndexMinHeap.h \
    KruskalMST.h \
    LazyPrimMST.h \
    MinHeap.h \
    PrimMST.h \
    ReadGraph.h \
    SparseGraph.h \
    UF.h
