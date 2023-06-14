#include <stdlib.h>

class Runner {
public:
	Runner() = default;
};

class Chkfile : public Runner {
public:
	int main(int argc, char* argv[]);
};

class Assert : public Runner {
public:
	int main(int argc, char* argv[]);
};

class Array : public Runner {
public:
	int main(int argc, char* argv[]);
};

class AssignIncrement : public Runner {
public:
	int main(int argc, char* argv[]);
};

class AssignInsert : public Runner {
public:
	int main(int argc, char* argv[]);
};
