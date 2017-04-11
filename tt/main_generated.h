// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MAIN_IROHA_H_
#define FLATBUFFERS_GENERATED_MAIN_IROHA_H_

#include "flatbuffers/flatbuffers.h"

#include "account_generated.h"
#include "asset_generated.h"
#include "commands_generated.h"
#include "primitives_generated.h"
#include "transaction_generated.h"

namespace iroha {

struct ConsensusEvent;

struct TransactionResponse;

struct ReceiverConfirmation;

enum Code {
  Code_COMMIT = 0,
  Code_FAIL = 1,
  Code_MIN = Code_COMMIT,
  Code_MAX = Code_FAIL
};

inline const char **EnumNamesCode() {
  static const char *names[] = {
    "COMMIT",
    "FAIL",
    nullptr
  };
  return names;
}

inline const char *EnumNameCode(Code e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesCode()[index];
}

struct ConsensusEvent FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PEERSIGNATURES = 4,
    VT_TRANSACTIONS = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<iroha::Signature>> *peerSignatures() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<iroha::Signature>> *>(VT_PEERSIGNATURES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<iroha::Transaction>> *transactions() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<iroha::Transaction>> *>(VT_TRANSACTIONS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PEERSIGNATURES) &&
           verifier.Verify(peerSignatures()) &&
           verifier.VerifyVectorOfTables(peerSignatures()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TRANSACTIONS) &&
           verifier.Verify(transactions()) &&
           verifier.VerifyVectorOfTables(transactions()) &&
           verifier.EndTable();
  }
};

struct ConsensusEventBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_peerSignatures(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<iroha::Signature>>> peerSignatures) {
    fbb_.AddOffset(ConsensusEvent::VT_PEERSIGNATURES, peerSignatures);
  }
  void add_transactions(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<iroha::Transaction>>> transactions) {
    fbb_.AddOffset(ConsensusEvent::VT_TRANSACTIONS, transactions);
  }
  ConsensusEventBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ConsensusEventBuilder &operator=(const ConsensusEventBuilder &);
  flatbuffers::Offset<ConsensusEvent> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<ConsensusEvent>(end);
    return o;
  }
};

inline flatbuffers::Offset<ConsensusEvent> CreateConsensusEvent(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<iroha::Signature>>> peerSignatures = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<iroha::Transaction>>> transactions = 0) {
  ConsensusEventBuilder builder_(_fbb);
  builder_.add_transactions(transactions);
  builder_.add_peerSignatures(peerSignatures);
  return builder_.Finish();
}

inline flatbuffers::Offset<ConsensusEvent> CreateConsensusEventDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<iroha::Signature>> *peerSignatures = nullptr,
    const std::vector<flatbuffers::Offset<iroha::Transaction>> *transactions = nullptr) {
  return iroha::CreateConsensusEvent(
      _fbb,
      peerSignatures ? _fbb.CreateVector<flatbuffers::Offset<iroha::Signature>>(*peerSignatures) : 0,
      transactions ? _fbb.CreateVector<flatbuffers::Offset<iroha::Transaction>>(*transactions) : 0);
}

struct TransactionResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MESSAGE = 4,
    VT_CODE = 6,
    VT_TRANSACTION = 8
  };
  const flatbuffers::String *message() const {
    return GetPointer<const flatbuffers::String *>(VT_MESSAGE);
  }
  Code code() const {
    return static_cast<Code>(GetField<uint8_t>(VT_CODE, 0));
  }
  const iroha::Transaction *transaction() const {
    return GetPointer<const iroha::Transaction *>(VT_TRANSACTION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           verifier.Verify(message()) &&
           VerifyField<uint8_t>(verifier, VT_CODE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_TRANSACTION) &&
           verifier.VerifyTable(transaction()) &&
           verifier.EndTable();
  }
};

struct TransactionResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message(flatbuffers::Offset<flatbuffers::String> message) {
    fbb_.AddOffset(TransactionResponse::VT_MESSAGE, message);
  }
  void add_code(Code code) {
    fbb_.AddElement<uint8_t>(TransactionResponse::VT_CODE, static_cast<uint8_t>(code), 0);
  }
  void add_transaction(flatbuffers::Offset<iroha::Transaction> transaction) {
    fbb_.AddOffset(TransactionResponse::VT_TRANSACTION, transaction);
  }
  TransactionResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TransactionResponseBuilder &operator=(const TransactionResponseBuilder &);
  flatbuffers::Offset<TransactionResponse> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<TransactionResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<TransactionResponse> CreateTransactionResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> message = 0,
    Code code = Code_COMMIT,
    flatbuffers::Offset<iroha::Transaction> transaction = 0) {
  TransactionResponseBuilder builder_(_fbb);
  builder_.add_transaction(transaction);
  builder_.add_message(message);
  builder_.add_code(code);
  return builder_.Finish();
}

inline flatbuffers::Offset<TransactionResponse> CreateTransactionResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *message = nullptr,
    Code code = Code_COMMIT,
    flatbuffers::Offset<iroha::Transaction> transaction = 0) {
  return iroha::CreateTransactionResponse(
      _fbb,
      message ? _fbb.CreateString(message) : 0,
      code,
      transaction);
}

struct ReceiverConfirmation FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SIGNATURE = 4,
    VT_HASH = 6
  };
  const iroha::Signature *signature() const {
    return GetPointer<const iroha::Signature *>(VT_SIGNATURE);
  }
  const flatbuffers::Vector<uint8_t> *hash() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_HASH);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SIGNATURE) &&
           verifier.VerifyTable(signature()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_HASH) &&
           verifier.Verify(hash()) &&
           verifier.EndTable();
  }
};

struct ReceiverConfirmationBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_signature(flatbuffers::Offset<iroha::Signature> signature) {
    fbb_.AddOffset(ReceiverConfirmation::VT_SIGNATURE, signature);
  }
  void add_hash(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> hash) {
    fbb_.AddOffset(ReceiverConfirmation::VT_HASH, hash);
  }
  ReceiverConfirmationBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ReceiverConfirmationBuilder &operator=(const ReceiverConfirmationBuilder &);
  flatbuffers::Offset<ReceiverConfirmation> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<ReceiverConfirmation>(end);
    return o;
  }
};

inline flatbuffers::Offset<ReceiverConfirmation> CreateReceiverConfirmation(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<iroha::Signature> signature = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> hash = 0) {
  ReceiverConfirmationBuilder builder_(_fbb);
  builder_.add_hash(hash);
  builder_.add_signature(signature);
  return builder_.Finish();
}

inline flatbuffers::Offset<ReceiverConfirmation> CreateReceiverConfirmationDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<iroha::Signature> signature = 0,
    const std::vector<uint8_t> *hash = nullptr) {
  return iroha::CreateReceiverConfirmation(
      _fbb,
      signature,
      hash ? _fbb.CreateVector<uint8_t>(*hash) : 0);
}

inline const iroha::ConsensusEvent *GetConsensusEvent(const void *buf) {
  return flatbuffers::GetRoot<iroha::ConsensusEvent>(buf);
}

inline const char *ConsensusEventIdentifier() {
  return "IROH";
}

inline bool ConsensusEventBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, ConsensusEventIdentifier());
}

inline bool VerifyConsensusEventBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<iroha::ConsensusEvent>(ConsensusEventIdentifier());
}

inline const char *ConsensusEventExtension() {
  return "iroha";
}

inline void FinishConsensusEventBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<iroha::ConsensusEvent> root) {
  fbb.Finish(root, ConsensusEventIdentifier());
}

}  // namespace iroha

#endif  // FLATBUFFERS_GENERATED_MAIN_IROHA_H_
