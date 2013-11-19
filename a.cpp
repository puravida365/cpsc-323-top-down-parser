#include <iostream>
#include <stack>
#include <string>

using namespace std;

class LL{
	private:
		// declare and initialize values
		string table[5][8] = {  {"TQ", " ",  " ",  " ",  " ", "TQ",  " ",  " "},
								{" ", "+TQ", "-TQ",  " ",  " ", " ",  " ",  " "},
								{"FR",  " ",  " ",  " ",  " ", "FR", " ",  " "},
								{" ",  " ",  " ", "*FR", "/FR", " ", " ",  " "},
								{"i",  " ",  " ", " ", " ", "(E)", " ",  " " } 
							};
		
		stack <string> T;
		string expression;
		string input;
		string temp;
		string token;
		int counter;
		int n;
	public:
		LL(){
			counter = 0;
			// initial push
			T.push("$");
			T.push("E");
		}
		void getString(){
			cout << "Enter expression: ";
			getline(cin, expression);
		}
		void parse(){
		
			pop();
			
			while(!T.empty()){
			
				input = expression[counter];

				if(temp != input){
					token = temp.insert(1,input);
					g();
				}
				else if(temp == input){
					counter++;
					input = expression[counter];
					pop();
					token = temp.insert(1,input); // new token 
					g();
				}
				else if(temp == "$"){
					cout << "Accept" << endl;
				}
				else{
					cout << "Not accepted" << endl;
				}
			}
		}
		void g(){
			if (token == "Ei"){
				T.push("Q");
				T.push("T");
			}
			else if (token == "E("){
				T.push("Q");
				T.push("T");
			}
			else if (token == "Q+"){
				T.push("Q");
				T.push("T");
				T.push("+");
			}
			else if (token == "Q-"){
				T.push("Q");
				T.push("T");
				T.push("-");
			}
			else if (token == "Ti"){
				T.push("R");
				T.push("F");
			}
			else if (token == "T("){
				T.push("R");
				T.push("F");
			}
			else if (token == "R*"){
				T.push("R");
				T.push("F");
				T.push("*");
			}
			else if (token == "R/"){
				T.push("R");
				T.push("F");
				T.push("/");
			}
			else if (token == "Fi"){
				T.push("i");
			}
			else if (token == "F("){
				T.push(")");
				T.push("E");
				T.push("(");
			}
			pop();
		}
		void pop(){
			temp = T.top();
			T.pop();
			cout << temp << endl;
		}
};

int main(){
	LL A;
	A.getString();
	A.parse();
	return(0);
}