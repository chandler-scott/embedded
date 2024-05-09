# Arduino project Makefile
PROJECT_DIRS := $(wildcard $(EMBEDDED_ROOT_DIR)/src/arduino/projects/*/.)

# Extract project names from directories
PROJECT_NAMES := $(notdir $(patsubst %/.,%,$(PROJECT_DIRS)))

all: $(PROJECT_NAMES)

$(PROJECT_NAMES):
	$(MAKE) -C $(EMBEDDED_ROOT_DIR)/src/arduino/projects/$@

clean:
	@$(foreach project_dir,$(PROJECT_DIRS),$(MAKE) -C $(project_dir) clean;)

.PHONY: all clean

