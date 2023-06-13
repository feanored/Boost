#include <iostream>
#include <boost/filesystem.hpp>
#include "ProjetoVS/classes.h"

using namespace std;
namespace boostfs = boost::filesystem;

int 
Chkfile::
main(int argc, char* argv[]) {
	if (argc <= 1) {
		std::cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << std::endl;
		return EXIT_FAILURE;
	}

	boostfs::path p(argv[1]);

	if (boostfs::exists(p)) {
		std::cout << "O arquivo " << p << " existe." << std::endl;
		return EXIT_SUCCESS;
	}
	else {
		std::cout << "O arquivo " << p << " não existe." << std::endl;
		return EXIT_FAILURE;
	}
}
