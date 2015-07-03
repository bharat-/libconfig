#include <iostream>
#include "json_lib.h"
using namespace std;

int main()
{
int r = 0;

r = Get("version", "/home/bharat/libconfig/src/src/testcfg.json");

cout << r << endl;

return 0;
}
