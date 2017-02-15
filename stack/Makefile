PICOTCP_INCLUDE=../../picotcp/build/include
WOLFSSL_INCLUDE=../../wolfssl

PIP?=0

CC=gcc
CXX_FILES := $(wildcard *.c)
OBJS:= $(patsubst %.c,%.o,$(CXX_FILES))
CFLAGS+=-m32 -Wall $(EXTRA_CFLAGS) $(PLATFORM_CFLAGS) -I../include -I$(PICOTCP_INCLUDE) -I$(WOLFSSL_INCLUDE) -DUSE_TLS_PSK


ifeq ($(PIP),1)
	CFLAGS+=-DPIP -fno-zero-initialized-in-bss
endif

all: ../lib/libpicowebstack.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

../lib/libpicowebstack.a: $(OBJS)
	mkdir -p /lib
	@$(CROSS_COMPILE)ar cru $@ $(OBJS)
	@$(CROSS_COMPILE)ranlib $@

clean:
	rm -rf $(OBJS) lib
