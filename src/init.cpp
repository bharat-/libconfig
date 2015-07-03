#include <cstdio>
#include <cstring>
#include <fstream>
//#include "/usr/include/jsoncpp/json.h"
#include "json_lib.h"
using namespace std;

int Init(char *iconfig, char *oconfig)
{
	int rc = -1;
	Json::Value root, node, new_root;
	Json::Reader reader;
	std::ifstream json_ifile(iconfig, std::ifstream::binary);
	std::ofstream json_ofile(oconfig, std::ofstream::binary);
	bool parsedSuccess;
	Json::Value::Members list;

	if (!iconfig || !oconfig) {
		cout << "Usage: init <input config file> <output config file>" << endl;
		rc = -1;
		goto err_out;
	}

	parsedSuccess = reader.parse(json_ifile, root, false);

	if (not parsedSuccess) {
		cout << "Failed to parse JSON" << endl
			 << reader.getFormatedErrorMessages() << endl;
		rc = -1;
		goto err_out;
	}

/*
	std::string version = root.get("version", "NULL_VERSION" ).asString();
	if (version.empty())
		cout << "version not found" << version << endl;
	else
		cout << "version is: " << version << endl;

	Json::Value log = root.get("log", "NULL_LOG");
	if (log.isNull()) {
		cout << "log not found\n";
		return 1;
	}
*/


	list = root.getMemberNames();
	for (int i = 0; i < list.size(); i++) {

		string curValue, defValue;
		curValue.insert(0, "C");
		defValue.insert(0, "D");
		curValue.append(list[i]);
		defValue.append(list[i]);

		new_root[list[i]][curValue] = root[list[i]];
		new_root[list[i]][defValue] = root[list[i]];

	}

	rc = 0;

noerr_out:
	// If we want to print JSON is as easy as doing:
	cout << "Json Example pretty print: " << endl
		 << new_root.toStyledString() << endl;

	json_ofile << new_root.toStyledString() << endl;

err_out:
	return rc;

}

