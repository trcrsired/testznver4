#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/Support/TargetSelect.h"

#include <string>

using namespace llvm;

int main(int argc, char *argv[]) {
  InitLLVM _(argc, argv);

  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargets();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmPrinters();
  llvm::InitializeAllAsmParsers();
  llvm::InitializeNativeTarget();

  ::std::string hosttriple = ::llvm::sys::getProcessTriple();
  ::std::string hostcpu = std::string(::llvm::sys::getHostCPUName());

  llvm::Triple triple(hosttriple);
  llvm::SmallVector<std::string, 1> targetAttributes;
  llvm::EngineBuilder engineBuilder;
  std::string errormessage;
  engineBuilder.setErrorStr(&errormessage);
  std::unique_ptr<llvm::TargetMachine> targetMachine(
    engineBuilder.selectTarget(triple, "", hostcpu, targetAttributes));
  outs() << "targetMachine = " << (void*)targetMachine.get() <<"\n"
  	"hosttriple: " << hosttriple <<"\n"
	  "hostcpu:"<< hostcpu << "\n"
	  "hostcpu==\"znver4\"?" << (hostcpu=="znver4") << '\n' ;
}