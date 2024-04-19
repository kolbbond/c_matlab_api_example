// matlab example embed from docs

#include "MatlabEngine.hpp"
#include "MatlabEngine/engine_factory.hpp"
#include "MatlabEngine/matlab_engine.hpp"
#include "MatlabExecutionInterface/util.hpp"
#include "MatlabExecutionInterface/value_future.hpp"
#include <memory>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace matlab::engine;

void printBuf(const std::shared_ptr<std::basic_stringbuf<char16_t>> buf) {
  // convert stream buffers to str
  auto str = buf->str();
  std::cout << matlab::execution::convertUTF16StringToUTF8String(str);
}

int main() {

  // print out from within engine?
  // engine->feval(u"disp",double(4));
  printf("starting matlab\n");
  //  std::unique_ptr<MATLABEngine> matlabPtr = startMATLAB();

  // async start matlab
  FutureResult<std::unique_ptr<MATLABEngine>> matlabFuture = startMATLABAsync();
  //
  printf("matlab is starting in background\n");
  printf("do other stuff here\n");

  std::unique_ptr<MATLABEngine> matlabPtr = matlabFuture.get();
  printf("GOOD\n");

  // GAME LOOP!
  //////////////////////////////////////////////////
  // try to use as interpreter
  // does this mean we do not need to get the results here??? @hey?

  // string to use as user input
  std::string str_use;

  bool done = false;

  // open a workspace?
  matlabPtr->eval(u"workspace;");

  while (!done) {

    // our string
    printf(">> ");
    std::getline(std::cin, str_use);
    if (str_use == "exit"){
      printf("EXIT NOW\n");
      done = true;
      break;
    }

    // convert to matlab string
    matlab::engine::String str_in =
        matlab::engine::convertUTF8StringToUTF16String(str_use);

    // output is stored in streambuffers
    auto buf_out = std::make_shared<std::basic_stringbuf<char16_t>>();
    auto buf_err = std::make_shared<std::basic_stringbuf<char16_t>>();

    // eval does not output a result
    matlabPtr->eval(str_in, buf_out, buf_err);

    // print whatever matlab outputted
    // printf("\n");
    printBuf(buf_out);
    // printf(" ");
    printBuf(buf_err);
  }

  // return
  return 0;
}
