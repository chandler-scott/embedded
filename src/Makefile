# Project Name: 
# Author: Chandler Scott
# Description: 

.PHONY: all libs arduino clean

all: setup arduino 

setup:
	mkdir -p $(EMBEDDED_BUILD_DIR)

arduino:
	$(MAKE) -C arduino

clean:
	rm -rf $(EMBEDDED_BUILD_DIR)
