#include <bits/stdc++.h>
using namespace std;

bool check_expression(string& s){
	stack<char> st;
	for(char c: s){
		if(c == '(' || c== '[' || c== '{')
			st.push(c);
		else{
			if(c == ')' && (st.top()=='[' || st.top()=='{')) return false;
			if(c == ']' && (st.top()=='{' || st.top()=='(')) return false;
			if(c == '}' && (st.top()=='(' || st.top()=='[')) return false;
			st.pop();
		}
	}
	return true;
}
int main(){
	string s="[{)}]";
	bool state=check_expression(s);
	if(state) cout << "Expression is correct\n";
	else      cout << "Expression is incorrect\n";
	return 0;
}
