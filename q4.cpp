//Concatenate a string
#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100];
    int i=0, j=0;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    while(str1[i] != '\0') i++;
    while(str2[j] != '\0') {
        str1[i] = str2[j];
        i++; j++;
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1;
}


//Reverse a string
#include <iostream>
using namespace std;

int main() {
    char str[100];
    int len=0;
    cout << "Enter a string: ";
    cin >> str;
    while(str[len] != '\0') len++;
    cout << "Reversed string: ";
    for(int i=len-1; i>=0; i--)
        cout << str[i];
}


//Delete vowels
#include <iostream>
using namespace std;

int main() {
    char str[100], res[100];
    int i=0, j=0;
    cout << "Enter a string: ";
    cin >> str;
    while(str[i] != '\0') {
        char ch = str[i];
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' &&
           ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U') {
            res[j] = ch;
            j++;
        }
        i++;
    }
    res[j] = '\0';
    cout << "String after removing vowels: " << res;
}


//Sort String Alphabateically
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char str[100][100], temp[100];
    for(int i=0; i<n; i++)
        cin >> str[i];
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(strcmp(str[i], str[j]) > 0) {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for(int i=0; i<n; i++)
        cout << str[i] << endl;
}

//Character Lowercase to uppercase
#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter uppercase character: ";
    cin >> ch;
    if(ch >= 'A' && ch <= 'Z')
        ch = ch + 32;
    cout << "Lowercase: " << ch;
}

