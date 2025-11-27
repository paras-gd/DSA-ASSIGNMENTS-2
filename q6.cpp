// Sparse Matrix Operations using Triplet Representation
#include <iostream>
using namespace std;

struct term {
    int row, col, val;
};

void read(term a[]) {
    cout << "Enter rows, cols and non-zero elements: ";
    cin >> a[0].row >> a[0].col >> a[0].val;
    cout << "Enter triplets (row col value):\n";
    for (int i=1; i<=a[0].val; i++)
        cin >> a[i].row >> a[i].col >> a[i].val;
}

void display(term a[]) {
    for (int i=0; i<=a[0].val; i++)
        cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
}

void transpose(term a[], term b[]) {
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    int k = 1;
    for (int i=0; i<a[0].col; i++) {
        for (int j=1; j<=a[0].val; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

void add(term a[], term b[], term c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible\n"; return;
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;
    int i=1, j=1, k=1;
    while (i<=a[0].val && j<=b[0].val) {
        if (a[i].row==b[j].row && a[i].col==b[j].col) {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        } else if (a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col)) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i<=a[0].val) c[k++] = a[i++];
    while (j<=b[0].val) c[k++] = b[j++];
    c[0].val = k-1;
}

void multiply(term a[], term b[], term c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible\n"; return;
    }
    term bt[100];
    transpose(b, bt);
    c[0].row = a[0].row;
    c[0].col = b[0].col;
    int k = 1;
    for (int i=1; i<=a[0].val;) {
        int r = a[i].row;
        for (int j=1; j<=bt[0].val;) {
            int ccol = bt[j].row;
            int sum = 0;
            int tempa = i, tempb = j;
            while (tempa<=a[0].val && a[tempa].row==r &&
                   tempb<=bt[0].val && bt[tempb].row==ccol) {
                if (a[tempa].col < bt[tempb].col) tempa++;
                else if (a[tempa].col > bt[tempb].col) tempb++;
                else {
                    sum += a[tempa].val * bt[tempb].val;
                    tempa++; tempb++;
                }
            }
            if (sum != 0) {
                c[k].row = r;
                c[k].col = ccol;
                c[k].val = sum;
                k++;
            }
            while (j<=bt[0].val && bt[j].row==ccol) j++;
        }
        while (i<=a[0].val && a[i].row==r) i++;
    }
    c[0].val = k-1;
}

int main() {
    int ch;
    cout << "1. Transpose  2. Addition  3. Multiplication\nEnter choice: ";
    cin >> ch;
    term a[100], b[100], c[100];
    if (ch == 1) {
        read(a);
        transpose(a, b);
        cout << "Transpose:\n"; display(b);
    } else if (ch == 2) {
        cout << "Matrix A:\n"; read(a);
        cout << "Matrix B:\n"; read(b);
        add(a, b, c);
        cout << "Result:\n"; display(c);
    } else if (ch == 3) {
        cout << "Matrix A:\n"; read(a);
        cout << "Matrix B:\n"; read(b);
        multiply(a, b, c);
        cout << "Result:\n"; display(c);
    }
}
