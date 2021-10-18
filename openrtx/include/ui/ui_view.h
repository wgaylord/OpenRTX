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

#ifndef UI_VIEW_H
#define UI_VIEW_H

#ifndef __cplusplus
#error This header is C++ only!
#endif

#include <array>
#include "ui_widget.h"

/**
 * Class that consists in a group of widgets shown at the same time on the screen
 * Tipically used to create a single page of a UIElement
 * It contains zero or more Widgets
 */
class View
{
public:
    
    /**
     * Constructor.
     */
    View(std::string title, 
         point_t origin = {0, 0}, 
         point_t size = {SCREEN_WIDTH, SCREEN_HEIGHT}) : title(title), 
                                                         origin(origin), 
                                                         size(size);
    
    /**
     * Destructor.
     */
    virtual ~View(){}
    
    /**
     * Add a widget to the View
     */
    void addWidget(Widget widget);
    
    /**
     * Renders this view and the widgets it contains
     */
    void draw();
    
    /**
     * Passes an event to the widgets it contains
     *
     * @param event: The event to be passed
     */
    void event(event_t event);

private:
    std::string title;              ///< Title of the View
    point_t origin, size;           ///< Origin and size of the view
    std::array<Widget> widgetList;  ///< Array of the widgets contained
};

#endif /* UI_VIEW_H */
