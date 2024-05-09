# Project Name: 
# Author: Chandler Scott
# Description: 

include $(EMBEDDED_ROOT_DIR)/src/arduino/common.mk

.PHONY: all clean

all: $(TARGET_HEX)

$(TARGET_ELF): $(OBJ) $(ARDUINO_OBJS) $(LIB_OBJS)
	@echo $(PROJECT_NAME)
	$(CC) $(CFLAGS) -o $@ $^
	avr-objcopy -O ihex $@ $(TARGET_HEX)

$(TARGET_HEX): $(TARGET_ELF)
	avr-objcopy -O ihex $(TARGET_ELF) $@
	rm $(TARGET_ELF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET_ELF) $(TARGET_HEX) $(DEPS)
