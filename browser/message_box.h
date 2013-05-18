// Copyright (c) 2013 GitHub, Inc. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BROWSER_MESSAGE_BOX_H_
#define BROWSER_MESSAGE_BOX_H_

#include <string>
#include <vector>

namespace atom {

enum MessageBoxType {
  MESSAGE_BOX_TYPE_NONE = 0,
  MESSAGE_BOX_TYPE_INFORMATION,
  MESSAGE_BOX_TYPE_WARNING
};

int ShowMessageBox(MessageBoxType type,
                   const std::vector<std::string>& buttons,
                   const std::string& title,
                   const std::string& message,
                   const std::string& detail);

}  // namespace atom

#endif  // BROWSER_MESSAGE_BOX_H_