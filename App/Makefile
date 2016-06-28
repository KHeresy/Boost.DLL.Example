INC_PATH 	= -I/usr/include
LIB_PATH	= -L/usr/lib
TARGET_PATH	= ../Bin

# for gcc
C++ = g++

# system command
CP = cp -f
RM = rm -f

CFLAGS	= --std=c++11

APP			= App.out

APP_OBJ		= AppMain.o

.SUFFIXES:
.SUFFIXES:	.cpp .o

all: $(APP)

$(APP): $(APP_OBJ)
	$(C++) -pg -o $@ $^ $(LIB_PATH) -lboost_system -lboost_filesystem -ldl
	$(CP) $@ $(TARGET_PATH)

.cpp.o:
	$(C++) $(CFLAGS) $(INC_PATH) -c $<

clean:
	$(RM) *.o $(APP)
