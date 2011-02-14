SRC_DIR= loader

CC=	gcc
CFLAGS= -std=c99 -m32 -Wall -Wextra -O0 -g -I$(SRC_DIR)/include -nostdinc -nostdlib 

LD=	ld
LDFLAGS= -z max-page-size=0x1000 -T$(SRC_DIR)/arch/i386/link.ld

BUILD=	build/loader

OBJ=	arch/i386/boot.o \
	lib/string/string.o \
	video/video.o \
	loader.o

BUILD_OBJ= $(OBJ:%.o=$(BUILD)/%.o)

.PHONY: all build clean pre-build post-build

all: build link test

pre-build:
	@echo "------ BUILD STARTED at `date` ------"

post-build:
	@echo "------ BUILD ENDED at `date` ------"

pre-link:
	@echo "------ LINKING STARTED at `date` ------"

post-link:
	@echo "------ LINKING ENDED at `date` ------"

$(BUILD)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "(CC) $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD)/%.o: $(SRC_DIR)/%.S
	@mkdir -p $(@D)
	@echo "(CC) $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

build: pre-build $(BUILD_OBJ) post-build

clean:
	@rm -rf build 

link: build pre-link do-link post-link

do-link:
	@echo "(LD) $(BUILD)/loader.elf"
	@$(LD) $(LDFLAGS) -o $(BUILD)/loader.elf $(BUILD_OBJ)

test: link
	@mbchk -q $(BUILD)/loader.elf

run:
	kvm -kernel $(BUILD)/loader.elf -append kernel=/kernel.elf -curses
