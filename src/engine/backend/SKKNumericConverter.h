/* -*- c++ -*-

  MacOS X implementation of the SKK input method.

  Copyright (C) 2006-2008 Tomotaka SUWA <t.suwa@mac.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#ifndef SKKNumericConverter_h
#define SKKNumericConverter_h

#include <string>
#include <vector>

class SKKCandidate;

// 数値変換用ユーティリティクラス
class SKKNumericConverter {
    std::string original_;
    std::string normalized_;
    std::vector<std::string> params_;

public:
    bool Setup(const std::string& query);

    const std::string& OriginalKey() const;
    const std::string& NormalizedKey() const;

    void Apply(SKKCandidate& candidate) const;
};

#endif
