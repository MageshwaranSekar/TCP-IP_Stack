PREFIX?=$(PWD)
PICOTCP_INCLUDE=$(PREFIX)/../picotcp/build/include
WOLFSSL_INCLUDE=$(PREFIX)/../wolfssl

CC=gcc
CXX_FILES := $(wildcard *.c)
OBJS:= $(patsubst %.c,%.o,$(CXX_FILES))
CFLAGS+=-Wall -Iconfig $(EXTRA_CFLAGS) $(PLATFORM_CFLAGS) -I $(PREFIX)/include -I $(PICOTCP_INCLUDE) -I $(WOLFSSL_INCLUDE) -DWOLFSSL_PICOTCP -DWOLFSSL_USER_IO -DNO_WRITEV -DUSE_TLS_PSK

all: $(PREFIX)/lib/libstack.a

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(PREFIX)/lib/libstack.a: $(OBJS)
	mkdir -p $(PREFIX)/lib
	@$(CROSS_COMPILE)ar cru $@ $(OBJS)
	@$(CROSS_COMPILE)ranlib $@

clean:
	rm -rf $(OBJS) $(PREFIX)/lib
