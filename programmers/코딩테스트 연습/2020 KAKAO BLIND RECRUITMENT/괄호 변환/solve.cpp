#include <string>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

inline int convert(char ch) {
    if(ch=='(')
        return 1;
    return -1;
}

bool isCorrect(const string& s) {
    stack<char> opening;
    for(int i=0;i<s.size();++i) {
        if(s[i]=='(')
            opening.push('(');
        else {
            if(opening.empty())
                return false;
            opening.pop();
        }
    }
    return opening.empty();
}

void reverse(string& s) {
    for(int i=0;i<s.size();++i) {
        if(s[i]=='(')
            s[i]=')';
        else
            s[i]='(';
    }
}

string solution(string p) {
    // 빈 문자열 혹은 올바른 괄호 문자열인 경우 그대로 반환
    if(p.empty() || isCorrect(p))
        return p;
    
    // 문자열을 균형잡힌 괄호 문자열로 앞 뒤 나눈다.
    int idx=0, diff=0;
    while(idx!=p.size()) {
        diff+=convert(p[idx]);
        ++idx;
        if(diff==0)
            break;
    }
    
    string first=p.substr(0,idx);
    string second=p.substr(idx);
    string ret;
    if(!isCorrect(first)) {
        ret="(";
        ret+=solution(second)+")";
        // u의 첫 번째와 마지막 문자를 제거한 뒤 뒤집어 붙인다.
        string back=first.substr(1,first.size()-2);
        reverse(back);
        ret+=back;
    }
    else {
        ret+=first;
        ret+=solution(second);
    }
        
    return ret;
}
