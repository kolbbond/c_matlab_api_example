// matlab example embed from docs

#include "MatlabEngine.hpp"
#include "MatlabExecutionInterface/util.hpp"
#include <memory>
#include <sstream>
#include <stdio.h>
#include <string>

using namespace matlab::engine;

void printBuf(const std::shared_ptr<std::basic_stringbuf<char16_t>> buf) {
  // convert stream buffers to str
  auto str = buf->str();
  std::cout << "*" << matlab::execution::convertUTF16StringToUTF8String(str)
            << "*" << std::endl;
}

int main() {

  // print out from within engine?
  // engine->feval(u"disp",double(4));
  printf("starting matlab\n");
  std::unique_ptr<MATLABEngine> matlabPtr = startMATLAB();
  printf("GOOD\n");

  //////////////////////////////////////////////////
  // try to use as interpreter
  // does this mean we do not need to get the results here??? @hey?

  // our string
  std::string str_use("a = sqrt(12.7);");

  // convert to matlab string
  matlab::engine::String str_in =
      matlab::engine::convertUTF8StringToUTF16String(str_use);

  // output is stored in streambuffers
  // std::shared_ptr<matlab::engine::StreamBuffer> buf_out;
  // std::shared_ptr<matlab::engine::StreamBuffer> buf_err;
  auto buf_out = std::make_shared<std::basic_stringbuf<char16_t>>();
  auto buf_err = std::make_shared<std::basic_stringbuf<char16_t>>();

  // open a workspace?
  matlabPtr->eval(u"workspace;");

  // eval does not output a result
  //matlabPtr->eval(str_in, buf_out, buf_err);
  matlabPtr->eval(u"why", buf_out, buf_err);

  printf("Buffer print: ");
  printBuf(buf_out);
  printf("Error print: ");
  printBuf(buf_err);

  // feval do
  auto a = matlabPtr->feval<double>(u"sqrt", double(12.7));
  printf("a = %0.2f\n", a);

  // return
  return 0;
}
