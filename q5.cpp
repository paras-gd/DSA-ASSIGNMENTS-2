// Efficient Storage of Special Matrices
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter order of matrix: ";
    cin >> n;

    int ch;
    cout << "1. Diagonal  2. Tri-diagonal  3. Lower Triangular  4. Upper Triangular  5. Symmetric\n";
    cout << "Enter choice: ";
    cin >> ch;

    if (ch == 1) { // Diagonal
        int d[n];
        cout << "Enter diagonal elements: ";
        for (int i=0; i<n; i++) cin >> d[i];
        cout << "Matrix:\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                cout << (i==j ? d[i] : 0) << " ";
            cout << endl;
        }
    }

    else if (ch == 2) { // Tri-diagonal
        int size = 3*n - 2;
        int t[size];
        cout << "Enter tri-diagonal elements: ";
        for (int i=0; i<size; i++) cin >> t[i];
        cout << "Matrix:\n";
        int k=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i-j==1 || i-j==0 || i-j==-1)
                    cout << t[k++] << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }

    else if (ch == 3) { // Lower triangular
        int size = n*(n+1)/2;
        int l[size];
        cout << "Enter lower triangular elements: ";
        for (int i=0; i<size; i++) cin >> l[i];
        cout << "Matrix:\n";
        int k=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i >= j) cout << l[k++] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }

    else if (ch == 4) { // Upper triangular
        int size = n*(n+1)/2;
        int u[size];
        cout << "Enter upper triangular elements: ";
        for (int i=0; i<size; i++) cin >> u[i];
        cout << "Matrix:\n";
        int k=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i <= j) cout << u[k++] << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }

    else if (ch == 5) { // Symmetric
        int size = n*(n+1)/2;
        int s[size];
        cout << "Enter lower triangular elements of symmetric matrix: ";
        for (int i=0; i<size; i++) cin >> s[i];
        cout << "Matrix:\n";
        int k=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i >= j)
                    cout << s[i*(i+1)/2 + j] << " ";
                else
                    cout << s[j*(j+1)/2 + i] << " ";
            }
            cout << endl;
        }
    }
}
