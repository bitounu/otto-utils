#pragma once

namespace otto {

class Display;

void drawProgressArc(const Display &display, float progress);

void fillTextCenteredWithSuffix(const std::string &text, const std::string &suffix, float textSize,
                                float suffixSize);

} // otto
