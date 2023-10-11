
// [do not edit,<auto-generated />]
// This file has been automatically generated, please do not change unless you disable auto-generation in the Makefile  
#include <libtcc.h>
#include <spin.h>

namespace spin {
namespace tcc {

using v8::String;
using v8::FunctionCallbackInfo;
using v8::Array;
using v8::Local;
using v8::ObjectTemplate;
using v8::Isolate;
using v8::Value;
using v8::Uint32Array;
using v8::ArrayBuffer;
using v8::Context;
using v8::Integer;
using v8::Function;
using v8::NewStringType;
using v8::Object;
using v8::BackingStore;
using v8::TryCatch;
using v8::ScriptCompiler;
using v8::Module;
using v8::FixedArray;
using v8::ScriptOrigin;
using v8::SharedArrayBuffer;
using v8::MaybeLocal;
using v8::HandleScope;
using v8::Promise;
using v8::Number;
using v8::StackTrace;
using v8::Message;
using v8::StackFrame;
using v8::Maybe;
using v8::FunctionTemplate;
using v8::FunctionCallback;
using v8::PromiseRejectMessage;
using v8::CFunction;
using v8::Global;
using v8::Exception;
using v8::CTypeInfo;
using v8::PropertyAttribute;
using v8::Signature;
using v8::ConstructorBehavior;
using v8::SideEffectType;
using v8::kPromiseRejectAfterResolved;
using v8::kPromiseResolveAfterResolved;
using v8::kPromiseHandlerAddedAfterReject;
using v8::Data;
using v8::PrimitiveArray;
using v8::TypedArray;
using v8::Uint8Array;
using v8::Boolean;
using v8::ModuleRequest;
using v8::CFunctionInfo;
using v8::OOMDetails;
using v8::V8;
using v8::BigInt;



void tcc_newFast(void* p, struct FastApiTypedArray* const p_ret);
v8::CTypeInfo cargstcc_new[2] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),

  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rctcc_new = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infotcc_new = v8::CFunctionInfo(rctcc_new, 2, cargstcc_new);
v8::CFunction pFtcc_new = v8::CFunction((const void*)&tcc_newFast, &infotcc_new);

void tcc_deleteFast(void* p, void* p0);
v8::CTypeInfo cargstcc_delete[2] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rctcc_delete = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infotcc_delete = v8::CFunctionInfo(rctcc_delete, 2, cargstcc_delete);
v8::CFunction pFtcc_delete = v8::CFunction((const void*)&tcc_deleteFast, &infotcc_delete);

int32_t tcc_set_output_typeFast(void* p, void* p0, int32_t p1);
v8::CTypeInfo cargstcc_set_output_type[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kInt32),
};
v8::CTypeInfo rctcc_set_output_type = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_set_output_type = v8::CFunctionInfo(rctcc_set_output_type, 3, cargstcc_set_output_type);
v8::CFunction pFtcc_set_output_type = v8::CFunction((const void*)&tcc_set_output_typeFast, &infotcc_set_output_type);

void tcc_set_optionsFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_set_options[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_set_options = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infotcc_set_options = v8::CFunctionInfo(rctcc_set_options, 3, cargstcc_set_options);
v8::CFunction pFtcc_set_options = v8::CFunction((const void*)&tcc_set_optionsFast, &infotcc_set_options);

int32_t tcc_add_library_pathFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_add_library_path[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_add_library_path = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_add_library_path = v8::CFunctionInfo(rctcc_add_library_path, 3, cargstcc_add_library_path);
v8::CFunction pFtcc_add_library_path = v8::CFunction((const void*)&tcc_add_library_pathFast, &infotcc_add_library_path);

int32_t tcc_add_libraryFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_add_library[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_add_library = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_add_library = v8::CFunctionInfo(rctcc_add_library, 3, cargstcc_add_library);
v8::CFunction pFtcc_add_library = v8::CFunction((const void*)&tcc_add_libraryFast, &infotcc_add_library);

int32_t tcc_add_include_pathFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_add_include_path[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_add_include_path = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_add_include_path = v8::CFunctionInfo(rctcc_add_include_path, 3, cargstcc_add_include_path);
v8::CFunction pFtcc_add_include_path = v8::CFunction((const void*)&tcc_add_include_pathFast, &infotcc_add_include_path);

int32_t tcc_add_fileFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_add_file[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_add_file = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_add_file = v8::CFunctionInfo(rctcc_add_file, 3, cargstcc_add_file);
v8::CFunction pFtcc_add_file = v8::CFunction((const void*)&tcc_add_fileFast, &infotcc_add_file);

int32_t tcc_compile_stringFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_compile_string[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_compile_string = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_compile_string = v8::CFunctionInfo(rctcc_compile_string, 3, cargstcc_compile_string);
v8::CFunction pFtcc_compile_string = v8::CFunction((const void*)&tcc_compile_stringFast, &infotcc_compile_string);

int32_t tcc_relocateFast(void* p, void* p0, void* p1);
v8::CTypeInfo cargstcc_relocate[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rctcc_relocate = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_relocate = v8::CFunctionInfo(rctcc_relocate, 3, cargstcc_relocate);
v8::CFunction pFtcc_relocate = v8::CFunction((const void*)&tcc_relocateFast, &infotcc_relocate);

void tcc_get_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, struct FastApiTypedArray* const p_ret);
v8::CTypeInfo cargstcc_get_symbol[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint32, v8::CTypeInfo::SequenceType::kIsTypedArray, v8::CTypeInfo::Flags::kNone)
};
v8::CTypeInfo rctcc_get_symbol = v8::CTypeInfo(v8::CTypeInfo::Type::kVoid);
v8::CFunctionInfo infotcc_get_symbol = v8::CFunctionInfo(rctcc_get_symbol, 4, cargstcc_get_symbol);
v8::CFunction pFtcc_get_symbol = v8::CFunction((const void*)&tcc_get_symbolFast, &infotcc_get_symbol);

int32_t tcc_add_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, void* p2);
v8::CTypeInfo cargstcc_add_symbol[4] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
};
v8::CTypeInfo rctcc_add_symbol = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_add_symbol = v8::CFunctionInfo(rctcc_add_symbol, 4, cargstcc_add_symbol);
v8::CFunction pFtcc_add_symbol = v8::CFunction((const void*)&tcc_add_symbolFast, &infotcc_add_symbol);

int32_t tcc_output_fileFast(void* p, void* p0, struct FastOneByteString* const p1);
v8::CTypeInfo cargstcc_output_file[3] = {
  v8::CTypeInfo(v8::CTypeInfo::Type::kV8Value),
  v8::CTypeInfo(v8::CTypeInfo::Type::kUint64),
  v8::CTypeInfo(v8::CTypeInfo::Type::kSeqOneByteString),
};
v8::CTypeInfo rctcc_output_file = v8::CTypeInfo(v8::CTypeInfo::Type::kInt32);
v8::CFunctionInfo infotcc_output_file = v8::CFunctionInfo(rctcc_output_file, 3, cargstcc_output_file);
v8::CFunction pFtcc_output_file = v8::CFunction((const void*)&tcc_output_fileFast, &infotcc_output_file);



void tcc_newSlow(const FunctionCallbackInfo<Value> &args) {

  void* rc = tcc_new();
  Local<ArrayBuffer> ab = args[0].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void tcc_newFast(void* p, struct FastApiTypedArray* const p_ret) {

  void* r = tcc_new();
  ((void**)p_ret->data)[0] = r;

}
void tcc_deleteSlow(const FunctionCallbackInfo<Value> &args) {
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  tcc_delete(v0);
}

void tcc_deleteFast(void* p, void* p0) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  tcc_delete(v0);
}
void tcc_set_output_typeSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  int32_t v1 = Local<Integer>::Cast(args[1])->Value();
  int32_t rc = tcc_set_output_type(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_set_output_typeFast(void* p, void* p0, int32_t p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  int32_t v1 = p1;
  return tcc_set_output_type(v0, v1);
}
void tcc_set_optionsSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  tcc_set_options(v0, *v1);
}

void tcc_set_optionsFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  tcc_set_options(v0, v1->data);
}
void tcc_add_library_pathSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_library_path(v0, *v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_add_library_pathFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_library_path(v0, v1->data);
}
void tcc_add_librarySlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_library(v0, *v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_add_libraryFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_library(v0, v1->data);
}
void tcc_add_include_pathSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_include_path(v0, *v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_add_include_pathFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_include_path(v0, v1->data);
}
void tcc_add_fileSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_add_file(v0, *v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_add_fileFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_add_file(v0, v1->data);
}
void tcc_compile_stringSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_compile_string(v0, *v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_compile_stringFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_compile_string(v0, v1->data);
}
void tcc_relocateSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  void* v1 = reinterpret_cast<void*>((uint64_t)Local<Integer>::Cast(args[1])->Value());
  int32_t rc = tcc_relocate(v0, v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_relocateFast(void* p, void* p0, void* p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  void* v1 = reinterpret_cast<void*>(p1);
  return tcc_relocate(v0, v1);
}
void tcc_get_symbolSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  void* rc = tcc_get_symbol(v0, *v1);
  Local<ArrayBuffer> ab = args[2].As<Uint32Array>()->Buffer();
  ((void**)ab->Data())[0] = rc;
}

void tcc_get_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, struct FastApiTypedArray* const p_ret) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  void* r = tcc_get_symbol(v0, v1->data);
  ((void**)p_ret->data)[0] = r;

}
void tcc_add_symbolSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  const void* v2 = reinterpret_cast<const void*>((uint64_t)Local<Integer>::Cast(args[2])->Value());
  int32_t rc = tcc_add_symbol(v0, *v1, v2);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_add_symbolFast(void* p, void* p0, struct FastOneByteString* const p1, void* p2) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  const void* v2 = reinterpret_cast<const void*>(p2);
  return tcc_add_symbol(v0, v1->data, v2);
}
void tcc_output_fileSlow(const FunctionCallbackInfo<Value> &args) {
  Isolate *isolate = args.GetIsolate();
  TCCState* v0 = reinterpret_cast<TCCState*>((uint64_t)Local<Integer>::Cast(args[0])->Value());
  String::Utf8Value v1(isolate, args[1]);
  int32_t rc = tcc_output_file(v0, *v1);
  args.GetReturnValue().Set(Number::New(isolate, rc));
}

int32_t tcc_output_fileFast(void* p, void* p0, struct FastOneByteString* const p1) {
  TCCState* v0 = reinterpret_cast<TCCState*>(p0);
  struct FastOneByteString* const v1 = p1;
  return tcc_output_file(v0, v1->data);
}

void Init(Isolate* isolate, Local<ObjectTemplate> target) {
  Local<ObjectTemplate> module = ObjectTemplate::New(isolate);
  SET_FAST_METHOD(isolate, module, "tcc_new", &pFtcc_new, tcc_newSlow);
  SET_FAST_METHOD(isolate, module, "tcc_delete", &pFtcc_delete, tcc_deleteSlow);
  SET_FAST_METHOD(isolate, module, "tcc_set_output_type", &pFtcc_set_output_type, tcc_set_output_typeSlow);
  SET_FAST_METHOD(isolate, module, "tcc_set_options", &pFtcc_set_options, tcc_set_optionsSlow);
  SET_FAST_METHOD(isolate, module, "tcc_add_library_path", &pFtcc_add_library_path, tcc_add_library_pathSlow);
  SET_FAST_METHOD(isolate, module, "tcc_add_library", &pFtcc_add_library, tcc_add_librarySlow);
  SET_FAST_METHOD(isolate, module, "tcc_add_include_path", &pFtcc_add_include_path, tcc_add_include_pathSlow);
  SET_FAST_METHOD(isolate, module, "tcc_add_file", &pFtcc_add_file, tcc_add_fileSlow);
  SET_FAST_METHOD(isolate, module, "tcc_compile_string", &pFtcc_compile_string, tcc_compile_stringSlow);
  SET_FAST_METHOD(isolate, module, "tcc_relocate", &pFtcc_relocate, tcc_relocateSlow);
  SET_FAST_METHOD(isolate, module, "tcc_get_symbol", &pFtcc_get_symbol, tcc_get_symbolSlow);
  SET_FAST_METHOD(isolate, module, "tcc_add_symbol", &pFtcc_add_symbol, tcc_add_symbolSlow);
  SET_FAST_METHOD(isolate, module, "tcc_output_file", &pFtcc_output_file, tcc_output_fileSlow);


  SET_MODULE(isolate, target, "tcc", module);
}
} // namespace tcc
} // namespace spin

extern "C" {
  void* _register_tcc() {
    return (void*)spin::tcc::Init;
  }
}