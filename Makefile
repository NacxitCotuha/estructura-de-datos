# ==============================================================================
# Makefile para proyectos en C (Escalable y Genérico)
# ==============================================================================

# Nombre del ejecutable final
TARGET_NAME ?= app

# Directorios del proyecto
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build
BIN_DIR   := bin

# Compilador y Flags
CC       := gcc
CFLAGS   := -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow -I$(INC_DIR)
LDFLAGS  := 
LDLIBS   := 

# Configuración según el modo de compilación (make MODE=release / make MODE=debug)
MODE ?= debug
ifeq ($(MODE), release)
    CFLAGS += -O3 -DNDEBUG
else
    CFLAGS += -g -O0 -DDEBUG
endif

# Detectar automáticamente todos los archivos .c (incluyendo subdirectorios)
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')

# Mapear archivos .c a sus correspondientes .o en la carpeta build
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Generar archivos de dependencia (.d) automáticamente
DEPS := $(OBJS:.o=.d)

# Nombre completo del binario
TARGET := $(BIN_DIR)/$(TARGET_NAME)

# ------------------------------------------------------------------------------
# Reglas Principales
# ------------------------------------------------------------------------------

.PHONY: all clean rebuild run help

# Regla por defecto: compilar todo
all: $(TARGET)

# Vinculación del ejecutable
$(TARGET): $(OBJS) | $(BIN_DIR)
	@echo "==> Vinculando ejecutable: $@"
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "✓ Compilacion exitosa en modo [$(MODE)]"

# Compilación de objetos + generación de dependencias (.d)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "==> Compilando: $<"
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Crear directorio de binarios si no existe
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Incluir archivos de dependencia generados por el compilador
-include $(DEPS)

# ------------------------------------------------------------------------------
# Comandos de Utilidad
# ------------------------------------------------------------------------------

# Ejecutar el proyecto
run: $(TARGET)
	@echo "==> Ejecutando $(TARGET)..."
	@./$(TARGET)

# Limpiar archivos generados
clean:
	@echo "==> Limpiando archivos de compilacion..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@echo "✓ Limpieza completada."

# Recompilar desde cero
rebuild: clean all

# Ayuda rápida
help:
	@echo "Uso del Makefile:"
	@echo "  make              Compila la aplicacion en modo Debug"
	@echo "  make MODE=release Compila con optimizaciones (Release)"
	@echo "  make run          Compila y ejecuta el binario"
	@echo "  make clean        Elimina binarios y archivos objeto"
	@echo "  make rebuild      Limpia y vuelve a compilar"