// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_BASE_IME_TEXT_INPUT_FLAGS_H_
#define UI_BASE_IME_TEXT_INPUT_FLAGS_H_

namespace ui {

// Intentionally keep in sync with blink::WebTextInputFlags defined in:
// third_party/WebKit/public/web/WebTextInputType.h
enum TextInputFlags {
  TEXT_INPUT_FLAG_NONE = 0,
  TEXT_INPUT_FLAG_AUTOCOMPLETE_ON = 1 << 0,
  TEXT_INPUT_FLAG_AUTOCOMPLETE_OFF = 1 << 1,
  TEXT_INPUT_FLAG_AUTOCORRECT_ON = 1 << 2,
  TEXT_INPUT_FLAG_AUTOCORRECT_OFF = 1 << 3,
  TEXT_INPUT_FLAG_SPELLCHECK_ON = 1 << 4,
  TEXT_INPUT_FLAG_SPELLCHECK_OFF = 1 << 5
};

}  // namespace ui

#endif  // UI_BASE_IME_TEXT_INPUT_FLAGS_H_
