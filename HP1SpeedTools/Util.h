#pragma once
#include <string>
#include <sstream>

using namespace std;

#define DLLExport __declspec( dllexport )

string intToHex(int num) {
	stringstream stream;
	stream << std::hex << num;
	return string(stream.str());
}
