.PHONY: clean all pre install uninstall

PREFIX ?= $(DESTDIR)/usr
LIBDIR ?= $(PREFIX)/lib
DATADIR ?= $(PREFIX)/share
BINDIR ?= $(PREFIX)/bin
INCLUDEDIR ?= $(PREFIX)/include
PKGCONFIGDIR ?= $(LIBDIR)/pkgconfig

CFLAGS_EXTRA = -ggdb -Wall -Wextra
LDFLAGS_EXTRA =

SOVERSION=0:2:0
LIB=libbubba-info.la
LIB_SRC=bubba-info.c
LIB_HSRC=bubba-info.h
LIB_OBJS=$(LIB_SRC:%.c=%.lo)

APP=bubba-info
APP_SRC=main.c
APP_OBJS=$(APP_SRC:%.c=%.o)

DEPDIR = .deps
%.lo  %.o: %.c
	libtool --mode=compile gcc -c $(CFLAGS_EXTRA) -O -MT $@ -MD -MP -MF $(DEPDIR)/$(subst /,_,$*).Tpo -o $@ $<
	mv -f $(DEPDIR)/$(subst /,_,$*).Tpo $(DEPDIR)/$(subst /,_,$*).Po


all: pre $(LIB) $(APP) bubba-info.pc

pre:
	@@if [ ! -d .deps ]; then mkdir .deps; fi

$(LIB): $(LIB_OBJS)
	libtool --mode=link gcc -O $(LDFLAGS) $(LDFLAGS_EXTRA) -o $@ -version-info $(SOVERSION) $^ -no-rpath -rpath /usr/lib

$(APP): $(APP_OBJS)
	libtool --mode=link gcc -O $(LDFLAGS) $(LDFLAGS_EXTRA) $^ -o $@ $(LIB) -shared

install:: bubba-info.pc
	libtool --mode=install install -D -m 644 -c $^ $(PKGCONFIGDIR)/$^

install:: $(LIB_HSRC)
	libtool --mode=install install -D -c $^ $(INCLUDEDIR)/$^

install:: $(LIB)
	libtool --mode=install install -D -c $^ $(LIBDIR)/$^

install:: $(APP)
	libtool --mode=install install -D -c $^ $(BINDIR)/$^

define do_uninstall
$(foreach file, $(1), libtool --mode=uninstall rm -f $(strip $(2))/$(strip $(1)))

endef

uninstall: 
	$(call do_uninstall, bubba-info.pc, $(PKGCONFIGDIR))
	$(call do_uninstall, $(LIB_HSRC), $(INCLUDEDIR))
	$(call do_uninstall, $(LIB), $(LIBDIR))
	$(call do_uninstall, $(APP), $(BINDIR))

clean:                                                                          
	rm -f *~ $(APP) $(LIB_OBJS)
	rm -rf .deps .libs
	rm -f *.lo *.la *.o *.pc

define do_subst
$(1)="$(strip $(call $(1)))" perl -pi -e 's#\@$(strip $(1))\@#$$ENV{$(strip $(1))}#' $(strip $(2))

endef

%.pc: %.pc.in
	cp $^ $@;
	$(foreach key, PREFIX VERSION, $(call do_subst, $(key), $@)	)

-include $(LIB_SRC:%.c=.deps/$(subst /,_,%).Po) 
-include $(APP_SRC:%.c=.deps/$(subst /,_,%).Po) 
