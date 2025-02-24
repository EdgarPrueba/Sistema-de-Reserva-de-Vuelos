# Definición del compilador y las banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Directorios
SRC_DIR = src
BUILD_DIR = build

# Ejecutables
PART1_EXECS = part_persistence part_graph

# Crear la carpeta build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Target principal: compila todos los ejecutables
all: $(PART1_EXECS)

# Compilar los ejecutables de la Parte 1
part_persistence: $(SRC_DIR)/persistence/test_persistence.cpp $(SRC_DIR)/persistence/FileManager.cpp $(SRC_DIR)/graph/Graph.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $^

# Compilar el test de Graph
part_graph: $(SRC_DIR)/graph/test_graph.cpp $(SRC_DIR)/graph/Graph.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/$@ $^

# Limpieza de archivos generados
clean:
	rm -rf $(BUILD_DIR)

# Ejecutar los programas
run_part_persistence:
	./$(BUILD_DIR)/part_persistence

run_part_graph:
	./$(BUILD_DIR)/part_graph

# Ejecutar todos los programas
run_all: run_part_persistence run_part_graph
