/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2019 Fritzing

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************

$Revision: 6904 $:
$Author: irascibl@gmail.com $:
$Date: 2013-02-26 16:26:03 +0100 (Di, 26. Feb 2013) $

********************************************************************/

#ifndef CORNERHANDLER_H_
#define CORNERHANDLER_H_

#include <QGraphicsPixmapItem>
#include <QCursor>

class ConnectorRectangle;

class CornerHandler : public QGraphicsRectItem {
public:
	CornerHandler(ConnectorRectangle *parent, QGraphicsItem* parentItem, Qt::Corner corner);
	void resize(const QPointF &mousePos);
	Qt::Corner corner();
	bool isBeingDragged();
	void doSetVisible(bool visible);
	void doSetRect(const QRectF &newRect);
	void doPaint(QPainter *painter);

protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	Qt::CursorShape cursorForCorner(Qt::Corner);

	void initPixmapHash();

	ConnectorRectangle *m_parent;
	Qt::Corner m_corner;

	bool m_isVisible;
	volatile bool m_resizing;

public:
	static QHash<Qt::Corner,QPixmap> pixmapHash;
	static double Size;
};

#endif /* CORNERHANDLER_H_ */
