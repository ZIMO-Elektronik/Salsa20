TARGET = Salsa20

TEMPLATE = lib

SOURCES += $$PWD/src/salsa20.c

HEADERS += $$PWD/include/salsa20/ecrypt-config.h \
        $$PWD/include/salsa20/ecrypt-machine.h \
        $$PWD/include/salsa20/ecrypt-portable.h \
        $$PWD/include/salsa20/ecrypt-sync.h
