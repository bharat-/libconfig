#include <cstdio>
#include <cstring>
#include <fstream>
#include "json_lib.h"

//#include "/usr/include/jsoncpp/json.h"
using namespace std;

int Set(char *param, char *val, char *config_path)
{
	int rc = -1;
	Json::Value root, node, node1;
	Json::Reader reader;
	string curValue, defValue;
	bool parsedSuccess;
	std::ifstream json_file(config_path, std::ifstream::binary);

	if (!param || !val || !config_path) {
		cout << "Usage: get <parameter name> <parameter value> <config file path>\n";
		rc = -1;
		goto err_out;
	}

	parsedSuccess = reader.parse(json_file, root, false);

	if (not parsedSuccess) {
		cout << "Failed to parse JSON" << endl
			 << reader.getFormatedErrorMessages() << endl;
		rc = -1;
		goto err_out;
	}

/*
	node = root;
	char *p = strtok(argv[1], "/");

	while (p) {
		//cout << p << "\n";
		//node1 = node[p];

		node1 = node.get(p, "");
		if (node1.isNull() || node1.empty()) {
			cout << "node: " << p << "not found" << endl;
			return -1;
		}

		node = node1;
		p = strtok(NULL, "/");
	}
*/

	node = root[param];

	if (node.isNull()) {
		cout << "node: " << param << "not found" << endl;
		rc = -1;
		goto err_out;
	}

	curValue.insert(0, "C");
	defValue.insert(0, "D");
	curValue.append(param);
	defValue.append(param);

	root[param][curValue] = val;
	rc = 0;

noerr_out:
// If we want to print JSON is as easy as doing:
	cout << "Json Example pretty print: " << endl
		 << root.toStyledString() << endl;

err_out:
	return rc;

	return 0;
}

