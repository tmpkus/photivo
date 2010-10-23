////////////////////////////////////////////////////////////////////////////////
//
// photivo
//
// Copyright (C) 2008 Jos De Laender
//
// This file is part of photivo.
//
// photivo is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 3
// as published by the Free Software Foundation.
//
// photivo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with photivo.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef DLCHOICE_H
#define DLCHOICE_H

#include <QtGui>
#include "ptGuiOptions.h"

////////////////////////////////////////////////////////////////////////////////
//
// ptChoice is a object showing a choice element with associated widgets
//
////////////////////////////////////////////////////////////////////////////////

class ptChoice : public QObject {

Q_OBJECT

public :

ptChoice(const QWidget*          MainWindow,
         const QString           ObjectName,
         const QString           ParentName,
         const short             HasDefaultValue,
         const QVariant          Default,
         const ptGuiOptionsItem* InitialOptions,
         const QString           ToolTip,
   const int     TimeOut);
// Destructor.
~ptChoice();

// Matches Value with a value in combobox.
void SetValue(const QVariant Value, const short BlockSignal = 1);
void AddOrReplaceItem(const QString Text,const QVariant Data);
int  Count(void) { return m_ComboBox->count(); };
void SetEnabled(const short Enabled);
void Clear(void);
void Show(const short Show);
QVariant GetItemData(const int Index) { return m_ComboBox->itemData(Index); };
QString  CurrentText(void) { return m_ComboBox->currentText(); };

private slots:
void OnValueChanged(int Value);
void OnButtonClicked();
void OnValueChangedTimerExpired();

signals :
void valueChanged(QVariant Value);

protected:
bool eventFilter(QObject *obj, QEvent *event);

private:
QVariant m_Value;
QVariant m_DefaultValue;
short    m_HaveDefault;
int      m_TimeOut;

QComboBox*   m_ComboBox;
QToolButton* m_Button;
QTimer*      m_Timer;
};

#endif

////////////////////////////////////////////////////////////////////////////////
