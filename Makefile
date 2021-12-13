CFLAGS=-Wall -Wextra
TARGET= main
SRCS=main.c bst.c
OBJS=$(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $< -c -o $@
	 

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	
.PHONY:clean
clean:
	-$(RM) $(TARGET) $(OBJS)