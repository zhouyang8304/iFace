// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_CRX_FILE_ID_UTIL_H_
#define COMPONENTS_CRX_FILE_ID_UTIL_H_

#include <string>

namespace base {
class FilePath;
}

namespace crx_file {
namespace id_util {

// The number of bytes in a legal id.
extern const size_t kIdSize;

// Generates an extension ID from arbitrary input. The same input string will
// always generate the same output ID.
std::string GenerateId(const std::string& input);

// Generate an ID for an extension in the given path.
// Used while developing extensions, before they have a key.
std::string GenerateIdForPath(const base::FilePath& path);

// Normalize the path for use by the extension. On Windows, this will make
// sure the drive letter is uppercase.
base::FilePath MaybeNormalizePath(const base::FilePath& path);

// Checks if |id| is a valid extension-id. Extension-ids are used for anything
// that comes in a CRX file, including apps, extensions, and components.
bool IdIsValid(const std::string& id);

}  // namespace id_util
}  // namespace crx_file

#endif  // COMPONENTS_CRX_FILE_ID_UTIL_H_
