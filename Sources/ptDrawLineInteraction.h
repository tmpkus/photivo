/*******************************************************************************
**
** Photivo
**
** Copyright (C) 2009-2011 Michael Munzert <mail@mm-log.com>
** Copyright (C) 2011 Bernd Schoeler <brjohn@brother-john.net>
**
** This file is part of Photivo.
**
** Photivo is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License version 3
** as published by the Free Software Foundation.
**
** Photivo is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Photivo.  If not, see <http://www.gnu.org/licenses/>.
**
*******************************************************************************/

#ifndef PTDRAWLINEINTERACTION_H
#define PTDRAWLINEINTERACTION_H

#include <QMouseEvent>
#include <QLine>
#include <QGraphicsLineItem>

#include "ptImageInteraction.h"


///////////////////////////////////////////////////////////////////////////
//
// class ptDrawLineInteraction
//
///////////////////////////////////////////////////////////////////////////
class ptDrawLineInteraction : public ptImageInteraction {
Q_OBJECT


///////////////////////////////////////////////////////////////////////////
//
// PUBLIC members
//
///////////////////////////////////////////////////////////////////////////
public:
  explicit ptDrawLineInteraction(QGraphicsView* View, QGraphicsScene* Scene);
  ~ptDrawLineInteraction();

  double angle();


///////////////////////////////////////////////////////////////////////////
//
// PRIVATE members
//
///////////////////////////////////////////////////////////////////////////
private:
  QLineF* m_Line;
  short m_NowDragging;
  QGraphicsLineItem* m_LineItem;


///////////////////////////////////////////////////////////////////////////
//
// PRIVATE slots
//
///////////////////////////////////////////////////////////////////////////
private slots:
  void mouseAction(QMouseEvent* event);

};

#endif // PTDRAWLINEINTERACTION_H
