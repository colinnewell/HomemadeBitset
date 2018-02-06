#include <memory>

namespace CPPLondonUni {
class Bitset // FIXED SET OFF 8bit
{
public:
  Bitset(char);

public: // Functions
  bool test(int);

  bool all();
  bool any();
  bool none();

  int count();

  int size();

  void set(int);
  void reset(int);

  void flip();

private: // Members
  char bitfield = 0x00;
};
} // namespace CPPLondonUni