/***************************************************************************
 *   Copyright (C) 2021 by Federico Amedeo Izzo IU2NUO,                    *
 *                         Niccolò Izzo IU2KIN                             *
 *                         Frederik Saraci IU2NRO                          *    
 *                         Silvano Seva IU2KWO                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   As a special exception, if other files instantiate templates or use   *
 *   macros or inline functions from this file, or you compile this file   *
 *   and link it with other works to produce a work based on this file,    *
 *   this file does not by itself cause the resulting work to be covered   *
 *   by the GNU General Public License. However the source code for this   *
 *   file must still be made available in accordance with the GNU General  *
 *   Public License. This exception does not invalidate any other reasons  *
 *   why a work based on this file might be covered by the GNU General     *
 *   Public License.                                                       *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 ***************************************************************************/

#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#ifndef __cplusplus
#error This header is C++ only!
#endif

#include <array>
#include "ui_view.h"

/**
 * Class that corresponds to a self-contained UI functionality
 * Example: Main menu, Main screen, GPS menu...
 * It is composed by one or more views which contain zero or more Widgets
 */
class UIElement
{
public:
    
    /**
     * Constructor.
     */

    UIElement();
    
    /**
     * Destructor.
     */
    virtual ~UIElement(){}
    
    /**
     * Show the element on screen, resetting its state if needed
     */
    void enable();
    
    /**
     * Remove the element from the screen
     */
    void disable();
    
    /**
     * Render the active view
     */
    void draw();
    
    /**
     * Process an event and pass it to the active View
     *
     * @param event: The event to be passed
     */
    void event(event_t event);

private:
    std::array<View> viewList; ///< Array of the views composing the UIElement
    unsigned int activeView;   ///< Index of the currently active view
};

#endif /* UI_ELEMENT_H */
