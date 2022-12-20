#ifndef _INCLUDE_MOVEPLAYER_H_
#define _INCLUDE_MOVEPLAYER_H_

namespace google {

struct Move {
  int x;
  int y;
};

struct Placement {
  Move move;
  int length;
  bool sideways;
};

}

#endif