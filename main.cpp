#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"

using namespace std;

int main(int argc, char ** argv)
{
	bool keepGoing = true;

	if(argc < 2)
	{
		cout << "You did not give a file name." << endl;
	}
	else if(argc >= 2)
	{
		string fileName = argv[1];
		GenStack<char> delimiters(50);

		while(keepGoing)
		{
			cout << "File name: " << fileName << endl;

			string text;
			int lineNum = 1;

			ifstream inputStream;
			inputStream.open(fileName.c_str());

			while(inputStream >> text)
			{
				for(int i = 0; i < text.size(); ++i)
				{
					if(text[i] == '(' || text[i] == ')' || text[i] == '{' || text[i] == '}' || text[i] == '[' || text[i] == ']')
					{
						if(delimiters.peek() == '(' && text[i] == ')')
						{
							delimiters.pop();
						}
						else if(delimiters.peek() == '(' && (text[i] == '}' || text[i] == ']'))
						{
							cout << "Line " << lineNum << ": Expected a ')' and found '" << text[i] << "' instead." << endl;
							return 0;
						}
						else if(delimiters.peek() == '{' && text[i] == '}')
						{
							delimiters.pop();
						}
						else if(delimiters.peek() == '{' && (text[i] == ')' || text[i] == ']'))
						{
							cout << "Line " << lineNum << ": Expected a '}' and found '" << text[i] << "' instead." << endl;
							return 0;
						}
						else if(delimiters.peek() == '[' && text[i] == ']')
						{
							delimiters.pop();
						}
						else if(delimiters.peek() == '[' && (text[i] == '}' || text[i] == ')'))
						{
							cout << "Line " << lineNum << ": Expected a ']' and found '" << text[i] << " 'instead." << endl;
							return 0;
						}
						else if(delimiters.isEmpty() == 1 && (text[i] == '}' || text[i] == ')' || text[i] == ']'))
						{
							cout << "Line " << lineNum << ": Invalid delimiter; found unopened " << text[i] << "." << endl;
							return 9;
						}
						else if(text[i] == '(' || text[i] == '[' || text[i] == '{')
						{
							delimiters.push(text[i]);
						}
					}
				}

				++lineNum;
			}

			inputStream.close();

			if(delimiters.isEmpty() == 0)
			{
				cout << "Reached end of file, still missing: " << delimiters.peek() << "." << endl;
				return 0;
			}
			else if(delimiters.isEmpty() == 1)
			{
				char response;

				cout << "The delimiter syntax in this file is correct. Enter 'Y' if you would like to analyze another file: ";
				cin >> response;

				if(response == 'y' || response == 'Y')
				{
					cout << "Enter another file: ";
					cin >> fileName;
					continue;
				}
				else
				{
					keepGoing = false;
				}
			}
		}
	}
	return 0;
}
