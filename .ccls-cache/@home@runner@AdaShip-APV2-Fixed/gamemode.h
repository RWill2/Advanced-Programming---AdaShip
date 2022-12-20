#ifndef _INCLUDE_GAMEMODE_H_
#define _INCLUDE_GAMEMODE_H_

namespace google {

class GameMode {
 public:
  GameMode() : _active(true) {}

  void Execute() {
    while (_active) {
      Render();
      WaitForInput();
      Tick();
    }
  }

  virtual void WaitForInput() = 0;
  virtual void Tick() = 0;
  virtual void Render() = 0;

 protected:
  bool _active;
};

} 

#endif 