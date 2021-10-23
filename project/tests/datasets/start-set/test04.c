//clang -Xclang -ast-dump -fsyntax-only test04.c

int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e;
double x;


int main() {
    e = (a + b) * c - d;
    e;
    //return 0;
}