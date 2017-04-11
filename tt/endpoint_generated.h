// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ENDPOINT_IROHA_H_
#define FLATBUFFERS_GENERATED_ENDPOINT_IROHA_H_

#include "flatbuffers/flatbuffers.h"

#include "account_generated.h"
#include "asset_generated.h"
#include "commands_generated.h"
#include "main_generated.h"
#include "primitives_generated.h"
#include "transaction_generated.h"

namespace iroha {

struct Response;

struct Response FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MESSAGE = 4,
    VT_CODE = 6,
    VT_SIGNATURE = 8
  };
  const flatbuffers::String *message() const {
    return GetPointer<const flatbuffers::String *>(VT_MESSAGE);
  }
  iroha::Code code() const {
    return static_cast<iroha::Code>(GetField<uint8_t>(VT_CODE, 0));
  }
  const iroha::Signature *signature() const {
    return GetPointer<const iroha::Signature *>(VT_SIGNATURE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           verifier.Verify(message()) &&
           VerifyField<uint8_t>(verifier, VT_CODE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SIGNATURE) &&
           verifier.VerifyTable(signature()) &&
           verifier.EndTable();
  }
};

struct ResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message(flatbuffers::Offset<flatbuffers::String> message) {
    fbb_.AddOffset(Response::VT_MESSAGE, message);
  }
  void add_code(iroha::Code code) {
    fbb_.AddElement<uint8_t>(Response::VT_CODE, static_cast<uint8_t>(code), 0);
  }
  void add_signature(flatbuffers::Offset<iroha::Signature> signature) {
    fbb_.AddOffset(Response::VT_SIGNATURE, signature);
  }
  ResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ResponseBuilder &operator=(const ResponseBuilder &);
  flatbuffers::Offset<Response> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<Response>(end);
    return o;
  }
};

inline flatbuffers::Offset<Response> CreateResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> message = 0,
    iroha::Code code = iroha::Code_COMMIT,
    flatbuffers::Offset<iroha::Signature> signature = 0) {
  ResponseBuilder builder_(_fbb);
  builder_.add_signature(signature);
  builder_.add_message(message);
  builder_.add_code(code);
  return builder_.Finish();
}

inline flatbuffers::Offset<Response> CreateResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *message = nullptr,
    iroha::Code code = iroha::Code_COMMIT,
    flatbuffers::Offset<iroha::Signature> signature = 0) {
  return iroha::CreateResponse(
      _fbb,
      message ? _fbb.CreateString(message) : 0,
      code,
      signature);
}

}  // namespace iroha

#endif  // FLATBUFFERS_GENERATED_ENDPOINT_IROHA_H_
