// Copyright 2010-2021, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <string>

#include "base/init_mozc.h"
#include "base/logging.h"
#include "base/process.h"
#include "absl/flags/flag.h"

ABSL_FLAG(std::string, open_browser, "", "URL");
ABSL_FLAG(std::string, spawn_process, "", "path");

int main(int argc, char **argv) {
  mozc::InitMozc(argv[0], &argc, &argv);
  if (!absl::GetFlag(FLAGS_open_browser).empty()) {
    if (!mozc::Process::OpenBrowser(absl::GetFlag(FLAGS_open_browser))) {
      LOG(INFO) << "Failed to open: " << absl::GetFlag(FLAGS_open_browser);
    }
  }
  if (!absl::GetFlag(FLAGS_spawn_process).empty()) {
    if (!mozc::Process::SpawnProcess(absl::GetFlag(FLAGS_spawn_process), "")) {
      LOG(INFO) << "Failed to spawn: " << absl::GetFlag(FLAGS_spawn_process);
    }
  }
  return 0;
}
