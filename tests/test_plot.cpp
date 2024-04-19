// matlab example embed from docs

#include "MatlabEngine.hpp"
#include <memory>
#include <stdio.h>

using namespace matlab::engine;
int main() {

  // print out from within engine?
  // engine->feval(u"disp",double(4));
  printf("starting matlab");
  std::unique_ptr<MATLABEngine> matlabPtr = startMATLAB();
  printf("GOOD");
  matlab::data::ArrayFactory factory;
  matlab::data::Array yData =
      factory.createArray<double>({1, 5}, {4.0, 11.0, 4.7, 36.2, 72.3});
  matlab::data::Array lineHandle = matlabPtr->feval(u"plot", yData);
  matlab::data::CharArray lineStyle = factory.createCharArray(":");
  matlabPtr->setProperty(lineHandle, u"LineStyle", lineStyle);
  //while(true){
   //   }

  // return
  return 0;
}
