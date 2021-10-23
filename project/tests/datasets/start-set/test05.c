//clang -Xclang -ast-dump -fsyntax-only test05.c

int a = 2;

int main() {
    a = a + 2;
    a;
    //return 0;
}