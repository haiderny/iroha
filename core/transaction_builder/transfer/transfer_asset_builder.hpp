/*
Copyright 2016 Soramitsu Co., Ltd.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#ifndef CORE_MODEL_TRANSACTION_BUILDER_TRANSFER_ASSET_HPP
#define CORE_MODEL_TRANSACTION_BUILDER_TRANSFER_ASSET_HPP

#include <infra/protobuf/api.pb.h>
#include <util/exception.hpp>
#include "../transaction_builder_base.hpp"
#include "../type_signatures/commands/transfer.hpp"
#include "../type_signatures/objects.hpp"

namespace txbuilder {

template <>
class TransactionBuilder<type_signatures::Transfer<type_signatures::Asset>> {
 public:
  TransactionBuilder() = default;
  TransactionBuilder(const TransactionBuilder&) = default;
  TransactionBuilder(TransactionBuilder&&) = default;

  TransactionBuilder& setSenderPublicKey(std::string sender) {
    if (_isSetSenderPublicKey) {
      throw exception::txbuilder::DuplicateSetArgmentException(
          "Transfer<Asset>", "senderPublicKey");
    }
    _isSetSenderPublicKey = true;
    _senderPublicKey = std::move(sender);
    return *this;
  }

  TransactionBuilder& setReceiverPublicKey(std::string receiverPublicKey) {
    if (_isSetReceiverPublicKey) {
      throw exception::txbuilder::DuplicateSetArgmentException(
          "Transfer<Asset>", "receiverPublicKey");
    }
    _isSetReceiverPublicKey = true;
    _receiverPublicKey = std::move(receiverPublicKey);
    return *this;
  }

  TransactionBuilder& setAsset(Api::Asset object) {
    if (_isSetAsset) {
      throw exception::txbuilder::DuplicateSetArgmentException(
          "Transfer<Asset>", "Asset");
    }
    _isSetAsset = true;
    _asset = std::move(object);
    return *this;
  }

  Api::Transaction build() {
    const auto unsetMembers = enumerateUnsetMembers();
    if (not unsetMembers.empty()) {
      throw exception::txbuilder::UnsetBuildArgmentsException("Transfer<Asset>",
                                                              unsetMembers);
    }
    Api::Transaction ret;
    ret.set_senderpubkey(_senderPublicKey);
    ret.set_receivepubkey(_receiverPublicKey);
    ret.set_type("Transfer");
    auto ptr = std::make_unique<Api::Asset>();
    ptr->CopyFrom(_asset);
    ret.set_allocated_asset(ptr.release());
    return ret;
  }

 private:
  std::string enumerateUnsetMembers() {
    std::string ret;
    if (not _isSetSenderPublicKey) ret += std::string(" ") + "sender";
    if (not _isSetReceiverPublicKey)
      ret += std::string(" ") + "receiverPublicKey";
    if (not _isSetAsset) ret += std::string(" ") + "Asset";
    return ret;
  }

  std::string _senderPublicKey;
  std::string _receiverPublicKey;
  Api::Asset _asset;

  bool _isSetSenderPublicKey = false;
  bool _isSetReceiverPublicKey = false;
  bool _isSetAsset = false;
};
}

#endif
