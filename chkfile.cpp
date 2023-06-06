#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
// namespace boostfs = boost::filesystem;

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		std::cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << std::endl;
		return 1;
	}

	boost::filesystem::path p(argv[1]);

	if (boost::filesystem::exists(p))
		std::cout << "O arquivo " << p << " existe." << std::endl;
	else
		std::cout << "O arquivo " << p << " nao existe." << '\n';

	return 0;
}
