#include <cstdio>
#include <cstring>
#include <fstream>
#include "json_lib.h"
//#include "/usr/include/jsoncpp/json.h"
using namespace std;

int Get(char *param, char *config_path)
{
	int rc = -1;
	Json::Value root, node;
	Json::Reader reader;
	string curValue, defValue;
	bool parsedSuccess;
	std::ifstream json_file(config_path, std::ifstream::binary);

	if (!param || !config_path) {
		cout << "Usage: get <parameter name> <config file path>" << endl;
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

	if (node[curValue].isNull()) {
		if (node[defValue].isNull()) {
			cout << "node: " << param << "not found" << endl;
			rc = -1;
			goto err_out;
		}

		cout << "found: " << node[defValue] << endl;
		rc = 0;
		goto noerr_out;
	}

	cout << "found: " << node[curValue] << endl;
	//cout << "Json Example pretty print: " << endl 
	//		 << root.toStyledString() << endl;

noerr_out:

err_out:
	return rc;

}

