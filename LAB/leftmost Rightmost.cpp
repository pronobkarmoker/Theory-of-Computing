#include <bits/stdc++.h>
using namespace std;

string S;
vector<string> A;
vector<string> B;
vector<string> symbols;
vector<string> veriables;

vector<string> ans;


bool hasThere(vector<string> v, string s){
    for(int i=0; i<v.size(); i++){
        if(v[i] == s){
            return true;
        }
    }
    return false;
}

string inSymbol(){
    for(int i=0; i<S.size(); i++){
        if(S[i] == '0'){
            return "0";
        }
        else if(S[i] == '1'){
            return "1";
        }
    }
    return "";
}


int main(){
    
    S = "A1B";
    A.push_back("0");
    // A.push_back("e");
    B.push_back("0");
    B.push_back("1");
    // B.push_back("e");
    symbols.push_back("0");
    symbols.push_back("1");
    veriables.push_back("A");
    veriables.push_back("B");

    string input;
    cout << "Enter a string: ";
    cin >> input;


    // Leftmost derivation
    string temp = input;
    string innerSsymbol = inSymbol();
    int posInner = S.find_last_of(innerSsymbol);
    string ansTemp = S;
    cout << "LMD : " << ansTemp << "  ";

    for(int i=0; i<temp.size(); i++){
        int j=0;
        for(; j<ansTemp.size(); j++){
            if(hasThere(veriables, string(1, ansTemp[j]))){
                i = j;
                break;
            }
        }

        if(ansTemp[j] == 'A'){
            if(hasThere(A, string(1, temp[i]))){
                string ansStr = (string(1, temp[i]) + "A");
                ansTemp.replace(j, 1, ansStr);
            }
            else{
                ansTemp.replace(j, 1, "");
            }
        }else if(ansTemp[j] == 'B'){
            if(hasThere(B, string(1, temp[i]))){
                string ansStr = (string(1, temp[i]) + "B");
                ansTemp.replace(j, 1, ansStr);
            }
            else{
                ansTemp.replace(j, 1, "");
            }
        }else continue;

        if(i==(temp.size()-1)){
            cout << ansTemp << "  ";
            ansTemp.replace(i+1, 1, "");
        }

        cout << ansTemp << "  ";
    }


    //Rightmost Derivation
    string temp2 = input;
    string innerSsymbol2 = inSymbol();
    int posInS = S.find_first_of(innerSsymbol2);
    int posInTemp2 = temp2.find_first_of(innerSsymbol2);
    string ansTemp2 = S;

    // cout << "\nposInTemp2 : \n" << posInTemp2 ;

    cout << "\nRMD : " << ansTemp2 << "  ";

    // after the breakpoint [first value of innersymbol of S in temp2]
    for(int i=posInTemp2+1; i<temp2.size(); i++){
        int j = ansTemp2.size()-1;
        for(; j>=0; j--){
            if(hasThere(veriables, string(1, ansTemp2[j]))){
                // i = j;
                break;
            }
        }

        if(ansTemp2[j] == 'A'){
            if(hasThere(A, string(1, temp2[i]))){
                string ansStr = (string(1, temp2[i]) + "A");
                ansTemp2.replace(j, 1, ansStr);
            }
            else{
                ansTemp2.replace(j, 1, "");
                cout << ansTemp2 << "  ";
                break;
            }
        }else if(ansTemp2[j] == 'B'){
            if(hasThere(B, string(1, temp2[i]))){
                string ansStr = (string(1, temp2[i]) + "B");
                ansTemp2.replace(j, 1, ansStr);
            }
            else{
                ansTemp2.replace(j, 1, "");
                cout << ansTemp2 << "  ";
                break;
            }
        }

        if(i==(temp2.size()-1)){
            if(i>j){
                cout << ansTemp2 << "  ";
                ansTemp2.replace(i, 1, "");
            }else{
                cout << ansTemp2 << "  ";
                ansTemp2.replace(j+1, 1, "");
            }
        }

        cout << ansTemp2 << "  ";
    }

    // after the breakpoint [first value of innersymbol of S in temp2]
    for(int i=0; i<=posInTemp2; i++){
        int j = ansTemp2.size()-1;
        for(; j>=0; j--){
            if(hasThere(veriables, string(1, ansTemp2[j]))){
                break;
            }
        }

        if(ansTemp2[j] == 'A'){
            if(hasThere(A, string(1, temp2[i]))){
                string ansStr = (string(1, temp2[i]) + "A");
                ansTemp2.replace(j, 1, ansStr);
            }
            else{
                ansTemp2.replace(j, 1, "");
                cout << ansTemp2 << "  ";
                break;
            }
        }else if(ansTemp2[j] == 'B'){
            if(hasThere(B, string(1, temp2[i]))){
                string ansStr = (string(1, temp2[i]) + "B");
                ansTemp2.replace(j, 1, ansStr);
            }
            else{
                ansTemp2.replace(j, 1, "");
                cout << ansTemp2 << "  ";
                break;
            }
        }

        if(i==(posInTemp2)){
            if(i>=j){
                cout << ansTemp2 << "  ";
                ansTemp2.replace(i+1, 1, "");
            }else{
                cout << ansTemp2 << "  ";
                ansTemp2.replace(j, 2, "");
            }
        }

        cout << ansTemp2 << "  ";
    }

}