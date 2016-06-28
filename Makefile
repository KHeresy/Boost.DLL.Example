MAKE = "make"
MAKE_CLEAN = $(MAKE) "clean"

APP_DIR		= App
DLLA_DIR	= DLLa

TARGET	= 	\
	App.out \
	libDLLa.so

all: $(TARGET)

App.out:
	@(cd $(APP_DIR);	$(MAKE));

libDLLa.so:
	@(cd $(DLLA_DIR);	$(MAKE));

clean:
	@(cd $(APP_DIR);	$(MAKE_CLEAN));
	@(cd $(DLLA_DIR);	$(MAKE_CLEAN));
	@(cd Bin; rm *);

