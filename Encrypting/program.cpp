#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <random>
#include <cmath>

using std::endl;
using std::cout;
using std::string;
using std::vector;
using std::istringstream;
using std::getline;
using std::cin;

class Encrtyptions {
private:
	int random() {
		std::random_device rd;
		std::mt19937_64 gen(rd());
		std::uniform_int_distribution<> distrib(1, 100);
		return distrib(gen);
	}
	void get_text(string& str) {
		cout << "Write needable text" << endl;
		getline(cin, str);
		system("cls");
		cout << "Working..." << endl;
	}
	vector<int> string_to_vector(string& str) {
		string temp;
		istringstream iss(str);
		vector<int> enc;
		while (iss >> temp) {
			enc.push_back(stoi(temp));
		}
		return enc;
	}
	int change(char c, int key) {
		int back = c - '0';
		back += 10123;
		back *= key;
		return back;
	}
	char change(int i, int key) {
		i /= key;
		i -= 10123;
		char c = i + '0';
		return c;
	}
	int get_key(int standart) {
		return pow(standart, 1.0 / 4);
	}



public:
	void Encrypt() {
		string sentense = "";
		get_text(sentense);
		vector<int> enc;
		int key = random();
		for (char c : sentense) {
			enc.push_back(change(c, key));
		}
		key *= key * key * key;
		enc.push_back(key);
		for (auto it = begin(enc); it != end(enc); it++) {
			cout << *it << " ";
		}
	}
	void Dectypt() {
		string sentense = "";
		get_text(sentense); 
		vector<int> enc;
		enc = string_to_vector(sentense);
		vector<char> dec;
		int key = get_key(enc[size(enc)-1]);
		enc.pop_back();
		for (int i : enc) {
			dec.push_back(change(i, key));
		}
		cout << endl;	
		for (char c : dec) {
			cout << c;
		}
		cout << endl;
	}

};










int main() {
	cout << "----------------------------------------------------------------------------------------------" << endl <<
		    "            |\    |     ____      __    \              /        /\                                 " << endl <<
		    "            | \   |    |         |__|    \            /        /  \                            " << endl <<
		    "            |  \  |    |____     |__      \    /\    /        /____\                                      " << endl <<
		    "            |   \ |    |         |  |      \  /  \  /        /      \                                 " << endl <<
		    "            |    \|    |____     |__|       \/    \/        /        \                                    " << endl <<
		    "----------------------------------------------------------------------------------------------";
	cout << endl << "Select mode: " << endl << "1 - Encrypt mode" << endl << "2 - Decrypt mode" << endl;
	int mode = 0;
	string temp;
	Encrtyptions e;
	getline(cin, temp);
	mode = stoi(temp);
	system("cls");
	switch (mode)
	{
	case 1:
		//delete(&mode);
		e.Encrypt();
		break;
	case 2:
		//delete(&mode);
		e.Dectypt();
		break;
	default:
		return 0;
		break;
	}
	
	return 0;
}

