# CMakeList.txt: projeto de CMake para Estruturas, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
add_executable (Lancamentos "lancamentos.cpp")
add_executable (Cargas "cargas.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lancamentos PROPERTY CXX_STANDARD 20)
  set_property(TARGET Cargas PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
