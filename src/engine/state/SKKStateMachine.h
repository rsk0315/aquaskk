/* -*- C++ -*-

   MacOS X implementation of the SKK input method.

   Copyright (C) 2008 Tomotaka SUWA <t.suwa@mac.com>

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

#ifndef SKKStateMachine_h
#define SKKStateMachine_h

#include "SKKState.h"

#ifndef SKK_DEBUG
typedef GenericStateMachine<SKKState> SKKStateMachine;
#else

#include <iostream>

template <typename Handler, typename Event> struct DebugInspector {
    std::string buf_;

public:
    void operator()(const Handler handler, const Event& event) {
        if (event == 0)
            return;

        SKKState::ToString(handler, event, buf_);

        std::cout << buf_ << std::endl;
    }
};

typedef GenericStateMachine<SKKState, DebugInspector> SKKStateMachine;
#endif

#endif
