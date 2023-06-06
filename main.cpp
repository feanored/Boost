#ifdef __linux__
#include <curses.h>
#include <stdlib.h>
#elif _WIN32
#include <windows.h>
#include <conio.h>
#endif

// Incluir todas as classes
#include "ProjetoVS/classes.h"

int main(int argc, char* argv[]) {
#ifdef _WIN32
	SetConsoleCP(1252);          // input   
	SetConsoleOutputCP(1252);    // output 
#endif

	// Instanciá-las
	Assert assert;
	Chkfile chkfile;
	Array01 array01;

	// Escolher qual rodar
	if (assert
		.main(argc, argv) == EXIT_FAILURE) {
		auto _nil = _getch();
		return EXIT_FAILURE;
	}
	auto _nil = _getch();
	return EXIT_SUCCESS;
}
