#include <iostream> 
#include <string> 
#include <regex> 
#include <fstream>
using namespace std; 
int main() {
	cout<<"Part 1:"<<endl<<endl;
    regex pattern{R"(\d\d)"};
    regex pat2{R"(thanks)"};
    string to_search = "I would like the number 98 "
                       " to be found and printed, thanks.";
    smatch matches;
    smatch matche;
	regex_search(to_search, matches, pattern);
	regex_search(to_search,matche, pat2);
 	for (auto match : matches) {
    	cout << match<<" ";
 	}
 	for(auto matc : matche){
 		cout << matc << endl;
 	}
 	
/*--------------------*/
	
	cout<<endl<<"Part 2:"<<endl<<endl;
	regex pattern3{R"(<head>([\s\S]+)<title>)"};
    regex pat4{R"(</title>([\s\S]+)</head>)"};
    string toSearch = "<html><head>Wow such a header <title>This is a title</title>"
                          "So top</head>Much body</html>";
	smatch matches2;
	smatch matche2;
	regex_search(toSearch, matches2, pattern3); 
	regex_search(toSearch, matche2, pat4); 
	cout << matches2[1];
	//cout << matches2[1] << endl;
	cout << matche2[1]<<endl;
	//cout << matche2[1]<<endl;

	/*-------------------*/

	cout<<endl<<"Part 3:"<<endl<<endl;
	ifstream in{"stroustrup.txt"};
	if(!in) cerr <<"no file\n";
	regex ppt{R"(<a href=\"([\s\S]+\.ppt)\">)"};
	int lineno = 0;
	for(string line; getline(in,line);){
		smatch powerpoints;
		if(regex_search(line,powerpoints,ppt)){
			++lineno;
			cout <<lineno<< ": "<<powerpoints[1]<<endl;
		}
	}

return 0; }