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

#ifndef UI_MANAGER_H
#define UI_MANAGER_H

#ifndef __cplusplus
#error This header is C++ only!
#endif

#include <array>
#include "ui_element.h"

/**
 * Class that manages the execution and switch of UI elements
 */
class UIManager
{
public:
    /**
     * Constructor.
     */
    UIManager();

    /**
     * Destructor.
     */
    ~UIManager();

    /**
     * Replaces the current active UIElement with another one
     * This methods disables the current UIElement and enables the new one.
     *
     * @param index: index of the new UIElement to activate, replacing the current one
     */
    void switchUIElement(const unsigned int elem);

    /**
     * Returns a reference to the array of available elements
     * To be used by MenuElement to get list of callable applications
     */
    const std::array<UIElement>& getUIElements();

    /**
     * Renders the active view of the active element
     */
    void draw();
    
    /**
     * Passes an event to the active element
     *
     * @param event: The event to be passed
     */
    void event(event_t event);
    
private:
    
    /**
     * Used to create a preset list of UIElements, containing the functionality
     * built-in OpenRTX
     */
    void createUIElementList();

    std::array<UIElement> elements;    ///< Array of the available UIElements
    unsigned int active;             ///< Index of the active UIElement
    unsigned int last;               ///< Index of the previous active UIElement
};

#endif /* UI_MANAGER_H */
