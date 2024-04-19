// lua example embed from wiki

#include "MatlabEngine.hpp"
#include <memory>
#include <stdio.h>

using namespace matlab::engine;
int main() {

  // create matlab engine
std::unique_ptr<MATLABEngine> engine = startMATLAB();
  //MATLABEngine *engine = matlab::engine::MATLABEngine;

  // load string
  return 0;
}
