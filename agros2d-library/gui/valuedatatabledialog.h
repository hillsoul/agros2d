// This file is part of Agros2D.
//
// Agros2D is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Agros2D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Agros2D.  If not, see <http://www.gnu.org/licenses/>.
//
// hp-FEM group (http://hpfem.org/)
// University of Nevada, Reno (UNR) and University of West Bohemia, Pilsen
// Email: agros2d@googlegroups.com, home page: http://hpfem.org/agros2d/

#ifndef DATATABLEDIALOG_H
#define DATATABLEDIALOG_H

#include "util.h"
#include "datatable.h"

class QwtPlotCurve;
class Chart;

class ValueDataTableDialog: public QDialog
{
    Q_OBJECT

public:
    ValueDataTableDialog(QWidget *parent = 0, const QString &labelX = "x", const QString &labelY = "y");
    ~ValueDataTableDialog();

    DataTable table();
    void setCubicSpline(DataTable table);

private:
    // captions
    QString m_labelX;
    QString m_labelY;

    // charts
    DataTable m_table;
    Chart *chartValue;
    QwtPlotCurve *chartValueCurveMarkers;
    Chart *chartDerivative;

    // values
    QPlainTextEdit *lstX;
    QPlainTextEdit *lstY;

    // info
    QLabel *lblLabelX;
    QLabel *lblLabelY;
    QLabel *lblInfoX;
    QLabel *lblInfoY;
    QLabel *lblInfoError;

    QCheckBox *chkDerivative;
    QCheckBox *chkMarkers;

    QPushButton *btnOk;
    QPushButton *btnClose;
    QPushButton *btnPlot;

    void createControls();
    void load();
    bool save();

    bool parseTable(bool addToTable = true);

    void highlightCurrentLine(QPlainTextEdit *lst);
    void gotoLine(QPlainTextEdit *lst, int lineNumber);

private slots:
    void doAccept();
    void doReject();

    void textChanged();
    void highlightCurrentLineX();
    void highlightCurrentLineY();
    void doPlot();
    void doShowDerivativeClicked();
    void doMaterialBrowser();
};

#endif // DATATABLEDIALOG_H
