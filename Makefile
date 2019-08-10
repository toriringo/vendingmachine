CC		= g++
CCFLAGS	= -std=c++17
CFLAGS	+= -D_DEBUG
CFLAGS  += -g

TARGET	= vendingmachine
OBJS	= main.o vendingmachine.o

.SUFFIXES: .cpp .o

all :		$(TARGET)

# リンク、ロケート
$(TARGET) :	$(OBJS)
			$(CC) $(OBJS) -o $(TARGET)

# コンパイル
.cpp.o :	$<
			$(CC) -c $(CCFLAGS) $(CFLAGS) $<

clean :
			rm -f *.o

