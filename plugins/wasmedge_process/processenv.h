// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2024 Second State INC

#pragma once

#include "common/hash.h"
#include "plugin/plugin.h"
#include "po/argument_parser.h"
#include "po/list.h"
#include "po/option.h"

#include <cstdint>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace WasmEdge {
namespace Host {

class WasmEdgeProcessEnvironment {
public:
  WasmEdgeProcessEnvironment() noexcept;

  /// Default timeout in milliseconds.
  static inline const uint32_t DEFAULT_TIMEOUT = 10000;
  /// Default polling time in milliseconds.
  static inline const uint32_t DEFAULT_POLLTIME = 1;

  /// Commands
  std::string Name;
  std::vector<std::string> Args;
  std::unordered_map<std::string, std::string> Envs;

  /// IO
  std::vector<uint8_t> StdIn;
  std::vector<uint8_t> StdOut;
  std::vector<uint8_t> StdErr;

  /// Configurations
  /// Timeout in milliseconds.
  uint32_t TimeOut = DEFAULT_TIMEOUT;
  /// Programs in white list.
  std::unordered_set<std::string> AllowedCmd;
  /// Flag to allow all programs.
  bool AllowedAll;

  /// Results
  uint32_t ExitCode = 0;

  static PO::List<std::string> AllowCmd;
  static PO::Option<PO::Toggle> AllowCmdAll;
};

} // namespace Host
} // namespace WasmEdge
