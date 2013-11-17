/*
	LL Parser

*/

#include <iostream>
#include <stack>
using namespace std;

class LL{
	private:
		string table[5][8] = { 'TQ', " ",  " ",  " ",  " ", "TQ",  " ",  " ",
								" ", "+TQ", "-TQ",  " ",  " ", " ",  "%",  "%",
								"FR",  " ",  " ",  " ",  " ", "FR", " ",  " ",
								" ",  "%",  "%", "*FR", "/FR", " ", "%",  "%",
								"i",  " ",  " ", " ", " ", "(E)", "%",  "%", };
		string input;
		stack <string> T;
		char read;
	public:
		LL(){}
		int getString(){
			cout << "What string would you like to parse?";
			cin >> input;
		}
		parse(){
			T.push("$");
			T.push("E");
		
		}
};

int main(){
	LL A;
	return(0);
}