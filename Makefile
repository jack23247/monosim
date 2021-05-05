# Makefile
# https://stackoverflow.com/a/2484343

CC = gcc
LD = gcc

BFLAGS = -O0 -ggdb -march=native -mrdrnd # -O3
CFLAGS = -I. -std=gnu99 -Wall -Wextra -pedantic
WITH =

EXE_NAME = monosim.x86_64

SRC_DIR := .
BUILD_DIR := .build

################################################################################

SRC := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ := $(patsubst ./%.c,.build/%.o,$(SRC))
INCLUDES := $(addprefix -I,$(SRC_DIR))

vpath %.c $(SRC_DIR)

define make-goal
$1/%.o: %.c
	$(CC) $(BFLAGS) $(CFLAGS) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all clean

all: $(BUILD_DIR) $(EXE_NAME)

$(EXE_NAME): $(OBJ)
	$(LD) $^ -o $@ $(WITH)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR) $(EXE_NAME)

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

################################################################################