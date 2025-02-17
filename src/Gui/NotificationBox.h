/***************************************************************************
 *   Copyright (c) 2023 Abdullah Tahiri <abdullah.tahiri.yo@gmail.com >    *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#ifndef GUI_NOTIFICATIONBOX_H
#define GUI_NOTIFICATIONBOX_H


namespace Gui
{

/** This class provides a non-intrusive tip alike notification
 * dialog, which unlike QToolTip, is kept shown during a time.
 *
 * The notification is shown during minShowTime, unless pop out
 * (i.e. clicked inside the notification).
 *
 * The notification will show up to a maximum of displayTime. The
 * only event that closes the notification between minShowTime and
 * displayTime is a mouse button click (anywhere of the screen).
 *
 * When displayTime is not provided, it is calculated based on the length
 * of the text.
 *
 * This class interface and its implementation are based on QT's
 * QToolTip.
 */
class NotificationBox
{
    NotificationBox() = delete;

public:
    /** Shows a non-intrusive notification.
     * @param pos Position at which the notification will be shown
     * @param displayTime Time after which the notification will auto-close (unless it is closed by
     * an event, see class documentation above)
     * @param minShowTime  Time during which the notification can only be made disappear by popping
     * it out (clicking inside it).
     * @param width Fixes the width of the notification. Default value makes the width to be system determined (dependent on
     * the text).
     */
    static void showText(const QPoint& pos, const QString& text, int displayTime = -1,
                         unsigned int minShowTime = 0, int width = 0);
    /// Hides a notification.
    static inline void hideText()
    {
        showText(QPoint(), QString());
    }
    /// Returns whether a notification is being shown or not.
    static bool isVisible();
    /// Returns the text of the notification.
    static QString text();
    /// Returns the palette.
    static QPalette palette();
    /// Sets the palette.
    static void setPalette(const QPalette&);
    /// Returns the font of the notification.
    static QFont font();
    /// Sets the font to be used in the notification.
    static void setFont(const QFont&);
};


}// namespace Gui

#endif// GUI_NOTIFICATIONBOX_H
