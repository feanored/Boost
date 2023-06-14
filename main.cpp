#ifdef __linux__
#include <curses.h>
#elif _WIN32
#include <windows.h>
#include <conio.h>
#endif

// Incluir todas as classes
#include "ProjetoVS/classes.h"

int _sair(unsigned short status) {
	auto _nil = _getch();
	return status;
}

int main(int argc, char* argv[]) {

#ifdef _WIN32
	// Input and Output encoding
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
#endif

	// Escolher qual programa rodar
	AssignDequePush runner;

	if (runner.main(argc, argv) == EXIT_SUCCESS)
		return _sair(EXIT_SUCCESS);
	else
		return _sair(EXIT_FAILURE);
}
