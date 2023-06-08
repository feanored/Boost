#ifdef __linux__
#include <curses.h>
#elif _WIN32
#include <windows.h>
#include <conio.h>
#endif

// Incluir todas as classes
#include "ProjetoVS/classes.h"

int main(int argc, char* argv[]) {
	// Input and Output encoding
	#ifdef _WIN32
		SetConsoleCP(1252);
		SetConsoleOutputCP(1252);
	#endif

	// Escolher qual classe rodar
	Array01 classe;

	if (classe.main(argc, argv) == EXIT_FAILURE) {
		auto _nil = _getch();
		return EXIT_FAILURE;
	}
	auto _nil = _getch();
	return EXIT_SUCCESS;
}
