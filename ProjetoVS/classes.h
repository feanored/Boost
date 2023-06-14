#pragma once
#ifndef CLASSES_H
#define CLASSES_H


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

class AssignListof : public Runner {
public:
	int main(int argc, char* argv[]) {
		return main();
	}
	int main();
};


#endif