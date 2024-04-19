// matlab example embed from docs

#include "MatlabEngine.hpp"
#include "MatlabExecutionInterface/util.hpp"
#include <memory>
#include <stdio.h>
#include <string>

using namespace matlab::engine;
int main() {

  // print out from within engine?
  // engine->feval(u"disp",double(4));
  printf("starting matlab\n");
  std::unique_ptr<MATLABEngine> matlabPtr = startMATLAB();
  printf("GOOD\n");

  // try to use as interpreter
  std::string str_use("a = sqrt(12.7);");
  matlab::engine::String str_in = matlab::engine::convertUTF8StringToUTF16String(str_use);
  // str1 = "why;";

  matlabPtr->eval(str_in);

  // return
  return 0;
}
