#pragma once
#ifndef CLASSES_H
#define CLASSES_H


class Runner {
public:
	Runner() = default;
	bool operator==(const Runner& other) const {
		return false;
	}
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
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class AssignInsert : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class AssignListOf : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class AssignMapListOf : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class AssignTupleListOf : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class AssignDequePush : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class StringUtilities : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};

class DequeElement : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};


#endif