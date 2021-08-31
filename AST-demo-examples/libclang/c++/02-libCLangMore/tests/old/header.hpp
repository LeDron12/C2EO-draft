// header.hpp
const int x = 0x10;
double y = 3.14;
long long t = 100ll;

class MyClass
{
public:
  int field = 0;
  virtual void method() const = 0;

  static const int static_field;
  static int static_method();
};
/*
enum Enum
{
  RED0 = 10,
  BLUE0 = 20
};

enum class Cpp11Enum
{
  RED = 10,
  BLUE = 20
};

struct Wowza
{
  virtual ~Wowza() = default;
  virtual void foo(int i = 0) = 0;
};

struct Badabang : Wowza
{
  void foo(int) override;

  bool operator==(const Badabang& o) const;
};

template <typename T>
void bar(T&& t);
struct figure {
    int key;
    union variant {
        triangle t;
        rectangle *r;
    };
};

struct figure f;
int a, b = 10, c = 5;

void ff() {
    a = b + c;
}
*/
