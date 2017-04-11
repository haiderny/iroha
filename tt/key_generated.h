// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_KEY_IROHA_H_
#define FLATBUFFERS_GENERATED_KEY_IROHA_H_

#include "flatbuffers/flatbuffers.h"

namespace iroha {

struct PublicKey;

enum KeyAlgorithm {
  KeyAlgorithm_ed25519 = 0,
  KeyAlgorithm_MIN = KeyAlgorithm_ed25519,
  KeyAlgorithm_MAX = KeyAlgorithm_ed25519
};

inline const char **EnumNamesKeyAlgorithm() {
  static const char *names[] = {
    "ed25519",
    nullptr
  };
  return names;
}

inline const char *EnumNameKeyAlgorithm(KeyAlgorithm e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesKeyAlgorithm()[index];
}

struct PublicKey FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ALGORITHM = 4,
    VT_DATA = 6
  };
  KeyAlgorithm algorithm() const {
    return static_cast<KeyAlgorithm>(GetField<int8_t>(VT_ALGORITHM, 0));
  }
  const flatbuffers::Vector<uint8_t> *data() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_DATA);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_ALGORITHM) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_DATA) &&
           verifier.Verify(data()) &&
           verifier.EndTable();
  }
};

struct PublicKeyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_algorithm(KeyAlgorithm algorithm) {
    fbb_.AddElement<int8_t>(PublicKey::VT_ALGORITHM, static_cast<int8_t>(algorithm), 0);
  }
  void add_data(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data) {
    fbb_.AddOffset(PublicKey::VT_DATA, data);
  }
  PublicKeyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PublicKeyBuilder &operator=(const PublicKeyBuilder &);
  flatbuffers::Offset<PublicKey> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<PublicKey>(end);
    fbb_.Required(o, PublicKey::VT_DATA);
    return o;
  }
};

inline flatbuffers::Offset<PublicKey> CreatePublicKey(
    flatbuffers::FlatBufferBuilder &_fbb,
    KeyAlgorithm algorithm = KeyAlgorithm_ed25519,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> data = 0) {
  PublicKeyBuilder builder_(_fbb);
  builder_.add_data(data);
  builder_.add_algorithm(algorithm);
  return builder_.Finish();
}

inline flatbuffers::Offset<PublicKey> CreatePublicKeyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    KeyAlgorithm algorithm = KeyAlgorithm_ed25519,
    const std::vector<uint8_t> *data = nullptr) {
  return iroha::CreatePublicKey(
      _fbb,
      algorithm,
      data ? _fbb.CreateVector<uint8_t>(*data) : 0);
}

}  // namespace iroha

#endif  // FLATBUFFERS_GENERATED_KEY_IROHA_H_
