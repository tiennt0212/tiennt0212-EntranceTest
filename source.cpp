#include <iostream>
#include <string>
#include <sstream> //Use this library to convert char -> int
using namespace std;
int check_existance(string str, string checkstr)
{
	//cout << "Check existance of " << checkstr << " in " <<  str << '\n';
	int found = str.find(checkstr);
	return (found == string::npos) ? -1 : found;
}

string get_to_end_from(string str, int pos)
{
	return str.substr(pos);
}

int main(int argc, char* argv[])
{
	int thread = 1,
		conn = 1,
		stop = 0; //Program stop or continue base-on this variable
	string url,
		path;

	cout << "Checking...\n";
	if (argc > 5 || argc < 3) //Check number of parameter
	{
		cout << "Syntax error!\n";
		stop = 1;
	}
	else
	{
		//Get string and split parameter
		int next_index = 1, //Store the parameter's index
			found;

		//Check existance of "--url=" in argv[1]
		found = check_existance(argv[next_index], "--url=");
		if (found == 0) // if argv[1] has "--url="
		{
			//Get URL from 6th character to end
			url = get_to_end_from(argv[next_index], 6);
			cout << "Have URL!\n";
		}
		else // no have "--url=" || the first position of "--url=" not equal 0
		{
			//Notice error!
			cout << "URL syntax error!\n";
			stop = 1;
		}
		//Increase next_index for next checking
		++next_index;

		//Check existance of "--thread=" in the next string
		found = check_existance(argv[next_index], "--thread="); 
		if (found != -1) // if it has "--thread="
		{
			if (found == 0) //good syntax
			{
				//Get value number of thread from 9th character to end
				string temp = get_to_end_from(argv[next_index], 9);
				stringstream convert(temp);
				convert >> thread;
				if (thread > 0)
				{
					cout << "Have parameter of thread!\n";
				}
				else
				{
					cout << "Number of thread must be positive, thread will give default value!\n";
					thread = 1;
				}
			}
			else //syntax error
			{
				cout << "Syntax thread error!\n";
				stop = 1;
			}
			++next_index;
		}
		else//it has not "--thread"
		{
			cout << "Default number of thread = 1\n";
		}


		found = check_existance(argv[next_index], "--conn="); //Find "--conn="
		if (found != -1) // if it has "--conn="
		{
			if (found == 0) //good syntax
			{
				//Get value number of connection from 7th character to end
				string temp = get_to_end_from(argv[next_index], 7);
				stringstream convert(temp);
				convert >> conn;
				if (conn > 0)
				{
					cout << "Have parameter of connection!\n";
				}
				else
				{
					cout << "Number of connection must be positive, connection will give default value!\n";
					thread = 1;
				}
			}
			else//syntax error
			{
				cout << "Syntax connection error!\n";
				stop = 1;
			}
			++next_index;
		}
		else//it has not "--conn"
		{
			cout << "Default number of connection = 1\n";
		}


		//Check existance of "--out=" in argv[next_index]
		found = check_existance(argv[next_index], "--out=");
		if (found == 0)
		{
			//Get string of path from 6th character to end.
			path = get_to_end_from(argv[next_index], 6);
			cout << "Have path!\n";
			//Complete the checking stage
		}
		else //no have path || the first position of "--out=" not equal 0
		{
			//Notice error!
			cout << "Path syntax error!\n";
			//This program must be stopped because of no OUT parameter
			stop = 1;
		}


		//Check value of stop
		if (stop) //If stop=1, stop immediately
		{
			return 0;
		}
		else //Else, can do the next step
		{
			cout << "\nChecking done!\n";
			cout << "URL is " << url << '\n';
			cout << "Number of thread is " << thread << '\n';
			cout << "Number of connection is " << conn << '\n';
			cout << "Path is " << path << '\n';
			cout << "\nPrepare to download......\n";
			cout << "SORRY! Download feature is not complete yet\nSEE YOU LATER!\n";
		}
	}
}
