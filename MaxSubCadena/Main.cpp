#include "MaxSubString.h"

int main(void) {
	MaxSubString max("abcdefg", "aedcabcefg");

	cout << max.findMaxSubString() << endl;

	system("PAUSE");
}