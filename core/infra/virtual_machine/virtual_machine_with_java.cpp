/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.
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

#include <map>
#include <util/logger.hpp>
#include <virtual_machine/virtual_machine.hpp>

#include "jvm/java_virtual_machine.hpp"

namespace virtual_machine {

static [[deprecated]] std::map<std::string, std::unique_ptr<jvm::JavaContext>> vmSet;

namespace detail {
[[deprecated]]
inline std::string pack(const std::string &packageName,
                        const std::string &contractName) {
  return packageName + "." + contractName;
}
}

using detail::pack;

[[deprecated]]
void initializeVM(const std::string &packageName,
                  const std::string &contractName) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    // http://bugs.java.com/bugdatabase/view_bug.do?bug_id=4479303
    // fork() or exec() needed? ref:
    // http://stackoverflow.com/questions/2259947/creating-a-jvm-from-within-a-jni-method
    logger::fatal("virtual machine with java")
        << "Currently, not supported for initializing VM twice.";
    exit(EXIT_FAILURE);
    //            vmSet.at(NameId)->jvm->DestroyJavaVM();
    //            vmSet.erase(NameId);
  }
  vmSet.emplace(NameId, jvm::initializeVM(packageName, contractName));
}

[[deprecated]]
void finishVM(const std::string &packageName, const std::string &contractName) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    vmSet.at(NameId)->jvm->DestroyJavaVM();
    //            vmSet.erase(NameId);
  }
}

[[deprecated]]
void invokeFunction(const std::string &packageName,
                    const std::string &contractName,
                    const std::string &functionName) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    const auto &context = vmSet.at(NameId);
    jvm::execFunction(context, functionName);
  }
}

[[deprecated]]
void invokeFunction(const std::string &packageName,
                    const std::string &contractName,
                    const std::string &functionName,
                    const std::map<std::string, std::string> &params) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    const auto &context = vmSet.at(NameId);
    jvm::execFunction(context, functionName, params);
  }
}

[[deprecated]]
void invokeFunction(
    const std::string &packageName, const std::string &contractName,
    const std::string &functionName,
    const std::map<std::string, std::string> &params1,
    const std::map<std::string, std::map<std::string, std::string>> &params2) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    const auto &context = vmSet.at(NameId);
    jvm::execFunction(context, functionName, params1, params2);
  }
}

[[deprecated]]
void invokeFunction(const std::string &packageName,
                    const std::string &contractName,
                    const std::string &functionName,
                    const std::map<std::string, std::string> &params1,
                    const std::map<std::string, std::string> &params2) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    const auto &context = vmSet.at(NameId);
    jvm::execFunction(context, functionName, params1, params2);
  }
}

[[deprecated]]
void invokeFunction(const std::string &packageName,
                    const std::string &contractName,
                    const std::string &functionName,
                    const std::map<std::string, std::string> &params1,
                    const std::vector<std::string> &params2) {
  const auto NameId = pack(packageName, contractName);
  if (vmSet.find(NameId) != vmSet.end()) {
    const auto &context = vmSet.at(NameId);
    jvm::execFunction(context, functionName, params1, params2);
  }
}
}