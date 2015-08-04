PROJECT = senselock-exf-skeleton

# Executables
CC = sdcc
LD = sdld
HEXBIN = makebin

# Pathes
SDCC = /usr/share/sdcc
SRC = ./src
OBJ = ./obj
OUTPUT = ../dist

# Flags
CFLAGS = --model-large --no-xinit-opt --opt-code-speed -c -I$(SDCC)/include -I../include -DSDCC_mcs51
LFLAGS = -u -m -x -i -k $(SDCC)/lib/large -k ../lib/senselock/sdcc/large -l libsdcc -l libint -l liblong -l libfloat -l mcs51 -l sdcc_ses51

all: $(OUTPUT)/$(PROJECT).bin

$(OUTPUT)/$(PROJECT).bin: $(OBJ)/$(PROJECT).ihx
	$(HEXBIN) -p $(OBJ)/$(PROJECT).ihx $(OUTPUT)/$(PROJECT).bin

$(OBJ)/$(PROJECT).ihx: $(OBJ)/$(PROJECT).rel
	$(LD) $(LFLAGS) -z $(OBJ)/$(PROJECT).rel

$(OBJ)/$(PROJECT).rel:
	$(CC) $(CFLAGS) -o $(OBJ)/$(PROJECT).rel $(SRC)/$(PROJECT).c

clean:
	rm -rf "$(OBJ)/$(PROJECT).*"
	rm -rf "$(OUTPUT)/$(PROJECT).bin"
