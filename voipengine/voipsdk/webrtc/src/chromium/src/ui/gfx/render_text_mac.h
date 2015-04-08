// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_RENDER_TEXT_MAC_H_
#define UI_GFX_RENDER_TEXT_MAC_H_

#include <ApplicationServices/ApplicationServices.h>

#include <string>
#include <vector>

#include "base/mac/scoped_cftyperef.h"
#include "ui/gfx/render_text.h"

namespace gfx {

// RenderTextMac is the Mac implementation of RenderText that uses CoreText for
// layout and Skia for drawing.
//
// Note: The current implementation only supports drawing and sizing the text,
//       but not text selection or cursor movement.
class RenderTextMac : public RenderText {
 public:
  RenderTextMac();
  ~RenderTextMac() override;

  // Overridden from RenderText:
  Size GetStringSize() override;
  SizeF GetStringSizeF() override;
  SelectionModel FindCursorPosition(const Point& point) override;
  std::vector<FontSpan> GetFontSpansForTesting() override;

 protected:
  // Overridden from RenderText:
  int GetLayoutTextBaseline() override;
  SelectionModel AdjacentCharSelectionModel(
      const SelectionModel& selection,
      VisualCursorDirection direction) override;
  SelectionModel AdjacentWordSelectionModel(
      const SelectionModel& selection,
      VisualCursorDirection direction) override;
  Range GetGlyphBounds(size_t index) override;
  std::vector<Rect> GetSubstringBounds(const Range& range) override;
  size_t TextIndexToLayoutIndex(size_t index) const override;
  size_t LayoutIndexToTextIndex(size_t index) const override;
  bool IsValidCursorIndex(size_t index) override;
  void ResetLayout() override;
  void EnsureLayout() override;
  void DrawVisualText(Canvas* canvas) override;

 private:
  struct TextRun {
    CTRunRef ct_run;
    SkPoint origin;
    std::vector<uint16> glyphs;
    std::vector<SkPoint> glyph_positions;
    SkScalar width;
    std::string font_name;
    int font_style;
    SkScalar text_size;
    SkColor foreground;
    bool underline;
    bool strike;
    bool diagonal_strike;

    TextRun();
    ~TextRun();
  };

  // Applies RenderText styles to |attr_string| with the given |ct_font|.
  void ApplyStyles(CFMutableAttributedStringRef attr_string, CTFontRef ct_font);

  // Updates |runs_| based on |line_| and sets |runs_valid_| to true.
  void ComputeRuns();

  // The Core Text line of text. Created by |EnsureLayout()|.
  base::ScopedCFTypeRef<CTLineRef> line_;

  // Array to hold CFAttributedString attributes that allows Core Text to hold
  // weak references to them without leaking.
  base::ScopedCFTypeRef<CFMutableArrayRef> attributes_;

  // Visual dimensions of the text. Computed by |EnsureLayout()|.
  SizeF string_size_;

  // Common baseline for this line of text. Computed by |EnsureLayout()|.
  SkScalar common_baseline_;

  // Visual text runs. Only valid if |runs_valid_| is true. Computed by
  // |ComputeRuns()|.
  std::vector<TextRun> runs_;

  // Indicates that |runs_| are valid, set by |ComputeRuns()|.
  bool runs_valid_;

  DISALLOW_COPY_AND_ASSIGN(RenderTextMac);
};

}  // namespace gfx

#endif  // UI_GFX_RENDER_TEXT_MAC_H_
