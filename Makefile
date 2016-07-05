MAKE = "make"
MAKE_CLEAN = $(MAKE) "clean"

APP_DIR		= App
DLLA_DIR	= DLLa
DLLB_DIR	= DLLb

TARGET	= 	\
	App.out \
	libDLLa.so \
	libDLLb.so

all: $(TARGET)

App.out:
	@(cd $(APP_DIR);	$(MAKE));

libDLLa.so:
	@(cd $(DLLA_DIR);	$(MAKE));

libDLLb.so:
	@(cd $(DLLB_DIR);	$(MAKE));

clean:
	@(cd $(APP_DIR);	$(MAKE_CLEAN));
	@(cd $(DLLA_DIR);	$(MAKE_CLEAN));
	@(cd $(DLLB_DIR);	$(MAKE_CLEAN));
	@(cd Bin; rm *);

