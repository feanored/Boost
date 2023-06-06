#ifdef __linux__
#include <curses.h>
#include <stdlib.h>
#elif _WIN32
#include <windows.h>
#include <conio.h>
#endif

// Incluir todas as classes
#include "ProjetoVS/assert.h"
#include "ProjetoVS/chkfile.h"
#include "ProjetoVS/array01.h"

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
	if (array01
		.main(argc, argv) == EXIT_FAILURE) {
		auto _nil = getch();
		return EXIT_FAILURE;
	}
	auto _nil = getch();
	return EXIT_SUCCESS;
}
