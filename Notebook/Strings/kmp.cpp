#include<bits/stdc++.h>
using namespace std;
void makelps(string pat, int m, int *lps){
    int len = 0;
    lps[0] = 0; //Siempre lps[0] empieza en 0
    for(int i = 1; i < m; i){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(len != 0){
                len = lps[len - 1];
            } else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
void kmp(string txt, string pat){
    int n = txt.size(), m = pat.size();
    int lps[m];
    makelps(pat, m, lps);
    int i = 0, j = 0;
    while(i < n){
        if(pat[j] == txt[i]){
            j++;
            i++;
        }
        if(j == m){
            cout<<"Ocurrencia encontrada en el index: "<<(i - j)<<endl;
            j = lps[j - 1];
        } else if(i < n && pat[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
}
int main(){
    string txt = "AAAABCAABCAAAA";
    string pat = "ABC";
    kmp(txt, pat);
    return 0;
}